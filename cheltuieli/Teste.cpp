#include "Teste.h"
#include <assert.h>

void testCheltuieli() {
	Cheltuieli off1;
	off1.setName("apa");
	
	off1.setType("bloc");
	off1.setPrice(15);
	off1.setData(20);
	// test setters, getters and copy constructor too
	
	/* -> */ Cheltuieli off= Cheltuieli(off1);
	
	assert(off.getName() == "apa");
	assert(off.getType() == "bloc");
	assert(off.getPrice() == 15);
	assert(off.getData() == 20);
	// test equals operator '=='
	assert(off == off1);
	// test constructor with parameters
	Cheltuieli cheltuieli(off1.getName(),off1.getType(),off1.getPrice(),off1.getData());
	assert(cheltuieli == off1);
	std::string toString;

	assert(cheltuieli.toStringCheltuieli() == "Cheltuieli's name : apa\nType :bloc\nPrice : 15\nData:20");
}  

void testCheltuielis() {
	
	Repo repository = Repo();
	Cheltuieli off1;
	
	off1.setName("apa");
	off1.setType("bloc");
	off1.setPrice(15);
	off1.setData(20);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	repository.add(off1);
	Cheltuieli off2("false","false",0,0);
	assert(repository.getSize() == 5);
	assert(repository.getCapacity() == 6);
	assert(repository.findCheltuieli(off1) == 0);
	assert(repository.findCheltuieli(off2) == -1);
	repository.add(Cheltuieli("true",  "true",1,1));
	assert(repository.removeCheltuieli(Cheltuieli("true", "true", 1,1))>-1);
	assert(repository.getSize() == 5);
	assert(repository.getCapacity() == 6);
	assert(repository.removeCheltuieli(off2)==-1);
	repository.add(off2);
	assert(repository.modifyCheltuieli(off2, Cheltuieli("incalzire","casa",20,15)) ==5 );
	assert(repository.modifyCheltuieli(off2, Cheltuieli("gaz", "casa", 21,10)) == -1);
}

void testService() {
	Repo repository = Repo();
	Cheltuieli off1;
	
	off1.setName("apa");
	off1.setType("bloc");
	off1.setPrice(15);
	off1.setData(20);
	Repo repo2 = Repo();
	repo2.add(off1);
	// The copy contructor of the Service class is disabled ( = delete)

	Service serv(repository);
	serv.add("apa",  "bloc", 15,20);				

	// The container can have no duplicates, so executing add with the same parameters again , wont add that offer to the container
	serv.add("apa", "bloc", 15,20);
	assert(serv.getElemente().size() == 1);
	serv.add("gaz", "bloc", 11,12);
	serv.add("apa",  "casa", 15,15);
	serv.add("curent",  "bloc", 15,15);
	
	// the new version of this off already exists , so it is going to be removed from the container and returns 1
	assert(serv.modifyCheltuieli("apa", "bloc", 15,20, "gaz", "bloc", 15,20)==1);
	assert(serv.getElemente().size() == 3);
	
	// the offer to be replaced does not exist , nothing happens , returns -1
	assert(serv.modifyCheltuieli("apa", "bloc", 15,20 ,"gaz", "bloc", 15,29)==1);
	
	// change first added off to have uppercase initials, returns the index where the old version was found , off1 was the first element to be added so the index is 0
	assert(serv.modifyCheltuieli("apa", "bloc", 15,20, "Apa", "bloc", 15,20)==0);
}