#include <iostream>
#include <iomanip>
using namespace std;


void printValidReadings(double readings[], int n) {
    cout << "Valid Readings: ";

    for (int i = 0; i < n; i++) {
        if (readings[i] < 0) {
            continue;
        }

        cout << readings[i] << " ";
    }

    cout << endl;
}


void findFirstCritical(double readings[], int n) {
    for (int i = 0; i < n; i++) {
        if (readings[i] >= 45) {
            cout << "First CRITICAL: Index " << i
                 << " -> " << readings[i] << " C" << endl;
            break;
        }
    }
}

void findStats(double readings[], int n) {
    double min = 9999;
    double max = -9999;
    double sum = 0;
    int count = 0;

    for (int i = 0; i < n; i++) {

        if (readings[i] < 0) {
            continue;
        }

        if (readings[i] < min) {
            min = readings[i];
        }

        if (readings[i] > max) {
            max = readings[i];
        }

        sum = sum + readings[i];
        count++;
    }

    double average = sum / count;

    cout << fixed << setprecision(2);
    cout << "MIN: " << min << " C" << endl;
    cout << "MAX: " << max << " C" << endl;
    cout << "AVERAGE: " << average << " C" << endl;
}


void countCategories(double readings[], int n) {
    int normal = 0;
    int warning = 0;
    int critical = 0;
    int shutdown = 0;

    for (int i = 0; i < n; i++) {

        if (readings[i] < 0) {
            continue;
        }

        if (readings[i] < 30) {
            normal++;
        }
        else if (readings[i] < 45) {
            warning++;
        }
        else if (readings[i] < 60) {
            critical++;
        }
        else {
            shutdown++;
        }
    }

    cout << "Normal: " << normal << endl;
    cout << "Warning: " << warning << endl;
    cout << "Critical: " << critical << endl;
    cout << "Shutdown: " << shutdown << endl;
}

int main() {
    int n;
    double readings[100];

    cout << "Enter number of readings: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "Enter reading " << i << ": ";
        cin >> readings[i];
    }

    cout << "\nReadings entered: " << n << endl;

    printValidReadings(readings, n);

    findFirstCritical(readings, n);

    findStats(readings, n);

    countCategories(readings, n);

    return 0;
}