#pragma once
#include "Roslina.h";

class WilczeJagody : public Roslina {
public:
	WilczeJagody(Swiat* swiat, int polozenieX, int polozenieY);

	bool Kolizja(Organizm* atakujacy) override;
	string getNazwa() const override;
	~WilczeJagody();
};