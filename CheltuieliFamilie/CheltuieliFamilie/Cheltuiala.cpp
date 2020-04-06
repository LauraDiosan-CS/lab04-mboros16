#include "Cheltuiala.h"
#include<string>
#include<iostream>
#include<fstream>
using namespace std;

///descriere: constructor implicit
///in:-
///out:

Cheltuiala::Cheltuiala()
{
	this->suma = 0;
	this->ziua = 0;
	this->tip_cheltuiala = "";
}

///descriere: constructor de copiere

Cheltuiala::Cheltuiala(int suma, int ziua, std::string tip_cheltuiala)
{
	this->suma = suma;
	this->ziua = ziua;
	this->tip_cheltuiala = tip_cheltuiala;

}

Cheltuiala::Cheltuiala(const Cheltuiala &c)
{
	this->suma = c.suma;
	this->ziua = c.ziua;
	this->tip_cheltuiala = c.tip_cheltuiala;
}

Cheltuiala::~Cheltuiala()
{

}

int Cheltuiala::getSuma()
{
	return this->suma;
}

int Cheltuiala::getZiua()
{
	return this->ziua;
}

std::string Cheltuiala::getTip_cheltuiala()
{
	return this->tip_cheltuiala;
}

void Cheltuiala::setSuma(int x)
{
	this->suma = x;
}

void Cheltuiala::setZiua(int y)
{
	this->ziua = y;
}

void Cheltuiala::setTip_cheltuiala(std::string z)
{
	this->tip_cheltuiala = z;
}

bool Cheltuiala::operator==(const Cheltuiala& c)
{
	if (this->ziua == c.ziua && this->suma == c.suma && this->tip_cheltuiala == c.tip_cheltuiala)
		return true;
	return false;
}

Cheltuiala& Cheltuiala::operator=(const Cheltuiala& c)
{
	this->suma = c.suma;
	this->ziua = c.ziua;
	this->tip_cheltuiala = c.tip_cheltuiala;
	return *this;
}

void Cheltuiala::print()
{
	std::cout << "Zi: " <<this->ziua<<"Tip: " << this->tip_cheltuiala << "Suma:"<< this->suma <<std::endl;
}