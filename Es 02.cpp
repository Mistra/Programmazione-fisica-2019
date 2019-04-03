#include <cmath>
#include <iostream>

using namespace std;

float deviazione(float a, float b, float c) {
    float media = (a + b + c) / 3;
    float dev_unsquared =
        (pow((a - media), 2) + pow((b - media), 2) + pow((c - media), 2));
    float dev = sqrt(dev_unsquared);
    return dev;
}

int main() {
    float a, b, c;
    cout << "Dammi il valore 1" << endl;
    cin >> a;
    cout << "Dammi il valore 2" << endl;
    cin >> b;
    cout << "Dammi il valore 3" << endl;
    cin >> c;

    float dev = deviazione(a, b, c);

    cout << "La deviazione standard è: " << dev << endl;

    return 0;
}