#include "Roslina.h";

Roslina::Roslina(Swiat * swiat, int sila,
	int polozenieX, int polozenieY, char literaOrganizmu) : Organizm(swiat, sila, 0, polozenieX, polozenieY, literaOrganizmu, 1){

}

bool Roslina::ProbaRozmnozeniaSie() {
	int los = rand() % 100;

	if (los > 10) {
		return false;
	}

	if (swiat->czyWszystkiePolaZajete(this->getX(), this->getY())) {
		//jesli wszystkie s�siednie pola s� zaj�te, to nie mo�e si� rozmno�y�
		return false;
	}

	int losowePole = swiat->getLosowePustePole(this);
	int doceloweX = getX(), doceloweY = getY();
	switch (losowePole) {
	case 1: //na p�noc
		doceloweY = this->getY() - 1;
		break;
	case 2: //na po�udnie
		doceloweY = this->getY() + 1;
		break;
	case 3: //na zach�d
		doceloweX = this->getX() - 1;
		break;
	case 4: //na wsch�d
		doceloweX = this->getX() + 1;
		break;
	default:
		return false;
	}

	swiat->dodajOrganizm(doceloweX, doceloweY, this->getLitera());

	return true;
	
}

void Roslina::Akcja() {
	if (ProbaRozmnozeniaSie()) {
		string komentarz = this->getNazwa() + " rozmnaza sie ";
		swiat->dodajKomentarz(komentarz);
	}
}

bool Roslina::Kolizja(Organizm* atakujacy) {
	string komentarz = atakujacy->getNazwa() + " zjada " + this->getNazwa();
	swiat->dodajKomentarz(komentarz);
	swiat->usunOrganizmZPola(this);
	this->setInicjatywa(-1);
	return true;
}

Roslina :: ~Roslina() {

}