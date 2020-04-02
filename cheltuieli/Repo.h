#pragma once
#include "Cheltuieli.h"
#include <vector>
class Repo
{
public:
	// constructors : without parameters; copy constr (have no ideea why , but i did it in case i will need it)
	Repo() = default;
	Repo(std::vector<Cheltuieli> cheltuielis):cheltuielis{ cheltuielis } {};
	~Repo() = default;

	// access members with :
	int getSize() { return cheltuielis.size(); }
	int getCapacity() { return cheltuielis.capacity(); }
	std::vector<Cheltuieli> getElements() { return cheltuielis; }

	// Everything related to functionality :
	void add(const Cheltuieli&);
	// returns first appearance's index in the container , -1 otherwise
	int findCheltuieli(const Cheltuieli&) const;
	int removeCheltuieli(const Cheltuieli&) ;
	int modifyCheltuieli(const Cheltuieli& off,const Cheltuieli& newCheltuieli);
private:
	std::vector<Cheltuieli> cheltuielis;
	
};

