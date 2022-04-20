#include "Mlecz.h";

Mlecz::Mlecz(Swiat* swiat, int polozenieX, int polozenieY) : Roslina(swiat, 0, polozenieX, polozenieY, 'M') {

}

void Mlecz::Akcja() {
	bool proba = false;
	for (int i = 0; i < 3; i++) {
		proba = ProbaRozmnozeniaSie();
		if (proba == true) {
			string komentarz = this->getNazwa() + " rozmnaza sie";
			swiat->dodajKomentarz(komentarz);
			break;
		}
	}
}

string Mlecz::getNazwa() const {
	return "Mlecz";
}