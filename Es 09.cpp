#include <iostream>

using namespace std;

int sommaW(int a, int b) {
    int i = a;
    int risultato = 0;
    while (i <= b) {
        risultato += i;
        ++i;
    }
    return risultato;
}

int sommaF(int a, int b) {
    int risultato = 0;
    for (int i = a; i <= b; ++i) {
        risultato += i;
    }
    return risultato;
}

int sommaR(int a, int b) {
    if (b == a) {
        return a;
    } else {
        return b + sommaR(a, b - 1);
    }
}

int main() {
    int a, b;
    cout << "Dammi a" << endl;
    cin >> a;

    cout << "Dammi b" << endl;
    cin >> b;

    if (a > b) {
        swap(a, b);
    }

    if (sommaW(a, b) == sommaF(a, b) && sommaF(a, b) == sommaR(a, b)) {
        cout << "Tutto va come deve andare, o per lo meno cosi' dicono" << endl;
    }

    return 0;
}