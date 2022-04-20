#pragma once
#include "Zwierze.h";

class Lis : public Zwierze {
public:
	Lis(Swiat* swiat, int polozenieX, int polozenieY);

	bool czyTenSamGatunek(Organizm* organizm) override;
	bool wykonajRuch() override;
	string getNazwa() const override;
};
