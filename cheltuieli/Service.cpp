#include "Service.h"


void Service::add(std::string name, std::string type, int price,int data) {
	
	Cheltuieli cheltuieli(name, type, price,data);
	if(container.findCheltuieli(cheltuieli)==-1)
		container.add(cheltuieli);
	else {
		//TODO: throw exception/message , the cheltuieli already exists
	}

}
int Service::removeCheltuieli(std::string name, std::string type, int price,int data) {
	
	Cheltuieli cheltuieli(name, type, price,data);
	return container.removeCheltuieli(cheltuieli);
}

int Service::findCheltuieli(std::string name, std::string type, int price,int data) {
	return container.findCheltuieli(Cheltuieli(name, type, price,data));

}
std::vector<Cheltuieli> Service::findCheltuieliByPrice(int price) {
	std::vector<Cheltuieli> v;
	for (int i = 0; i < container.getSize(); i++)
	{
		if (container.getElements().operator[](i).getPrice() == price)
			v.push_back(Cheltuieli(container.getElements().operator[](i)));
	}
	return v;
}
std::vector<Cheltuieli> Service::findCheltuieliByData(int data) {
	std::vector<Cheltuieli> v;
	for (int i = 0; i < container.getSize(); i++)
	{
		if (container.getElements().operator[](i).getData() == data)
			v.push_back(Cheltuieli(container.getElements().operator[](i)));
	}
	return v;
}


int Service::modifyCheltuieli(std::string name, std::string type, int price,int data,std::string newName, std::string newType, int newPrice,int newData) {
	

	Cheltuieli cheltuieliNew(newName, newType, newPrice, newData);
	// Modifies the old Cheltuieli only if the new version of the offer is not in the container
	if (container.findCheltuieli(cheltuieliNew) == -1) {
		Cheltuieli cheltuieliOld(name,  type, price,data);
		return container.modifyCheltuieli(cheltuieliOld, cheltuieliNew);
	}
	return removeCheltuieli(name,  type, price,data);
	
	//		this method removes the element from the container
}
