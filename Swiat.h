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

	//sortuje organizmy w zale¿noœci od inicjatywy (malej¹co). Jeœli dwa zwierzêta maj¹ 
	//tê sam¹ inicjatywê, porównuje je wiekiem (starszy ma pierwszeñstwo).
	void sortujOrganizmy();

	//zabija organizmy o inicjatywie mniejszej od 0 (ustawiane podczas metody Kolizja())
	void zabijOrganizmy();

	//postarza wszystkie ¿ywe organizmy o 1 turê
	void postarzOrganizmy();

	//wprowadza nowo narodzone dzieci do wektora organizmy
	void przeniesNoweOrganizmy();

	void drukujPowiadomienia();
	void czyscPowiadomienia();
public:

	Swiat(const int& szerokosc, const int& wysokosc);

	//sprawdza, czy pole o wspó³rzêdnych (x,y) jest okupowane przez organizm czy nie
	bool czyPoleJestPuste(int x, int y);

	//sprawdza, czy wokó³ pola o wspó³rzêdnych (x.y) nie ma ani jednego wolnego miejsca. 
	//Zwraca 1 jeœli nie ma, a 0 jeœli jest chocia¿ jedno wolne miejsce.
	bool czyWszystkiePolaZajete(int x, int y);

	//sprawdza, czy dany organizm jest zwierzêciem
	bool czyOrganizmJestZwierzeciem(Organizm* organizm);

	//zwraca wskaŸnik organizm znajduj¹cy siê na wspó³rzêdnych (x,y)
	Organizm* getOrganizm(int x, int y);

	//zwraca wskaŸnik na cz³owieka 
	Czlowiek* getCzlowiek();

	//sprawdza, czy cz³owiek znajduje siê w wektorze organizmy
	bool czyCzlowiekZyje();
	//próbuje aktywowaæ umiejêtnoœæ cz³owieka. Zwraca 1 jeœli aktywuje, 0 jeœli nie aktywuje.
	bool aktywujUmiejetnoscCzlowieka();
	int getRuchCzlowieka();
	//ustawia ruch cz³owieka w zale¿noœci od wciœniêtego klawisza przez u¿ytkownika
	void setRuchCzlowieka(int ruchCzlowieka);

	//losuje zwierzêta, które pojawi¹ siê na œwiecie
	void inicjujSwiat();

	//dodaje organizm na pole o wspó³rzêdnych (polozenieX, polozenieY) i o gatunku bazowanym na podstawie litery rodzica.
	void dodajOrganizm(int polozenieX, int polozenieY, char literaOrganizmu);

	//weŸ losowe pole (mo¿e byæ zajête) wokó³ organizmu organizm
	int getLosowePole(Organizm* organizm);

	//weŸ losowe pole wokó³ organizmu organizm. Jeœli jest zajête, to 
	//tylko wtedy jak znajduje siê tam organizm mniejszy si³¹
	int getLosowePoleMniejszegoSila(Organizm* organizm);

	//weŸ losowe puste pole wokó³ organizmu organizm
	int getLosowePustePole(Organizm* organizm);

	//weŸ losowe puste pole, albo dla organizmu organizm, albo dla jego partnera
	int getLosowePustePoleDlaObuOrganizmow(Organizm* organizm, Organizm* partner);

	//usuwa organizm z tablicy œwiata
	void usunOrganizmZPola(Organizm* organizm);
	//dodaje organizm do tablicy œwiata
	void dodajOrganizmDoPola(Organizm* organizm, int x, int y);

	void wykonajTure();

	void rysujSwiat();

	//funkcje komentatora
	void dodajKomentarz(string komentarz);
	

	~Swiat();
};