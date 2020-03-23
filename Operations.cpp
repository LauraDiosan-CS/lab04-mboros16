#include "operations.h" 
 
// filter all the cheltuieli of a given name
// In: an array of cheltuieli, a name (String)
// Out: an array of filtered cheltuieli and their number (integer)
void filterCheltuieli(Cheltuieli cheltuieli[], int n, char* s, Cheltuieli cheltuieliFilter[], int &m)
{     
    m = 0;     
    for(int i = 0; i < n; i++)
    {         
        if (strcmp(s, cheltuieli[i].getName()) == 0)
        {             
            cheltuieliFilter[m++] = cheltuieli[i];
        }     
    } 
} 
 
// filter all the cheltuieli of a given name 
// In: an array of cheltuieli and their number (integer), a name (String)
// Out: an array of filtered cheltuieli and their number (integer) 
void filterCheltuieliWithRepo(Repo &rep, char* s, Cheltuieli cheltuieliFilter[], int &m)
{     
    for(int i = 0; i < rep.getSize(); i++)
    {         
        Cheltuieli crtCheltuieli = rep.getItemFromPos(i); 
        if (strcmp(s, crtCheltuieli.getName()) == 0)
        {             
            cheltuieliFilter[m++] = crtCheltuieli;
        }     
    } 
} 