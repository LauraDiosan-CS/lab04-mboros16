#include "Repo.h"


void Repo::add(const Cheltuieli& off){ 
	cheltuielis.push_back(off); 
}

int Repo::findCheltuieli(const Cheltuieli& off) const{
	for (int i = 0; i < cheltuielis.size(); i++) {
		{
			if (this->cheltuielis[i].operator==(off))
				return i;
				
		}
	}
	return -1;
}
int Repo::removeCheltuieli(const Cheltuieli& off) {
	int index = findCheltuieli(off);
	if (index > -1)
	{
		cheltuielis.erase(cheltuielis.begin() + index);
		return 1;
	}
	return -1;
}
int Repo::modifyCheltuieli(const Cheltuieli& off,const Cheltuieli& newCheltuieli) {
	int index = findCheltuieli(off);
	if (index > -1)
	{
		cheltuielis[index].setName(newCheltuieli.getName());
		return index;
	}
	return -1;
}