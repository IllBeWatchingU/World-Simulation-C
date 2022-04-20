#pragma once
#include "Zwierze.h";

class Antylopa : public Zwierze {
public:
	Antylopa(Swiat * swiat, int polozenieX, int polozenieY);

	bool czyTenSamGatunek(Organizm* organizm) override;
	bool wykonajUnik(Organizm* atakujacy) override;
	string getNazwa() const override;
};
