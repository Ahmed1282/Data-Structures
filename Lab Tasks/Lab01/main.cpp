#include "Hospital.cpp"

int main()
{
    int choice;
    double doubleTemp;
    int intTemp;
    string stringTemp;

    Hospital *hospital = new Hospital;

    cout<<"1) In-Patient\n";
    cout<<"2) Out-Patient\n";
    cout<<"Choice: ";
    cin>>choice;
    cout<<endl;

    if ( choice == 1 )
    {
        hospital->getPatient().setType("In-Patient");
        cout<<"Number Of Days: ";
        cin >> intTemp;
        hospital->getPatient().setDays(intTemp);
        cout << "Daily Rate: ";
        cin >> doubleTemp;
        hospital->setDailyRate(doubleTemp);
        cout << "Medication Charges: ";
        cin >> intTemp;
        hospital->setMedicationCharges(intTemp);
        cout << "Hospital Charges: ";
        cin >> intTemp;
        hospital->setHospitalCharges(intTemp);
        cout<<endl;
        cout<< "Total Charges: " << hospital->getTotalCharges();
        cout << endl << endl;
    }
    else if(choice == 2 )
    {
        hospital->getPatient().setType("Out-Patient");
        cout << "Hospital Services  : ";
        cin >> intTemp;
        hospital->setHospitalServices(intTemp);
        cout << "Medication Charges : ";
        cin >> intTemp;
        hospital->setMedicationCharges(intTemp);
        cout<<endl;
        cout << "Total Charges: " << hospital->getTotalCharges(4);
        cout << endl << endl;
    }
    else
    {
        cout << "INVALID ";
        return 0;
    }

}
