#ifndef HOSPITAL_H_
#define HOSPITAL_H_
#include "Patient.cpp"

class Hospital
{
    private:
        Patient *ob;
        double dailyRate;
        int hospitalCharges;
        int medicationCharges;
        int hospitalServices;
    public:
        Hospital();
        Hospital(Patient tempObj, double dr, int hc, int mc, int hs);
        void setDailyRate(double dr);
        void setHospitalCharges(int hc);
        void setMedicationCharges(int mc);
        void setHospitalServices(int hs);
        double getDailyRate();
        int getHospitalCharges();
        int getMedicationCharges();
        int getHospitalServices();
        Patient getPatient();
        int getTotalCharges();                // for In-Patient
        int getTotalCharges(int dummyVar);    // for Out-Patient
};

#endif
