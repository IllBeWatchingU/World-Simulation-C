#pragma once
#include "Roslina.h";

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(Swiat* swiat, int polozenieX, int polozenieY);
	void Akcja() override;
	bool Kolizja(Organizm* atakujacy) override;
	string getNazwa() const override;
};
