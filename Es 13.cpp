#include <cmath>
#include <iostream>

using namespace std;

double somma(double n) {
    if (n == 0) return 4 * (pow(-1, n) / (2 * n + 1));
    return 4 * (pow(-1, n) / (2 * n + 1)) + somma(n - 1);
}

void stampa_somma(double m) {
    cout << "il risultato e': " << somma(m) << endl;
    return;
}

int main() {
    double numero = 50000;

    stampa_somma(numero);

    return 0;
}
