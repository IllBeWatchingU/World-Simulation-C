#include "Wilk.h";

Wilk::Wilk(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, 9, 5, polozenieX, polozenieY, 'W', 1) {

}

bool Wilk::czyTenSamGatunek(Organizm* organizm) {
	if (organizm->getLitera() == 'W') {
		return true;
	}
	return false;
}

string Wilk::getNazwa() const {
	return "Wilk";
}