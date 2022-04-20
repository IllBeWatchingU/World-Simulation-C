#include "Owca.h";

Owca::Owca(Swiat* swiat, int polozenieX, int polozenieY) : Zwierze(swiat, 4, 4, polozenieX, polozenieY, 'O', 1) {

}

bool Owca::czyTenSamGatunek(Organizm* organizm) {
	if (organizm->getLitera() == 'O') {
		return true;
	}
	return false;
}

string Owca::getNazwa() const {
	return "Owca";
}