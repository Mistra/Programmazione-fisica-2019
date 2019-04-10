#include <cmath>
#include <iostream>

using namespace std;

void risoluzione1(float a, float b) {
    if (a == 0) {
        if (b == 0) {
            cout << "eq sempre vera" << endl;
        } else {
            cout << "eq impossibile" << endl;
        }
    } else {
        cout << "il risultao vale" << -b / a << endl;
    }
}

void risoluzione2(float a, float b, float c) {
    // manca la parte immaginaria
    if (a == 0) {
        return risoluzione1(b, c);
    }
    float delta = pow(b, 2) - 4 * a * c;
    if (delta > 0) {
        float risultato1 = (-b + sqrt(delta)) / 2 * a;
        float risultato2 = (-b - sqrt(delta)) / 2 * a;
        cout << "r1:" << risultato1 << "r2:" << risultato2 << endl;
    }
    if (delta == 0) {
        float risultato1 = (-b / 2 * a);
        cout << "r:" << risultato1 << endl;
    }
    if (delta < 0) {
        cout << "impossibile" << endl;
    }
}

int main() {
    float a, b, c;
    cout << "Dammi il valore 1" << endl;
    cin >> a;
    cout << "Dammi il valore 2" << endl;
    cin >> b;
    cout << "Dammi il valore 3" << endl;
    cin >> c;

    risoluzione2(a, b, c);

    return 0;
}