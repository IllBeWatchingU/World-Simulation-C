#include "Swiat.h";
#include "NaglowkiOrganizmow.h";

Swiat::Swiat(const int& szerokosc, const int& wysokosc) : szerokosc(szerokosc), wysokosc(wysokosc), tura(1){
	//tworzy dwuwymiarow¹ tablicê œwiata, w której przechowywane s¹ znaki organizmów
	this->tablicaSwiata = new char*[this->wysokosc];
	for (int i = 0; i < this->wysokosc; i++) {
		this->tablicaSwiata[i] = new char[this->szerokosc];
	}

	for (int i = 0; i < this->wysokosc; i++) {
		for (int j = 0; j < this->szerokosc; j++) {
			this->tablicaSwiata[i][j] = '0';
		}
	}

	srand(time(NULL));
}

bool Swiat::czyPoleJestPuste(int x, int y) {
	if (x >= WORLD_WIDTH || y >= WORLD_HEIGHT || x < 0 || y < 0) {
		return false;
	}
	if (tablicaSwiata[y][x] == '0') {
		return true;
	}
	else {
		return false;
	}
}

bool Swiat::czyWszystkiePolaZajete(int x, int y) {
	int north = y - 1;
	int south = y + 1;
	int west = x - 1;
	int east = x + 1;

	bool isNorthEmpty;
	if (north < 0) {
		isNorthEmpty = false;
	}
	else {
		isNorthEmpty = czyPoleJestPuste(x, north);
	}

	bool isSouthEmpty;
	if (south >= WORLD_HEIGHT) {
		isSouthEmpty = false;
	}
	else {
		isSouthEmpty = czyPoleJestPuste(x, south);
	}

	bool isWestEmpty;
	if (west < 0) {
		isWestEmpty = false;
	}
	else {
		isWestEmpty = czyPoleJestPuste(west, y);
	}

	bool isEastEmpty;
	if (east >= WORLD_WIDTH) {
		isEastEmpty = false;
	}
	else {
		isEastEmpty = czyPoleJestPuste(east, y);
	}
	
	if (!isNorthEmpty && !isSouthEmpty && !isWestEmpty && !isEastEmpty) {
		return true;
	}
	else {
		return false;
	}
	
}

bool Swiat::czyOrganizmJestZwierzeciem(Organizm* organizm) {
	if (organizm == NULL) {
		return false;
	}
	char test = organizm->getLitera();
	if (test == 'W' || test == 'O' || test == 'C' || test == 'Z' || test == 'A' || test == 'L') {
		return true;
	}
	return false;
}
/*
void Swiat::inicjujSwiat() {
	int randomX = 0;
	int randomY = 0;
	Organizm* organizm = new BarszczSosnowskiego(this, randomX, randomY);
	organizmy.push_back(organizm);
	tablicaSwiata[randomY][randomX] = organizm->getLitera();
	
	randomX = 1;
	randomY = 0;
	Organizm* organizmDwa = new BarszczSosnowskiego(this, randomX, randomY);
	organizmy.push_back(organizmDwa);
	tablicaSwiata[randomY][randomX] = organizmDwa->getLitera();
	randomX = 0;
	randomY = 1;
	Organizm* organizmTrzy = new BarszczSosnowskiego(this, randomX, randomY);
	organizmy.push_back(organizmTrzy);
	tablicaSwiata[randomY][randomX] = organizmTrzy->getLitera();
	
	sortujOrganizmy();
}
*/

void Swiat::inicjujSwiat() {
	for (int i = 1; i <= 10; i++) {

		int chance = rand() % 3 + 1;
		int j = 0;
		while(j < chance){

			//losuje losowe pola dla nowo wygenerowanej postaci
			int randomX = rand() % WORLD_WIDTH;
			int randomY = rand() % WORLD_HEIGHT;

			if (czyPoleJestPuste(randomX, randomY)) {
				j++;
				Organizm* organizm = NULL;

				//z ka¿dego gatunku musi istnieæ w œwiecie od 1 do 3 osobników
				switch (i) {
				case 1:
					organizm = new Wilk(this, randomX, randomY);
					break;
				case 2:
					organizm = new Owca(this, randomX, randomY);
					break;
				case 3:
					organizm = new Lis(this, randomX, randomY);
					break;
				case 4:
					organizm = new Zolw(this, randomX, randomY);
					break;
				case 5:
					organizm = new Antylopa(this, randomX, randomY);
					break;
				case 6:
					organizm = new Trawa(this, randomX, randomY);
					break;
				case 7:
					organizm = new Mlecz(this, randomX, randomY);
					break;
				case 8:
					organizm = new Guarana(this, randomX, randomY);
					break;
				case 9:
					organizm = new WilczeJagody(this, randomX, randomY);
					break;
				case 10:
					organizm = new BarszczSosnowskiego(this, randomX, randomY);
					break;
				}

				organizmy.push_back(organizm);
				tablicaSwiata[randomY][randomX] = organizm->getLitera();
			}
		}
	}
	
	//znajduje losowe puste pole i generuje cz³owieka
	while (true) {
		int randomX = rand() % WORLD_WIDTH;
		int randomY = rand() % WORLD_HEIGHT;
		if (czyPoleJestPuste(randomX, randomY)) {
			Organizm* organizm = new Czlowiek(this, randomX, randomY);
			organizmy.push_back(organizm);
			tablicaSwiata[randomY][randomX] = organizm->getLitera();
			break;
		}
	}
	
	sortujOrganizmy();
}


bool sortowaniePoInicjatywie(Organizm* x, Organizm* y) {
	return x->getInicjatywa() > y->getInicjatywa();
}

void Swiat::sortujOrganizmy() {
	//sortuje organizmy najpierw po inicjatywie...
	sort(organizmy.begin(), organizmy.end(), sortowaniePoInicjatywie);
	//...a potem, jeœli inicjatywy dwóch organizmów s¹ równe, to sortuje je po wieku
	for (int i = 1; i < organizmy.size(); i++) {
		if (organizmy[i]->getInicjatywa() == organizmy[i - 1]->getInicjatywa()) {
			if (organizmy[i]->getWiek() > organizmy[i - 1]->getWiek()) {
				swap(organizmy[i - 1], organizmy[i]);
			}
		}
	}
}

Organizm* Swiat::getOrganizm(int x, int y) {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getX() == x && organizmy[i]->getY() == y) {
			return organizmy[i];
		}
	}
}

Czlowiek* Swiat::getCzlowiek() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getLitera() == 'C') {
			Czlowiek* czlowiek = dynamic_cast <Czlowiek*> (organizmy[i]);
			return czlowiek;
		}
	}
	return NULL;
}

void Swiat::setRuchCzlowieka(int ruchCzlowieka) {
	Czlowiek* czlowiek = getCzlowiek();
	switch (ruchCzlowieka) {
	case 1:
		if (czlowiek->getY() == 0) {
			this->ruchCzlowieka = 0;
		}
		else {
			this->ruchCzlowieka = ruchCzlowieka;
		}
		break;
	case 2:
		if (czlowiek->getY() == WORLD_HEIGHT - 1) {
			this->ruchCzlowieka = 0;
		}
		else {
			this->ruchCzlowieka = ruchCzlowieka;
		}
		break;
	case 3:
		if (czlowiek->getX() == 0) {
			this->ruchCzlowieka = 0;
		}
		else {
			this->ruchCzlowieka = ruchCzlowieka;
		}
		break;
	case 4:
		if (czlowiek->getX() == WORLD_WIDTH - 1) {
			this->ruchCzlowieka = 0;
		}
		else {
			this->ruchCzlowieka = ruchCzlowieka;
		}
		break;
	default:
		this->ruchCzlowieka = 0;
		break;
	}
	
}

int Swiat::getRuchCzlowieka() {
	return ruchCzlowieka;
}

bool Swiat::czyCzlowiekZyje() {
	Czlowiek* organizm = getCzlowiek();
	if (organizm != NULL) {
		return true;
	}
	return false;
}

bool Swiat::aktywujUmiejetnoscCzlowieka() {
	Czlowiek* organizm = getCzlowiek();
	if (organizm != NULL) {
		if (organizm->aktywujUmiejetnosc()) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

void Swiat::zabijOrganizmy() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getInicjatywa() < 0) {
			delete organizmy[i];
			organizmy.erase(organizmy.begin() + i);
		}
	}
}

void Swiat::postarzOrganizmy() {
	for (int i = 0; i < organizmy.size(); i++) {
		int temp = organizmy[i]->getWiek();
		temp++;
		organizmy[i]->setWiek(temp);
	}
}

void Swiat::przeniesNoweOrganizmy() {
	for(int i = 0; i < noweOrganizmy.size(); i++) {
		tablicaSwiata[noweOrganizmy[i]->getY()][noweOrganizmy[i]->getX()] = noweOrganizmy[i]->getLitera();
		organizmy.push_back(noweOrganizmy[i]);
	}
	noweOrganizmy.clear();
}

void Swiat::dodajOrganizm(int polozenieX, int polozenieY, char literaOrganizmu) {
	if (czyPoleJestPuste(polozenieX, polozenieY)) {
		Organizm* organizm;

		switch (literaOrganizmu) {
		case 'W':
			organizm = new Wilk(this, polozenieX, polozenieY);
			break;
		case 'O':
			organizm = new Owca(this, polozenieX, polozenieY);
			break;
		case 'L':
			organizm = new Lis(this, polozenieX, polozenieY);
			break;
		case 'Z':
			organizm = new Zolw(this, polozenieX, polozenieY);
			break;
		case 'A':
			organizm = new Antylopa(this, polozenieX, polozenieY);
			break;
		case 'T':
			organizm = new Trawa(this, polozenieX, polozenieY);
			break;
		case 'M':
			organizm = new Mlecz(this, polozenieX, polozenieY);
			break;
		case 'G':
			organizm = new Guarana(this, polozenieX, polozenieY);
			break;
		case 'J':
			organizm = new WilczeJagody(this, polozenieX, polozenieY);
			break;
		case 'B':
			organizm = new BarszczSosnowskiego(this, polozenieX, polozenieY);
			break;
		}

		noweOrganizmy.push_back(organizm);
	}
}

int Swiat::getLosowePole(Organizm* organizm) {
	vector <int> losowe = { 1,2,3,4 };
	int size = 4;
	random_shuffle(losowe.begin(), losowe.end());
	int losowePole = losowe[0];
	while (size != 0) {
		switch (losowePole) {
		case 1:
			if (organizm->getY() != 0) {
				return 1;
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 2:
			if (organizm->getY() != WORLD_HEIGHT - 1) {
				return 2;
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 3:
			if (organizm->getX() != 0) {
				return 3;
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 4:
			if (organizm->getX() != WORLD_WIDTH - 1) {
				return 4;
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		}
	}
	return 0;
}

int Swiat::getLosowePoleMniejszegoSila(Organizm* organizm) {
	vector <int> losowe = { 1,2,3,4 };
	int size = 4;
	random_shuffle(losowe.begin(), losowe.end());
	int losowePole = losowe[0];
	while (size != 0) {
		switch (losowePole) {
		case 1:
			if (organizm->getY() != 0) {
				if (!czyPoleJestPuste(organizm->getX(), organizm->getY() - 1)) {
					Organizm* naPolu = getOrganizm(organizm->getX(), organizm->getY() - 1);
					if (naPolu->getSila() < organizm->getSila()) {
						return 1;
					}
				}
				
				else {
					return 1;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 2:
			if (organizm->getY() != WORLD_HEIGHT - 1) {
				if (!czyPoleJestPuste(organizm->getX(), organizm->getY() + 1)) {
					Organizm* naPolu = getOrganizm(organizm->getX(), organizm->getY() + 1);
					if (naPolu->getSila() < organizm->getSila()) {
						return 2;
					}
				}
				else {
					return 2;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 3:
			if (organizm->getX() != 0) {
				if (!czyPoleJestPuste(organizm->getX() - 1, organizm->getY())) {
					Organizm* naPolu = getOrganizm(organizm->getX() - 1, organizm->getY());
					if (naPolu->getSila() < organizm->getSila()) {
						return 3;
					}
				}
				else {
					return 3;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 4:
			if (organizm->getX() != WORLD_WIDTH - 1) {
				if (!czyPoleJestPuste(organizm->getX() + 1, organizm->getY())) {
					Organizm* naPolu = getOrganizm(organizm->getX() + 1, organizm->getY());
					if (naPolu->getSila() < organizm->getSila()) {
						return 4;
					}
				}
				else {
					return 4;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		}
	}
	return 0;
}

int Swiat::getLosowePustePole(Organizm* organizm) {
		vector <int> losowe = { 1,2,3,4 };
		int size = 4;
		random_shuffle(losowe.begin(), losowe.end());
		int losowePole = losowe[0];
		while (size != 0) {
			switch (losowePole) {
			case 1:
				if (organizm->getY() != 0) {
					if (tablicaSwiata[organizm->getY() - 1][organizm->getX()] == '0') {
						return 1;
					}
				}
				if (size == 1) {
					losowe.erase(losowe.begin());
				}
				else {
					losowe.erase(losowe.begin());
					losowePole = losowe[0];
				}
				size--;
				break;
			case 2:
				if (organizm->getY() != WORLD_HEIGHT - 1) {
					if (tablicaSwiata[organizm->getY() + 1][organizm->getX()] == '0') {
						return 2;
					}
				}
				if (size == 1) {
					losowe.erase(losowe.begin());
				}
				else {
					losowe.erase(losowe.begin());
					losowePole = losowe[0];
				}
				size--;
				break;
			case 3:
				if (organizm->getX() != 0) {
					if (tablicaSwiata[organizm->getY()][organizm->getX() - 1] == '0') {
						return 3;
					}
				}
				if (size == 1) {
					losowe.erase(losowe.begin());
				}
				else {
					losowe.erase(losowe.begin());
					losowePole = losowe[0];
				}
				size--;
				break;
			case 4:
				if (organizm->getX() != WORLD_WIDTH - 1) {
					if (tablicaSwiata[organizm->getY()][organizm->getX() + 1] == '0') {
						return 4;
					}
				}
				if (size == 1) {
					losowe.erase(losowe.begin());
				}
				else {
					losowe.erase(losowe.begin());
					losowePole = losowe[0];
				}
				size--;
				break;
			}
		}
		return 0;
}

int Swiat::getLosowePustePoleDlaObuOrganizmow(Organizm* organizm, Organizm* partner) {
	vector <int> losowe = { 1,2,3,4 };
	int size = 4;
	random_shuffle(losowe.begin(), losowe.end());
	int losowePole = losowe[0];
	while (size != 0) {
		switch (losowePole) {
		case 1:
			if (organizm->getY() != 0) {
				if (tablicaSwiata[organizm->getY() - 1][organizm->getX()] == '0') {
					return 1;
				}
			}
			if (partner->getY() != 0) {
				if (tablicaSwiata[partner->getY() - 1][partner->getX()] == '0') {
					return 5;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 2:
			if (organizm->getY() != WORLD_HEIGHT - 1) {
				if (tablicaSwiata[organizm->getY() + 1][organizm->getX()] == '0') {
					return 2;
				}
			}
			if (partner->getY() != WORLD_HEIGHT - 1) {
				if (tablicaSwiata[partner->getY() + 1][partner->getX()] == '0') {
					return 6;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 3:
			if (organizm->getX() != 0) {
				if (tablicaSwiata[organizm->getY()][organizm->getX() - 1] == '0') {
					return 3;
				}
			}
			if (partner->getX() != 0) {
				if (tablicaSwiata[partner->getY()][partner->getX() - 1] == '0') {
					return 7;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		case 4:
			if (organizm->getX() != WORLD_WIDTH - 1) {
				if (tablicaSwiata[organizm->getY()][organizm->getX() + 1] == '0') {
					return 4;
				}
			}
			if (partner->getX() != WORLD_WIDTH - 1) {
				if (tablicaSwiata[partner->getY()][partner->getX() + 1] == '0') {
					return 8;
				}
			}
			if (size == 1) {
				losowe.erase(losowe.begin());
			}
			else {
				losowe.erase(losowe.begin());
				losowePole = losowe[0];
			}
			size--;
			break;
		}
	}
}

void Swiat::usunOrganizmZPola(Organizm* organizm) {
	//cout << "Usuwam " << tablicaSwiata[organizm->getY()][organizm->getX()] << " z pola " << organizm->getX() << " " << organizm->getY() << endl;
	tablicaSwiata[organizm->getY()][organizm->getX()] = '0';
	
}

void Swiat::dodajOrganizmDoPola(Organizm* organizm, int x, int y) {
		tablicaSwiata[y][x] = organizm->getLitera();
		//cout << "Zmieniam " << tablicaSwiata[y][x] << " na pole " << x << " " << y << endl;
		//cout << "Zmiana: " << tablicaSwiata[y][x] << endl;
}

void Swiat::rysujSwiat() {
	for (int i = 0; i < WORLD_WIDTH + 2; i++) {
		cout << "=";
	}
	cout << endl;
	for (int i = 0; i < WORLD_HEIGHT; i++) {
		cout << "|";
		for (int j = 0; j < WORLD_WIDTH; j++) {
			if (tablicaSwiata[i][j] != '0') {
				cout << tablicaSwiata[i][j];
			}
			else {
				cout << " ";
			}
		}
		cout << "|";
		cout << endl;
	}
	for (int i = 0; i < WORLD_WIDTH + 2; i++) {
		cout << "=";
	}
	cout << endl;
	cout << "Tura numer: " << tura << endl;
}

void Swiat::dodajKomentarz(string komentarz) {
	komentarze.push_back(komentarz);
}

void Swiat::drukujPowiadomienia() {
	for (int i = 0; i < komentarze.size(); i++) {
		cout << komentarze[i] << endl;
	}
}

void Swiat::czyscPowiadomienia() {
	komentarze.clear();
}

void Swiat::wykonajTure() {
	for (int i = 0; i < organizmy.size(); i++) {
		if (organizmy[i]->getInicjatywa() >= 0) {
			//cout << organizmy[i]->getLitera() << " Wspolrzedne: " << organizmy[i]->getX() << " " << organizmy[i]->getY() << endl;
			organizmy[i]->Akcja();
		}
	}
	zabijOrganizmy();
	postarzOrganizmy();
	przeniesNoweOrganizmy();
	sortujOrganizmy();
	tura++;
	rysujSwiat();
	drukujPowiadomienia();
	czyscPowiadomienia();
}

Swiat::~Swiat() {
	int max = organizmy.size();
	for (int i = max - 1; i >= 0; i--) {
		delete organizmy[i];
		organizmy.pop_back();
	}

	max = noweOrganizmy.size();
	for (int i = max - 1; i >= 0; i--) {
		delete noweOrganizmy[i];
		noweOrganizmy.pop_back();
	}

	for (int i = 0; i < WORLD_WIDTH; i++) {
		delete[] tablicaSwiata[i];
	}
	delete[] tablicaSwiata;
}