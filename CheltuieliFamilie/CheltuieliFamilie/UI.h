#pragma once
#include <string>
#include<fstream>
#include <iostream>
#include "RepoCheltuieli.h"

using namespace std;

class UI
{
private:
	RepoCheltuieli repo;
public:

	void Meniu();

	void ADD();
	void EliminaCheltuieli(int zi);
	void EliminaCheltuieli(int zi_inceput, int zi_sfarsit);
	void EliminaCheltuieli(std::string tip_cheltuiala);
	
	void Afiseaza();
	void Afiseaza(std::string tip_cheltuiala);
	void Afiseaza(std::string tip_cheltuiala, int pret_minim);
	void AfiseazaFix(std::string tip_cheltuiala, int pret_fix);

	void SumaTipCheltuiala(std::string tip_cheltuiala);
	void MaxZi();
	void SortareZi();
	void SortareTip(std::string tip_cheltuiala);

	void FiltrareTip(std::string tip_cheltuiala);
	void FiltrareTip_ValMAX(std::string tip_cheltuiala, int valoare_maxima);
	void FiltrareTip_ValExacta(std::string tip_cheltuiala, int valoare_exacta);

	void Undo();
};
