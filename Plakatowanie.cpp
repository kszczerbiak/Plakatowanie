#include <iostream>
#include <stack>	
#include <vector>
#include <cstdio>



struct budynek {
	int wysokosc;
	int szerokosc;
};

class Plakaty {

public:
	Plakaty() {
		this->wczytajDane();
		this->wypiszWynik(this->liczIloscPlakatow());
	}
private:
	std::stack<int> stosPlakatow;
	int liczbaBudynkow = 0;
	std::vector<budynek> budynki;

	void wczytajDane() {
		budynek tmpBudynek;
		std::cin >> this->liczbaBudynkow;
		for (int i = 0; i < this->liczbaBudynkow; i++)
		{
			std::cin >> tmpBudynek.szerokosc >> tmpBudynek.wysokosc;
			this->budynki.push_back(tmpBudynek);
		}
	};
	void wypiszWynik(int plakaty) {
		std::cout << plakaty;
	}
	int liczIloscPlakatow() {
		int plakaty = 0;
		for (int i = 0; i < liczbaBudynkow; i++)
		{
			while (this->stosPlakatow.size() != 0 && this->stosPlakatow.top() > this->budynki[i].wysokosc) {
				this->stosPlakatow.pop();
			}
			if (this->stosPlakatow.size() == 0 || this->stosPlakatow.top() < this->budynki[i].wysokosc) {
				this->stosPlakatow.push(budynki[i].wysokosc);
				plakaty++;
			}
		}
		return plakaty;
	}
};

int main()
{
	std::ios_base::sync_with_stdio(false);
	Plakaty plakaty;
};
