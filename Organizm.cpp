#include "Organizm.h";

Organizm :: Organizm(Swiat * swiat, int sila, int inicjatywa, int polozenieX,
	int polozenieY, const char literaOrganizmu, int wiek) :
	swiat(swiat), sila(sila), inicjatywa(inicjatywa), polozenieX(polozenieX), polozenieY(polozenieY), 
	literaOrganizmu(literaOrganizmu), wiek(1) {
}

void Organizm :: setPolozenie(const int& x, const int& y) {
	this->polozenieX = x;
	this->polozenieY = y;
}

void Organizm::setInicjatywa(const int& inicjatywa) {
	this->inicjatywa = inicjatywa;
}

void Organizm::setSila(const int& sila) {
	this->sila = sila;
}

void Organizm::setWiek(const int& wiek) {
	this->wiek = wiek;
}

int Organizm :: getSila() const {
	return sila;
}

int Organizm::getInicjatywa() const {
	return inicjatywa;
}

int Organizm::getWiek() const {
	return wiek;
}

char Organizm::getLitera() const {
	return literaOrganizmu;
}

int Organizm::getX() {
	return polozenieX;
}

int Organizm::getY() {
	return polozenieY;
}

bool Organizm::odeprzyjAtak(Organizm* atakujacy) {
	return false;
}

Organizm::~Organizm() {

}

