#include <iostream>
#include <cmath>
using namespace std;

double computeRMS(double* s, int n) {
    double sum = 0;

    for (int i = 0; i < n; i++)
        sum += (*(s + i)) * (*(s + i));

    return sqrt(sum / n);
}

void normalise(double* s, int n) {
    double max = 0;

    for (int i = 0; i < n; i++)
        if (fabs(*(s + i)) > max)
            max = fabs(*(s + i));

    for (int i = 0; i < n; i++)
        *(s + i) = *(s + i) / max;
}

int countZeroCrossings(double* s, int n) {
    int count = 0;

    for (int i = 0; i < n - 1; i++) {
        if ((*(s + i) < 0 && *(s + i + 1) > 0) ||
            (*(s + i) > 0 && *(s + i + 1) < 0))
            count++;
    }

    return count;
}

void applyGain(double* s, int n, double gain) {
    for (int i = 0; i < n; i++)
        *(s + i) *= gain;
}

void print(double* s, int n) {
    for (int i = 0; i < n; i++)
        cout << *(s + i) << " ";
    cout << endl;
}

int main() {
    double signal[] = {0.5, -1.2, 0.8, -0.3, 1.0, -0.9, 0.1};
    int n = 7;

    cout << "Before: ";
    print(signal, n);

    cout << "RMS: " << computeRMS(signal, n) << endl;
    cout << "Zero Crossings: " << countZeroCrossings(signal, n) << endl;

    normalise(signal, n);

    cout << "After Normalise: ";
    print(signal, n);

    applyGain(signal, n, 2);

    cout << "After Gain: ";
    print(signal, n);

    return 0;
}