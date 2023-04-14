#ifndef PATIENT_H_
#define PATIENT_H_
#include <iostream>
using namespace std;

class Patient
{
    private:
        string name;
        string type;        
        int noOfDays; 
    public:
        Patient();
        Patient( string n, string t, int d);
        void setName(string n);
        void setType(string t);
        void setDays(int d);
        string getName();
        string getType();
        int getDays();
};

#endif
