#include <iostream>
#include <string>
using namespace std;

class Patient {
    private:
    int patientID;
    string name;
    int age;
    string ward;
    const string bloodGroup;

    public:
    Patient() :
    patientID(0), name("Unknown"), age(0), ward("General"), bloodGroup("O+") {
        cout << "Default patient Registered. " << endl;
    }

    Patient(int id, const string& n) :
    patientID(id), name(n), age(0), ward("General"), bloodGroup("O+") {
        cout << "Emergency: " << name << endl;
    }

    Patient(int id, const string& n, int a, const string& w, const string& bg):
    patientID(id), name(n), age(a), ward(w), bloodGroup(bg) {
        cout << "Full Admission: " << name << endl;
    }

    ~Patient() {
        cout << "Patient" << name << "Discharged" << endl;
    }

    void displayRecord() const {
        cout << "\n----------Patient Record--------------";
        cout << "Patient ID: " << patientID << endl;
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
        cout << "Ward: " << ward << endl;
        cout << "Blood Group: " << bloodGroup << endl;
    }

    void transferWard(const string& newWard) {
        cout << "Transfer Ward: " << name << "-> " << newWard << endl;
        ward = newWard;
    }
};

int main() {
    Patient p1;
    Patient p2(1002, "Raj");
    Patient p3(1003, "Meera", 34, "Cardiology", "B+");

    p1.displayRecord();
    p2.displayRecord();
    p3.displayRecord();

    Patient *patients = new Patient[4];
    for(int i = 0; i < 4; i++) {
        patients[i].displayRecord();
    }
    patients[1].transferWard("ICU");
    delete[] patients;
    return 0;
}