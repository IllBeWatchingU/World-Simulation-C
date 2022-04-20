#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze {
private:
	int czasZdolnosci;
	int cooldownZdolnosci;
	bool czyZdolnoscAktywna;

	bool wykonajRuch() override;
	void wykonajUmiejetnosc();

	//sprawdza, czy zdolnoœæ mo¿e byæ w³¹czona, czy jest na cooldownie
	bool czyZdolnoscMoze();

public:
	Czlowiek(Swiat * swiat, int polozenieX, int polozenieY);

	//gettery
	int getCooldown();
	bool getCzyZdolnoscAktywna();

	//próbuje aktywowaæ umiejêtnoœæ. Je¿eli mu siê uda, zwraca 1. W przeciwnym razie zwraca 0.
	bool aktywujUmiejetnosc();

	bool czyTenSamGatunek(Organizm* organizm) override;
	
	void Akcja() override;
	string getNazwa() const override;
	~Czlowiek();
};
