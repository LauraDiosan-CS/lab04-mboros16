#ifndef REPO_H 
#define REPO_H 
#include "Cheltuieli.h" 
using namespace std; 
 
class Repo
{ 
    private:     
        Cheltuieli cheltuieli[10];     
        int noCheltuieli; 
 
    public:     
        Repo();     
        ~Repo();
        void addItem(Cheltuieli &s);
        Cheltuieli getItemFromPos(int pos);
        int getSize(); 
}; 
#endif
