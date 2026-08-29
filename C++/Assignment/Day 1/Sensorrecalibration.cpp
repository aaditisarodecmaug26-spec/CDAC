#include <iostream>
using namespace std;

void resetSensorV1(int reading1, int reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorV2(int& reading1, int& reading2) {
    int temp = reading1;
    reading1 = reading2;
    reading2 = temp;
}

void resetSensorV3(int* reading1, int* reading2) {
    int temp = *reading1;
    *reading1 = *reading2;
    *reading2 = temp;
}

int main() {
    int A = 55;
    int B = 12;

    cout << "V1 : Call by Value " << endl;
    cout << "Before  : A = " << A << " B = " << B <<endl;
    resetSensorV1(A, B);
    cout << "After  : A = " << A << " B = " << B <<endl;

    cout << "V2 : Call by Refrence " << endl;
    cout << "Before  : A = " << A << " B = " << B <<endl;
    resetSensorV2(A, B);
    cout << "After  : A = " << A << " B = " << B <<endl;

    cout << "V3 : Call by Pointer" << endl;
    cout << "Before  : A = " << A << " B = " << B <<endl;
    resetSensorV3(&A, &B);
    cout << "After  : A = " << A << " B = " << B <<endl;

    return 0;

}