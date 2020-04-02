#pragma once
#include "Repo.h"
#include <vector>
class Service
{
public:
	// Service must not contain copy-constructor, thus we have to prevent the compiler to make it by appending =delete to the copy constructors declaration
	// In order to define a constructor for the Service class , a repository's constructor is needed 
	// since a member of this class has to be instantiated , we must use the initialization list;
	Service(Repo& cont) :container(cont) {};
	// copy constructor gets disabled
	Service(const Service&) = delete;
	void add(std::string name,std::string type,int price,int data);
	int findCheltuieli(std::string name, std::string type, int price,int data);
	int removeCheltuieli(std::string name, std::string type, int price,int data);
	int modifyCheltuieli(std::string name, std::string type, int price,int data, std::string newName,  std::string newType, int newPrice,int newData);
	std::vector<Cheltuieli> getElemente() const{ return container.getElements(); }
	std::vector<Cheltuieli> findCheltuieliByPrice(int price);
	std::vector<Cheltuieli> findCheltuieliByData(int data);
private:
	Repo& container;
};

