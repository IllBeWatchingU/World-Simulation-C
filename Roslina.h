#pragma once
#include "Organizm.h";

class Roslina : public Organizm {
public:
	Roslina(Swiat * swiat, int sila, int polozenieX, int polozenieY, const char literaOrganizmu);
	bool ProbaRozmnozeniaSie();
	virtual void Akcja() override;
	virtual bool Kolizja(Organizm* atakujacy) override;
	~Roslina();
};
