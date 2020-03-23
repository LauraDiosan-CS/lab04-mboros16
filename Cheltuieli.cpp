#include "Cheltuieli.h"
#include <iostream>
#include <string.h>

// Constructor
// In: -
// Out: an empty object of type Cheltuieli
Cheltuieli::Cheltuieli()
{
    this->name = NULL;
    //this->age = 0;
}

// Constructor with parameters
// In: a name (string)
// Out: an object of type Cheltuieli that contains the given info
Cheltuieli::Cheltuieli(char* n)
{
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, sizeof this->name, n);
    //this->age = a;
}

// Copy constructor
// In: an object s of type Cheltuieli
// Out: another object of type Cheltuieli that contains the same info as s
Cheltuieli::Cheltuieli(const Cheltuieli &s)
{
    this->name = new char[strlen(s.name) + 1];
    strcpy_s(this->name, sizeof this->name, s.name);
    //this->age = s.age;
}

// Desonstructor
// In: an object of type Cheltuieli
// Out: -
Cheltuieli::~Cheltuieli()
{
    if (this->name)
    {
        delete[] this->name;
        this->name = NULL;
    }
}

// getter
// In: an object of type Cheltuieli
// Out: name of the cheltuieli
char* Cheltuieli::getName()
{
    return this->name;
}


// setter
// In: an object of type Cheltuieli and a name (string)
// Out: the same object with a new name
void Cheltuieli::setName(char *n)
{
    if (this->name)
    {
        delete[] this->name;
    }
    this->name = new char[strlen(n) + 1];
    strcpy_s(this->name, sizeof this->name, n);
}


// assignment operator
// In: two objects of type Cheltuieli (the current one, this, and s)
// Out: the new state of the current object (this)
Cheltuieli& Cheltuieli::operator=(const Cheltuieli &s)
{
    this->setName(s.name);
    return *this;
}

// comparator
// In: two objects of type Cheltuieli (this and s)
// Out: true or false
bool Cheltuieli::operator==(const Cheltuieli &s)
{
    return (strcmp(this->name, s.name) == 0);
}
