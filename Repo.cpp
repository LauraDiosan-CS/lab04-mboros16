#include "Repo.h"

Repo::Repo()
{
    this->noCheltuieli = 0;
}
Repo::~Repo(){}
void Repo::addItem(Cheltuieli &s)
{
    this->cheltuieli[this->noCheltuieli++] = s;
}
Cheltuieli Repo::getItemFromPos(int pos)
{
    return this->cheltuieli[pos];
}
int Repo::getSize()
{
    return this->noCheltuieli;
}
