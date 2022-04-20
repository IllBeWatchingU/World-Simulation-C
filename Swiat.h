#pragma once
#define WORLD_WIDTH 30
#define WORLD_HEIGHT 20
#include "Organizm.h"
#include <vector>
#include <iostream>
#include <stdlib.h>   
#include <time.h>
#include <algorithm>
using namespace std;

class Organizm;
class Czlowiek;
class Zwierze;

class Swiat {
private:
	const int szerokosc, wysokosc;
	int tura;
	vector < Organizm* > organizmy = {};
	vector < Organizm* > noweOrganizmy = {};
	vector < string > komentarze = {};
	char** tablicaSwiata;
	int ruchCzlowieka = 0;

	//sortuje organizmy w zale�no�ci od inicjatywy (malej�co). Je�li dwa zwierz�ta maj� 
	//t� sam� inicjatyw�, por�wnuje je wiekiem (starszy ma pierwsze�stwo).
	void sortujOrganizmy();

	//zabija organizmy o inicjatywie mniejszej od 0 (ustawiane podczas metody Kolizja())
	void zabijOrganizmy();

	//postarza wszystkie �ywe organizmy o 1 tur�
	void postarzOrganizmy();

	//wprowadza nowo narodzone dzieci do wektora organizmy
	void przeniesNoweOrganizmy();

	void drukujPowiadomienia();
	void czyscPowiadomienia();
public:

	Swiat(const int& szerokosc, const int& wysokosc);

	//sprawdza, czy pole o wsp�rz�dnych (x,y) jest okupowane przez organizm czy nie
	bool czyPoleJestPuste(int x, int y);

	//sprawdza, czy wok� pola o wsp�rz�dnych (x.y) nie ma ani jednego wolnego miejsca. 
	//Zwraca 1 je�li nie ma, a 0 je�li jest chocia� jedno wolne miejsce.
	bool czyWszystkiePolaZajete(int x, int y);

	//sprawdza, czy dany organizm jest zwierz�ciem
	bool czyOrganizmJestZwierzeciem(Organizm* organizm);

	//zwraca wska�nik organizm znajduj�cy si� na wsp�rz�dnych (x,y)
	Organizm* getOrganizm(int x, int y);

	//zwraca wska�nik na cz�owieka 
	Czlowiek* getCzlowiek();

	//sprawdza, czy cz�owiek znajduje si� w wektorze organizmy
	bool czyCzlowiekZyje();
	//pr�buje aktywowa� umiej�tno�� cz�owieka. Zwraca 1 je�li aktywuje, 0 je�li nie aktywuje.
	bool aktywujUmiejetnoscCzlowieka();
	int getRuchCzlowieka();
	//ustawia ruch cz�owieka w zale�no�ci od wci�ni�tego klawisza przez u�ytkownika
	void setRuchCzlowieka(int ruchCzlowieka);

	//losuje zwierz�ta, kt�re pojawi� si� na �wiecie
	void inicjujSwiat();

	//dodaje organizm na pole o wsp�rz�dnych (polozenieX, polozenieY) i o gatunku bazowanym na podstawie litery rodzica.
	void dodajOrganizm(int polozenieX, int polozenieY, char literaOrganizmu);

	//we� losowe pole (mo�e by� zaj�te) wok� organizmu organizm
	int getLosowePole(Organizm* organizm);

	//we� losowe pole wok� organizmu organizm. Je�li jest zaj�te, to 
	//tylko wtedy jak znajduje si� tam organizm mniejszy si��
	int getLosowePoleMniejszegoSila(Organizm* organizm);

	//we� losowe puste pole wok� organizmu organizm
	int getLosowePustePole(Organizm* organizm);

	//we� losowe puste pole, albo dla organizmu organizm, albo dla jego partnera
	int getLosowePustePoleDlaObuOrganizmow(Organizm* organizm, Organizm* partner);

	//usuwa organizm z tablicy �wiata
	void usunOrganizmZPola(Organizm* organizm);
	//dodaje organizm do tablicy �wiata
	void dodajOrganizmDoPola(Organizm* organizm, int x, int y);

	void wykonajTure();

	void rysujSwiat();

	//funkcje komentatora
	void dodajKomentarz(string komentarz);
	

	~Swiat();
};