#pragma once
#include "Organizm.h"

#define DOMYSLNY_ZASIEG_RUCHU 1
#define DOMYSLNA_SZANSA_RUCHU 100

class Zwierze : public Organizm {
private:
	int szansaWykonaniaRuchu;
	int zasiegRuchu;

public: 

	Zwierze(Swiat* swiat, int sila, int inicjatywa,
		int polozenieX, int polozenieY, const char literaOrganizmu, int wiek);

	Zwierze(Swiat* swiat, int sila, int inicjatywa,
		int polozenieX, int polozenieY, const char literaOrganizmu, int wiek, int szansaWykonaniaRuchu, int zasiegRuchu);
	
	//settery
	void setZasiegRuchu(int zasieg);

	//gettery
	int getZasiegRuchu();
	int getSzansaRuchu();

	virtual bool czyTenSamGatunek(Organizm* organizm) = 0;
	virtual bool Rozmnazanie(Organizm* partner);
	virtual bool wykonajRuch();
	bool czyWykonujeRuch();
	virtual bool wykonajUnik(Organizm* atakujacy);

	virtual void Akcja() override;
	virtual bool Kolizja(Organizm* atakujacy) override;
	~Zwierze() override;
};
