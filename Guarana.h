#pragma once
#include "Roslina.h";

class Guarana : public Roslina {
public:
	Guarana(Swiat* swiat, int polozenieX, int polozenieY);

	string getNazwa() const override;

	bool Kolizja(Organizm* atakujacy) override;

	~Guarana();
};
