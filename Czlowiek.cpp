#include "Czlowiek.h";

Czlowiek::Czlowiek(Swiat * swiat, int polozenieX, int polozenieY) : 
Zwierze(swiat, 5, 4, polozenieX, polozenieY, 'C', 1, DOMYSLNA_SZANSA_RUCHU, DOMYSLNY_ZASIEG_RUCHU),
cooldownZdolnosci(0), czasZdolnosci(5), czyZdolnoscAktywna(false){

}

bool Czlowiek::aktywujUmiejetnosc() {
	if (czyZdolnoscAktywna == false && cooldownZdolnosci == 0) {
		czyZdolnoscAktywna = true;
		return true;
	}
	return false;
}

void Czlowiek::wykonajUmiejetnosc() {
	if (czyZdolnoscAktywna == false) {
		return;
	}
	if (cooldownZdolnosci == 0) {
		if (czasZdolnosci >= 3) {
			this->setZasiegRuchu(2);
			czasZdolnosci--;
		}
		else if (czasZdolnosci > 0 && czasZdolnosci < 3) {
			int chance = rand() % 100;
			if (chance >= 50) {
				this->setZasiegRuchu(2);
				czasZdolnosci--;
			}
			else {
				this->setZasiegRuchu(DOMYSLNY_ZASIEG_RUCHU);
				czasZdolnosci--;
			}
		}
	}

	if (czasZdolnosci == 0) {
		this->setZasiegRuchu(1);
		this->cooldownZdolnosci = 5;
		this->czasZdolnosci = 5;
		this->czyZdolnoscAktywna = false;
	}
}

bool Czlowiek::czyZdolnoscMoze() {
	if (cooldownZdolnosci != 0) {
		cooldownZdolnosci--;
		return false;
	}
	else {
		return true;
	}
}

int Czlowiek::getCooldown() {
	return this->cooldownZdolnosci;
}

bool Czlowiek::getCzyZdolnoscAktywna() {
	return this->czyZdolnoscAktywna;
}

bool Czlowiek::wykonajRuch() {
	int losowePole = swiat->getRuchCzlowieka();
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
	case 0:
		return false;
		break;
	}

	if (doceloweX < 0 || doceloweY < 0 || doceloweX >= WORLD_WIDTH || doceloweY >= WORLD_HEIGHT) {
		return false;
	}

	if (swiat->czyPoleJestPuste(doceloweX, doceloweY) == false) {
		Organizm* zajmujacy = swiat->getOrganizm(doceloweX, doceloweY);
		if (zajmujacy->Kolizja(this)) {
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

void Czlowiek::Akcja() {
	if (this->czyZdolnoscMoze()) {
		if (this->czyZdolnoscAktywna) {
			this->wykonajUmiejetnosc();
		}
	}
	if (this->czyWykonujeRuch()) {
		for (int i = 0; i < this->getZasiegRuchu(); i++) {
			if (!wykonajRuch()) {
				break;
			}
		}
	}
}

bool Czlowiek::czyTenSamGatunek(Organizm* organizm) {
	return false;
}

string Czlowiek::getNazwa() const {
	return "Czlowiek";
}

Czlowiek::~Czlowiek() {

}