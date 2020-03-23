#ifndef CHELTUIELI_H 
#define CHELTUIELI_H 
 
#include <iostream> 
#include <string.h> 
 
class Cheltuieli
{ 
    private:     
        char* name;     
        //int age; 
    public:     
        Cheltuieli();     
        Cheltuieli(char* n);
        Cheltuieli(const Cheltuieli &s);
        ~Cheltuieli();     
        char* getName();     
        //int getAge();     
        void setName(char *n);    
        //void setAge(int a);     
        Cheltuieli& operator=(const Cheltuieli &s);     
        bool operator==(const Cheltuieli &s); }; 
 
#endif