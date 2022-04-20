#include "Zwierze.h";

Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa,
	int polozenieX, int polozenieY, const char literaOrganizmu, int wiek, int szansaWykonaniaRuchu, int zasiegRuchu)
	: Organizm(swiat, sila, inicjatywa, polozenieX, polozenieY, literaOrganizmu, wiek), szansaWykonaniaRuchu(szansaWykonaniaRuchu), zasiegRuchu(zasiegRuchu){

}

Zwierze::Zwierze(Swiat* swiat, int sila, int inicjatywa,
	int polozenieX, int polozenieY, const char literaOrganizmu, int wiek) :
	Organizm(swiat, sila, inicjatywa, polozenieX, polozenieY, literaOrganizmu, wiek){
	szansaWykonaniaRuchu = DOMYSLNA_SZANSA_RUCHU;
	zasiegRuchu = DOMYSLNY_ZASIEG_RUCHU;
}

void Zwierze::setZasiegRuchu(int zasieg) {
	this->zasiegRuchu = zasieg;
}

int Zwierze::getZasiegRuchu() {
	return this->zasiegRuchu;
}

int Zwierze::getSzansaRuchu() {
	return this->szansaWykonaniaRuchu;
}

bool Zwierze::wykonajRuch() {
	int losowePole = swiat->getLosowePole(this);
	int doceloweX = this->getX(), doceloweY = this->getY();
	switch (losowePole) {
	case 1: //na pó³noc
		doceloweY = this->getY() - DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 2: //na po³udnie
		doceloweY = this->getY() + DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 3: //na zachód
		doceloweX = this->getX() - DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 4: //na wschód
		doceloweX = this->getX() + DOMYSLNY_ZASIEG_RUCHU;
		break;
	default:
		return false;
		break;
	}

	if (doceloweX < 0 || doceloweY < 0 || doceloweX >= WORLD_WIDTH || doceloweY >= WORLD_HEIGHT) {
		return false;
	}

	if (swiat->czyPoleJestPuste(doceloweX, doceloweY) == false) {
		Organizm* zajmujacy = swiat->getOrganizm(doceloweX, doceloweY);
		if (czyTenSamGatunek(zajmujacy)) {
			if (!Rozmnazanie(zajmujacy)) {
				return true;
			}
		}
		else if (zajmujacy->Kolizja(this)) {
			swiat->usunOrganizmZPola(this);
			this->setPolozenie(doceloweX, doceloweY);
			swiat->dodajOrganizmDoPola(this, doceloweX, doceloweY);
		}
		return false;
	}
	else {
		swiat->usunOrganizmZPola(this);
		this->setPolozenie(doceloweX, doceloweY);
		swiat->dodajOrganizmDoPola(this, doceloweX, doceloweY);
		return true;
	}
}

bool Zwierze::czyWykonujeRuch() {
	int losowaLiczba = rand() % 100;
	if (losowaLiczba <= this->szansaWykonaniaRuchu) {
		return true;
	}
	return false;
}

bool Zwierze::Kolizja(Organizm* atakujacy) {
	if (this->getSila() > atakujacy->getSila()) {
		if (!atakujacy->odeprzyjAtak(this)) {
			string komentarz = this->getNazwa() + " odpiera nieudany atak " + atakujacy->getNazwa() + " i zjada ten organizm";
			swiat->dodajKomentarz(komentarz);
			swiat->usunOrganizmZPola(atakujacy);
			atakujacy->setInicjatywa(-1);
		}
		return false;
	}
	else {
		if (this->wykonajUnik(atakujacy)) {
			string komentarz = this->getNazwa() + " unika atak " + atakujacy->getNazwa();
			swiat->dodajKomentarz(komentarz);
			return true;
		}
		else if(this->odeprzyjAtak(atakujacy)){
			string komentarz = this->getNazwa() + " odpiera atak " + atakujacy->getNazwa();
			swiat->dodajKomentarz(komentarz);
			return false;
		}

		string komentarz = atakujacy->getNazwa() + " zjada " + this->getNazwa();
		swiat->dodajKomentarz(komentarz);

		swiat->usunOrganizmZPola(this);
		this->setInicjatywa(-1);
		return true;
	}
}

bool Zwierze::Rozmnazanie(Organizm* partner) {
	if (swiat->czyWszystkiePolaZajete(this->getX(), this->getY()) && swiat->czyWszystkiePolaZajete(partner->getX(), partner->getY())) {
		//jesli wszystkie s¹siednie pola s¹ zajête, to nie mo¿e siê rozmno¿yæ
		return false;
	}

	int losowePole = swiat->getLosowePustePoleDlaObuOrganizmow(this, partner);
	int doceloweX, doceloweY;
	switch (losowePole) {
	case 1: //na pó³noc
		doceloweX = this->getX();
		doceloweY = this->getY() - DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 2: //na po³udnie
		doceloweX = this->getX();
		doceloweY = this->getY() + DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 3: //na zachód
		doceloweX = this->getX() - DOMYSLNY_ZASIEG_RUCHU;
		doceloweY = this->getY();
		break;
	case 4: //na wschód
		doceloweX = this->getX() + DOMYSLNY_ZASIEG_RUCHU;
		doceloweY = this->getY();
		break;
	case 5: //na pó³noc partnera
		doceloweX = partner->getX();
		doceloweY = partner->getY() - DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 6: //na po³udnie partnera
		doceloweX = partner->getX();
		doceloweY = partner->getY() + DOMYSLNY_ZASIEG_RUCHU;
		break;
	case 7: //na zachód partnera
		doceloweX = partner->getX() - DOMYSLNY_ZASIEG_RUCHU;
		doceloweY = partner->getY();
		break;
	case 8: //na wschód partnera
		doceloweX = partner->getX() + DOMYSLNY_ZASIEG_RUCHU;
		doceloweY = partner->getY();
		break;
	default:
		return false;
		break;
	}

	swiat->dodajOrganizm(doceloweX, doceloweY, this->getLitera());
	
	string komentarz = this->getNazwa() + " rozmnaza sie";
	swiat->dodajKomentarz(komentarz);

	return true;

}

bool Zwierze::wykonajUnik(Organizm* atakujacy) {
	return false;
}

void Zwierze::Akcja() {
	if (this->czyWykonujeRuch()) {
		for (int i = 0; i < this->zasiegRuchu; i++) {
			if (!wykonajRuch()) {
				break;
			}
		}
	}
}

Zwierze::~Zwierze(){

}