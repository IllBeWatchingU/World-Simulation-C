#include "Zolw.h";

Zolw::Zolw(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, 2, 1, polozenieX, polozenieY, 'Z', 1, 25, DOMYSLNY_ZASIEG_RUCHU) {

}

bool Zolw::czyTenSamGatunek(Organizm* organizm) {
	if (organizm->getLitera() == 'Z') {
		return true;
	}
	return false;
}

bool Zolw::odeprzyjAtak(Organizm* atakujacy) {
	if (atakujacy->getSila() < ODPIERAJ_SILE) {
		return true;
	}
	return false;
}

string Zolw::getNazwa() const {
	return "Zolw";
}