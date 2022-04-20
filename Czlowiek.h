#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int czasZdolnosci;
	int cooldownZdolnosci;
	bool czyZdolnoscAktywna;

	bool wykonajRuch() override;
	void wykonajUmiejetnosc();

	//sprawdza, czy zdolno�� mo�e by� w��czona, czy jest na cooldownie
	bool czyZdolnoscMoze();

public:
	Czlowiek(Swiat * swiat, int polozenieX, int polozenieY);

	//gettery
	int getCooldown();
	bool getCzyZdolnoscAktywna();

	//pr�buje aktywowa� umiej�tno��. Je�eli mu si� uda, zwraca 1. W przeciwnym razie zwraca 0.
	bool aktywujUmiejetnosc();

	bool czyTenSamGatunek(Organizm* organizm) override;
	
	void Akcja() override;
	string getNazwa() const override;
	~Czlowiek();
};
