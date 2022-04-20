#include "Swiat.h";
#include <conio.h>
#define KEY_UP 119 //w
#define KEY_DOWN 115 //s
#define KEY_LEFT 97 //a
#define KEY_RIGHT 100 //d

int main() {
	Swiat* swiat = new Swiat(WORLD_WIDTH, WORLD_HEIGHT);
	swiat->inicjujSwiat();
	swiat->rysujSwiat();
	
	while (1) {
		if (swiat->czyCzlowiekZyje()) {
			switch(_getch()) {
			case 122: //klawisz 'z' aktywuje zdolnoœæ cz³owieka
				if (swiat->aktywujUmiejetnoscCzlowieka()) {
					cout << "Zdolnosc czlowieka zostala aktywowana! " << endl;
				}
				else {
					cout << "Zdolnosc czlowieka nie mogla byc aktywowana " << endl;
				}
				switch (_getch()) { // po zdolnoœci mo¿na albo ruszyæ siê cz³owiekiem, albo zacz¹æ now¹ turê bez ruchu
				case KEY_UP:
					swiat->setRuchCzlowieka(1);
					swiat->wykonajTure();
					break;
				case KEY_DOWN:
					swiat->setRuchCzlowieka(2);
					swiat->wykonajTure();
					break;
				case KEY_LEFT:
					swiat->setRuchCzlowieka(3);
					swiat->wykonajTure();
					break;
				case KEY_RIGHT:
					swiat->setRuchCzlowieka(4);
					swiat->wykonajTure();
					break;
				case 110:
					swiat->setRuchCzlowieka(0);
					swiat->wykonajTure();
					break;
				}
				break;
			case KEY_UP:
				swiat->setRuchCzlowieka(1);
				swiat->wykonajTure();
				break;
			case KEY_DOWN:
				swiat->setRuchCzlowieka(2);
				swiat->wykonajTure();
				break;
			case KEY_LEFT:
				swiat->setRuchCzlowieka(3);
				swiat->wykonajTure();
				break;
			case KEY_RIGHT:
				swiat->setRuchCzlowieka(4);
				swiat->wykonajTure();
				break;
			case 110:
				swiat->setRuchCzlowieka(0);
				swiat->wykonajTure();
				break;
			case 113:
				return 0;
				break;
			default:
				break;
			}
		}
		else {
			if (_getch() == 110) { //'n' rozpoczyna now¹ turê
				swiat->wykonajTure();
			}
			else if (_getch() == 113) { //'q' zamyka symulacjê
				return 0;
			}
		}
		
	}
}