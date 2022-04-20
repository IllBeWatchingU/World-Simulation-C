#include "Guarana.h";

Guarana::Guarana(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, 0, polozenieX, polozenieY, 'G') {

}

string Guarana::getNazwa() const {
	return "Guarana";
}

bool Guarana::Kolizja(Organizm* atakujacy) {
	string komentarz = atakujacy->getNazwa() + " zjada " + this->getNazwa();
	swiat->dodajKomentarz(komentarz);

	int nowaSila = atakujacy->getSila();
	nowaSila = nowaSila + 3;
	atakujacy->setSila(nowaSila);
	swiat->usunOrganizmZPola(this);
	this->setInicjatywa(-1);
	return true;
}

Guarana::~Guarana() {

}