#include "WilczeJagody.h";

WilczeJagody::WilczeJagody(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, 99, polozenieX, polozenieY, 'J') {

}

string WilczeJagody::getNazwa() const {
	return "Wilcze Jagody";
}

bool WilczeJagody::Kolizja(Organizm* atakujacy) {

	string komentarz = atakujacy->getNazwa() + " probuje zjesc " + this->getNazwa() + " i ginie";
	swiat->dodajKomentarz(komentarz);

	swiat->usunOrganizmZPola(atakujacy);
	atakujacy->setInicjatywa(-1);
	swiat->usunOrganizmZPola(this);
	this->setInicjatywa(-1);
	return false;
}

WilczeJagody::~WilczeJagody() {

}