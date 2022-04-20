#include "Trawa.h";

Trawa::Trawa(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, 0, polozenieX, polozenieY, 'T') {

}

string Trawa::getNazwa() const {
	return "Trawa";
}