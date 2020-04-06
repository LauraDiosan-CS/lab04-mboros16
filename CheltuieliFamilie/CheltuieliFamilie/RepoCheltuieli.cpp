#include<iostream>
#include<fstream>
#include "RepoCheltuieli.h"
using namespace std;

RepoCheltuieli::RepoCheltuieli()
{

}

RepoCheltuieli::~RepoCheltuieli()
{
	cout << "DESTRUCTOR" << endl;
}

void RepoCheltuieli::setBackupPoint()
{
	//backup.clear();
	//backup = List<Cheltuiala>(cheltuieli);
}

void RepoCheltuieli::UndoLastOperation()
{
	cheltuieli = backup;
}

void RepoCheltuieli::Add(Cheltuiala X)
{
	setBackupPoint();
	Cheltuiala * c = new Cheltuiala(X);
	cheltuieli.Add(c);
}

void RepoCheltuieli::Remove(Cheltuiala X)
{
	setBackupPoint();
	Cheltuiala * c = get(X);
	cheltuieli.Remove(c);
	//delete c;
}

Cheltuiala * RepoCheltuieli::get(Cheltuiala cheltuiala)
{
	for (int i = 0; i < cheltuieli.getCount(); i++)
	{
		Cheltuiala * c = cheltuieli[i];
		if (cheltuiala.getTip_cheltuiala() == c->getTip_cheltuiala()
			&& cheltuiala.getSuma() == c->getSuma()
			&& cheltuiala.getZiua() == c->getZiua())
			return c;
	}
	return nullptr;
}


int RepoCheltuieli::getCount()
{
	return cheltuieli.getCount();
}


List<Cheltuiala> *  RepoCheltuieli::getAll()
{
	return &cheltuieli;
}