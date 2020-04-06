#pragma once
#ifndef REPOSITORY_H
#define REPOSITORY_H
#include "Cheltuiala.h"
#include <iostream>
#include<string>
#include<fstream>
#include "lista.h"

using namespace std;

class RepoCheltuieli
{
public:
	List<Cheltuiala> cheltuieli;
	List<Cheltuiala> backup;

public:
	RepoCheltuieli();
	~RepoCheltuieli();
	void Add(Cheltuiala X);
	void Remove(Cheltuiala X);

	int getCount();
	List<Cheltuiala> * getAll();
	Cheltuiala *  get(Cheltuiala cheltuiala);
	void setBackupPoint();
	void UndoLastOperation();
};
#endif;