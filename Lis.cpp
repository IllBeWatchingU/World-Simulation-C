#include "Lis.h";

Lis::Lis(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, 3, 7, polozenieX, polozenieY, 'L', 1) {

}

bool Lis::czyTenSamGatunek(Organizm* organizm) {
	if (organizm->getLitera() == 'L') {
		return true;
	}
	return false;
}

bool Lis::wykonajRuch() {
	int losowePole = swiat->getLosowePoleMniejszegoSila(this);
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

string Lis::getNazwa() const {
	return "Lis";
}