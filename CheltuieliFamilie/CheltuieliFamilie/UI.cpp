#include <string>
#include<fstream>
#include "UI.h"
#include<iostream>
using namespace std;

void UI::Meniu()
{
	printf("1.Adauga cheltuiala \n");
	printf("2.Elimina cheltuieli zi \n");
	printf("3.Elimina cheltuieli perioada \n");
	printf("4.Elimina cheltuieli tip \n");
	printf("5.Afiseaza \n");
	printf("6.Afiseaza tip cheltuiala \n");
	printf("7.Afiseaza tip cheltuiala & pret minim \n");
	printf("8.Afiseaza tip cheltuiala & pret fix \n");
	printf("9.Suma tip cheltuiala \n");
	printf("10.Max zi \n");
	printf("11.Sortare zi \n");
	printf("12.Sortare tip \n");
	printf("13.Filtrare tip \n");
	printf("14.Filtrare (tip & val maxima) \n");
	printf("15.Filtrare (tip & val fixa) \n");
	printf("16.Undo\n");

	int path = 0;
	std::cout << "Alege:";
	std::cin >> path;
	
	switch (path)
	{
	case 1:
		ADD();
		break;
	case 2:
	{
		int zi;
		std::cout << "Dati ziua:";
		std::cin >> zi;
		EliminaCheltuieli(zi);
	}
		break;
	case 3:
	{
		int zi_inceput;
		int zi_sfarsit;
		std::cout << "Zi inceput:";
		std::cin >> zi_inceput;
		std::cin >> zi_sfarsit;
		EliminaCheltuieli(zi_inceput, zi_sfarsit);
	}
		break;
	case 4:
	{
		std::string tip_cheltuiaala;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		EliminaCheltuieli(tip_cheltuiaala);
	}
		break;
	case 5:
	{
		Afiseaza();
	}
		break;
	case 6:
	{
		std::string tip_cheltuiaala;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		Afiseaza(tip_cheltuiaala);
	}
		break;
	case 7:
	{
		std::string tip_cheltuiaala;
		int pret_minim;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		std::cout << "Dati pretul minim:";
		std::cin >> pret_minim;
		Afiseaza(tip_cheltuiaala,pret_minim);
	}
		break;
	case 8:
	{
		std::string tip_cheltuiaala;
		int pret_fix;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		std::cout << "Dati pretul fix:";
		std::cin >> pret_fix;
		AfiseazaFix(tip_cheltuiaala, pret_fix);
	}
		break;
	case 9:
	{
		std::string tip_cheltuiaala;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		SumaTipCheltuiala(tip_cheltuiaala);
	}
		break;
	case 10:
	{
		MaxZi();
	}
		break;
	case 11:
	{
		SortareZi();
	}
		break;
	case 12:
	{
		std::string tip_cheltuiaala;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		SortareTip(tip_cheltuiaala);
	}
		break;
	case 13:
	{
		std::string tip_cheltuiaala;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		FiltrareTip(tip_cheltuiaala);
	}
		break;
	case 14:
	{
		std::string tip_cheltuiaala;
		int pret_maxim;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		std::cout << "Dati pretul maxim:";
		std::cin >> pret_maxim;
		FiltrareTip_ValMAX(tip_cheltuiaala, pret_maxim);
	}
		break;
	case 15:
	{
		std::string tip_cheltuiaala;
		int pret_fix;
		std::cout << "Dati tipul:";
		std::cin >> tip_cheltuiaala;
		std::cout << "Dati pretul fix:";
		std::cin >> pret_fix;
		FiltrareTip_ValMAX(tip_cheltuiaala, pret_fix);
	}
		break;
	case 16:
		break;
	}
}

void UI::ADD()
{
	int suma;
	int ziua;
	std::string tip_cheltuiala;

	cout << "ziua";
	cin >> ziua;

	cout << "tip cheltuiala:";
	cin >> tip_cheltuiala;

	cout << "suma";
	cin >> suma;
	Cheltuiala  c(suma, ziua, tip_cheltuiala);
	repo.Add(c);
}


void UI::EliminaCheltuieli(int zi)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getZiua() == zi)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}
}

void UI::EliminaCheltuieli(int zi_inceput, int zi_sfarsit)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		for (int j = zi_inceput; j < zi_sfarsit; j++)
		{
			Cheltuiala * c = cheltuieli[i];
			if (c->getZiua() >=zi_inceput && c->getZiua()<=zi_sfarsit )
			{
				repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
			}
		}
	}
}
void UI::EliminaCheltuieli(std::string tip_cheltuiala)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() == tip_cheltuiala)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}
}
void UI::Afiseaza()
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		c->print();
	}
}
void UI::Afiseaza(std::string tip_cheltuiala)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if(c->getTip_cheltuiala() == tip_cheltuiala)
			c->print();
	}
}
void UI::Afiseaza(std::string tip_cheltuiala, int pret_minim)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() == tip_cheltuiala && c->getSuma() >=pret_minim)
			c->print();
	}
}

void UI::AfiseazaFix(std::string tip_cheltuiala, int pret_fix)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() == tip_cheltuiala && c->getSuma() == pret_fix)
			c->print();
	}
}

void UI::SumaTipCheltuiala(std::string tip_cheltuiala)
{
	int total = 0;
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() == tip_cheltuiala)
			total += c->getSuma();
	}
	std::cout << "Total: "<<total<<std::endl;
}



void UI::MaxZi()
{
	int total_maxim = 0;
	int zi_max = 0;
	List<Cheltuiala> cheltuieli = repo.cheltuieli;

	for (int i = 1; i < 30; i++)
	{
		int total = 0;
		for (int j = 0; j < cheltuieli.getCount(); j++)
		{
			Cheltuiala * c = cheltuieli[j];
			if (c->getZiua() == i)
				total += c->getSuma();
		}
		if (total_maxim < total)
		{
			total_maxim = total;
			zi_max = i;
		}
	}
	std::cout << "Ziua:" << zi_max << " Total:"<<total_maxim<<std::endl;
}


void UI::SortareZi()
{
	
	/*for (int i = 1; i < 30; i++)
	{
		int total = 0;
		for (int j = 0; j < repo.getCount(); j++)
		{
			Cheltuiala c = repo.get(j);
			if (c.getZiua() == i)
				c.print();
		}
	}*/
}
void UI::SortareTip(std::string tip_cheltuiala)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() != tip_cheltuiala)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}
}

void UI::FiltrareTip(std::string tip_cheltuiala)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() != tip_cheltuiala)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}
}

void UI::FiltrareTip_ValMAX(std::string tip_cheltuiala, int valoare_maxima)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() != tip_cheltuiala || c->getSuma() >= valoare_maxima)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}

}
void UI::FiltrareTip_ValExacta(std::string tip_cheltuiala, int valoare_exacta)
{
	List<Cheltuiala> cheltuieli = repo.cheltuieli;
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (c->getTip_cheltuiala() != tip_cheltuiala || c->getSuma() >= valoare_exacta)
		{
			repo.Remove(Cheltuiala(c->getSuma(), c->getZiua(), c->getTip_cheltuiala()));
		}
	}
}

void UI::Undo()
{
	repo.UndoLastOperation();
}