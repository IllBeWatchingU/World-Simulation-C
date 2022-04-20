#include "BarszczSosnowskiego.h";

BarszczSosnowskiego::BarszczSosnowskiego(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, 0, polozenieX, polozenieY, 'B') {

}

void BarszczSosnowskiego::Akcja() {
	if (this->polozenieY != 0) {// sprawdza, czy na p�nocy znajduje si� zwierze
		if (!swiat->czyPoleJestPuste(this->polozenieX, this->polozenieY - 1)) {
			Organizm* organizm = swiat->getOrganizm(this->polozenieX, this->polozenieY - 1);
			if (swiat->czyOrganizmJestZwierzeciem(organizm)) {
				swiat->usunOrganizmZPola(organizm);
				organizm->setInicjatywa(-1);

				string komentarz = this->getNazwa() + " zabija " + organizm->getNazwa();
				swiat->dodajKomentarz(komentarz);
			}
		}
	}
	if (this->polozenieY != WORLD_HEIGHT - 1) { //sprawdza, czy na po�udniu znajduje si� zwierze
		if (!swiat->czyPoleJestPuste(this->polozenieX, this->polozenieY + 1)) {
			Organizm* organizm = swiat->getOrganizm(this->polozenieX, this->polozenieY + 1);
			if (swiat->czyOrganizmJestZwierzeciem(organizm)) {
				swiat->usunOrganizmZPola(organizm);
				organizm->setInicjatywa(-1);

				string komentarz = this->getNazwa() + " zabija " + organizm->getNazwa();
				swiat->dodajKomentarz(komentarz);
			}
		}
	}
	if (this->polozenieX != 0) { //sprawdza, czy na zachodzie znajduje si� zwierze
		if (!swiat->czyPoleJestPuste(this->polozenieX - 1, this->polozenieY)) {
			Organizm* organizm = swiat->getOrganizm(this->polozenieX - 1, this->polozenieY);
			if (swiat->czyOrganizmJestZwierzeciem(organizm)) {
				swiat->usunOrganizmZPola(organizm);
				organizm->setInicjatywa(-1);

				string komentarz = this->getNazwa() + " zabija " + organizm->getNazwa();
				swiat->dodajKomentarz(komentarz);
			}
		}
	}
	if (this->polozenieX != WORLD_WIDTH - 1) { //sprawdza, czy na wschodzie znajduje si� zwierze
		if (!swiat->czyPoleJestPuste(this->polozenieX + 1, this->polozenieY)) {
			Organizm* organizm = swiat->getOrganizm(this->polozenieX + 1, this->polozenieY);
			if (swiat->czyOrganizmJestZwierzeciem(organizm)) {
				swiat->usunOrganizmZPola(organizm);
				organizm->setInicjatywa(-1);

				string komentarz = this->getNazwa() + " zabija " + organizm->getNazwa();
				swiat->dodajKomentarz(komentarz);
			}
		}
	}

	if (ProbaRozmnozeniaSie()) {
		string komentarz = this->getNazwa() + " rozmnaza sie";
		swiat->dodajKomentarz(komentarz);
	}
}

bool BarszczSosnowskiego::Kolizja(Organizm* atakujacy) {

	string komentarz = atakujacy->getNazwa() + " probuje zjesc " + this->getNazwa() + " i ginie";
	swiat->dodajKomentarz(komentarz);

	//je�eli nast�puje kolizja, i barszcz i atakuj�cy organizm gin�
	swiat->usunOrganizmZPola(atakujacy);
	atakujacy->setInicjatywa(-1);
	swiat->usunOrganizmZPola(this);
	this->setInicjatywa(-1);
	return false;
}

string BarszczSosnowskiego::getNazwa() const {
	return "Barszcz Sosnowskiego";
}