#pragma once
#include "Zwierze.h";
#define ODPIERAJ_SILE 5

class Zolw : public Zwierze {
public:
	Zolw(Swiat* swiat, int polozenieX, int polozenieY);

	bool czyTenSamGatunek(Organizm* organizm) override;
	bool odeprzyjAtak(Organizm* atakujacy) override;
	string getNazwa() const override;
};
