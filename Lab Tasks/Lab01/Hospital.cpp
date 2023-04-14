#include "Hospital.h"

Hospital :: Hospital()
{
	ob = new Patient;
    ob->setDays(0);
    ob->setName("\0");
    ob->setType("\0");
    dailyRate = 0;
    hospitalCharges = 0;
    medicationCharges = 0;
    hospitalServices = 0;
}

Hospital :: Hospital (Patient tempObj, double dr, int hc, int mc, int hs)
{
	ob = new Patient;
    ob = &tempObj;
    dailyRate = dr;
    hospitalCharges = hc;
    medicationCharges = mc;
    hospitalServices = hs;
}

void Hospital :: setDailyRate(double dr)
{
    dailyRate = dr;
}

void Hospital :: setHospitalCharges(int hc)
{
    hospitalCharges = hc;
}

void Hospital :: setMedicationCharges(int mc)
{
    medicationCharges = mc;
}

void Hospital :: setHospitalServices(int hs)
{
    hospitalServices = hs;
}

double Hospital :: getDailyRate()
{
    return dailyRate;
}

int Hospital :: getHospitalCharges()
{
    return hospitalCharges;
}

int Hospital :: getMedicationCharges()
{
    return medicationCharges;
}

int Hospital :: getHospitalServices()
{
    return hospitalServices;
}

Patient Hospital :: getPatient()
{
    return *ob;
}

int Hospital :: getTotalCharges()
{
    int totalCharges;
    totalCharges = (dailyRate * hospitalCharges) + medicationCharges + hospitalServices;
    return totalCharges;
}

int Hospital :: getTotalCharges(int dummyVar)
{
    int totalCharges;
    totalCharges = medicationCharges + hospitalServices;
    return totalCharges;
}
