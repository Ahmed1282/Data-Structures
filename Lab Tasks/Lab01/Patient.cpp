#include "Patient.h"

Patient :: Patient()
{
    name = "\0";
    type = "\0";
    noOfDays = 0;
}

Patient :: Patient( string n, string t, int d)
{
    name = n;
    type = t;
    noOfDays = d;
}

void Patient :: setName(string n)
{
    name = n;
}

void Patient :: setType(string t)
{
    type = t;
}

void Patient :: setDays(int d)
{
    noOfDays = d;
}

string Patient :: getName()
{
    return name;
}

string Patient :: getType()
{
    return type;
}

int Patient :: getDays()
{
    return noOfDays;
}