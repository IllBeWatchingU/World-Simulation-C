#pragma once
#include "Swiat.h"
#include <string>
using namespace std;

class Swiat;

class Organizm {

protected:
	Swiat * swiat;
	int sila;
	int inicjatywa;
	int polozenieX, polozenieY;
	int wiek;
	const char literaOrganizmu;

public:

	Organizm(Swiat * swiat, int sila, int inicjatywa, int polozenieX, int polozenieY, const char literaOrganizmu, int wiek);

	//settery 
	void setPolozenie(const int& x, const int& y);
	void setInicjatywa(const int& inicjatywa);
	void setSila(const int& sila);
	void setWiek(const int& wiek);

	//gettery
	int getSila() const;
	int getInicjatywa() const;
	int getWiek() const;
	char getLitera() const;
	int getX();
	int getY();

	virtual void Akcja() = 0;
	virtual bool Kolizja(Organizm * atakujacy) = 0;
	virtual bool odeprzyjAtak(Organizm* atakujacy);
	virtual string getNazwa() const = 0;
	virtual ~Organizm();

};
