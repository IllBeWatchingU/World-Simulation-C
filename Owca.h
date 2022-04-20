#pragma once
#include "Zwierze.h";

class Owca : public Zwierze {
public:
	Owca(Swiat* swiat, int polozenieX, int polozenieY);

	bool czyTenSamGatunek(Organizm* organizm) override;
	string getNazwa() const override;
};
