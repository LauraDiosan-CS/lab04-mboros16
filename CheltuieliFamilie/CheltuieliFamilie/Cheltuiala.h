#pragma once
#ifndef CHELTUIALA_H
#define CHELTUIALA_H
#include <string>
#include <iostream>
#include<time.h>
using namespace std;


class Cheltuiala {
private:
	int suma;
	int ziua;
	std::string tip_cheltuiala;

public:
	Cheltuiala();
	Cheltuiala(int suma,int ziua, std::string tip_cheltuiala);
	Cheltuiala(const Cheltuiala &c);
	int getSuma();
	int getZiua();
	std::string getTip_cheltuiala();
	void setSuma(int suma);
	void setZiua(int ziua);
	void setTip_cheltuiala(std::string tip_cheltuiala);
	~Cheltuiala();
	bool operator==(const Cheltuiala& c);
	Cheltuiala& operator=(const Cheltuiala& newc);

	void print();

	friend istream& operator >> (istream &input, Cheltuiala &c);
	friend ostream&operator<<(ostream &output, Cheltuiala &c);
};
#endif //CHELTUIALA_H