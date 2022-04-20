#include "Antylopa.h";

Antylopa::Antylopa(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, 4, 4, polozenieX, polozenieY, 'A', 1, DOMYSLNA_SZANSA_RUCHU, 2) {

}

bool Antylopa::czyTenSamGatunek(Organizm* organizm) {
	if (organizm->getLitera() == 'A') {
		return true;
	}
	return false;
}

bool Antylopa::wykonajUnik(Organizm* atakujacy){
	int losowaLiczba = rand() % 100;
	if (losowaLiczba < 50) {
		if (swiat->czyWszystkiePolaZajete(this->getX(), this->getY())) {
			return false;
		}
		else {
			int losowePole = swiat->getLosowePustePole(this);
			int doceloweX = getX(), doceloweY = getY();
			switch (losowePole) {
			case 1: //na pó³noc
				doceloweY = getY() - DOMYSLNY_ZASIEG_RUCHU;

			case 2: //na po³udnie
				doceloweY = getY() + DOMYSLNY_ZASIEG_RUCHU;
				break;
			case 3: //na zachód
				doceloweX = getX() - DOMYSLNY_ZASIEG_RUCHU;
				break;
			case 4: //na wschód
				doceloweX = getX() + DOMYSLNY_ZASIEG_RUCHU;
				break;
			}
			swiat->usunOrganizmZPola(this);
			this->setPolozenie(doceloweX, doceloweY);
			swiat->dodajOrganizmDoPola(this, doceloweX, doceloweY);
			return true;
		}
	}
	return false;
}

string Antylopa::getNazwa() const {
	return "Antylopa";
}