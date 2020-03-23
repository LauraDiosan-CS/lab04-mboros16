#include "Tests.h" 
#include "Operations.h" 
#include "assert.h" 
 
#include <iostream> 
using namespace std; 
 
void testFilterCheltuieli()
{     
    Cheltuieli s1("Mancare");     
    Cheltuieli s2("Internet");     
    Cheltuieli s3("Curent");     
    Cheltuieli s4("Gaz");     
    Cheltuieli chelt[4] = {s1, s2,s3, s4};     
    Cheltuieli results[4];     
    int m = 0;     
    filterCheltuieli(chelt, 4, "Mancare",results, m);
    assert (((m == 2) && (results[0] == s1) && (results[1] == s3)) == false); 
} 
 
void testFilterCheltuieliWithRepo()
{     
    Cheltuieli s1("Mancare");     
    Cheltuieli s2("Internet"); 
    Cheltuieli s3("Curent");     
    Cheltuieli s4("Gaz");
    Repo rep;
    rep.addItem(s1);     
    rep.addItem(s2);     
    rep.addItem(s3);     
    rep.addItem(s4);     
    Cheltuieli results[10];     
    int m = 0;     
    filterCheltuieliWithRepo(rep, "Mancare",results, m);
    assert (((m == 2) && (results[0] == s1) && (results[1] == s3))==false);
} 