#include <iostream>
#include <iomanip>
using namespace std;

void inputTemperatures(double temperature[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Enter temperature for Floor " << i + 1
                 << ", Room " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }
}

void displayTemperatures(double temperature[3][3]) {
    cout << "\n\tRoom1\tRoom2\tRoom3" << endl;

    for (int i = 0; i < 3; i++) {
        cout << "Floor " << i + 1 << ":\t";

        for (int j = 0; j < 3; j++) {
            cout << temperature[i][j] << "\t";
        }

        cout << endl;
    }
}

void findHottestRoom(double temperature[3][3]) {
    double hottest = temperature[0][0];
    int hotFloor = 0;
    int hotRoom = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (temperature[i][j] > hottest) {
                hottest = temperature[i][j];
                hotFloor = i;
                hotRoom = j;
            }
        }
    }

    cout << "\nHottest Room : Floor " << hotFloor + 1
         << ", Room " << hotRoom + 1
         << " -> " << hottest << " C" << endl;
}

void findHottestFloor(double temperature[3][3]) {
    double highestAverage = 0;
    int hottestFloor = 0;

    for (int i = 0; i < 3; i++) {

        double sum = 0;

        for (int j = 0; j < 3; j++) {
            sum = sum + temperature[i][j];
        }

        double average = sum / 3;

        if (average > highestAverage) {
            highestAverage = average;
            hottestFloor = i;
        }
    }

    cout << "Hottest Floor : Floor " << hottestFloor + 1
         << " (avg " << fixed << setprecision(2)
         << highestAverage << " C)" << endl;
}

void countWarningRooms(double temperature[3][3]) {
    int count = 0;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {

            if (temperature[i][j] >= 30) {
                count++;
            }
        }
    }

    cout << "Rooms at WARNING or above : " << count << endl;
}

int main() {

    double temperature[3][3];

    inputTemperatures(temperature);

    displayTemperatures(temperature);

    findHottestRoom(temperature);

    findHottestFloor(temperature);

    countWarningRooms(temperature);

    return 0;
}