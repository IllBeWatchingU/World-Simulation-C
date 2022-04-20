#pragma once
#include "Roslina.h";

class Mlecz : public Roslina {
public:
	Mlecz(Swiat* swiat, int polozenieX, int polozenieY);
	void Akcja() override;
	string getNazwa() const override;
};
