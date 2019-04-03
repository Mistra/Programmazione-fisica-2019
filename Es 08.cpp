#include <iostream>

using namespace std;

int sommaW(int n) {
    int i = 0;
    int risultato = 0;
    while (i <= n) {
        risultato += i * i;
        ++i;
    }
    return risultato;
}

int sommaF(int n) {
    int risultato = 0;
    for (int i = 0; i <= n; ++i) {
        risultato += i * i;
    }
    return risultato;
}

int sommaR(int n) {
    if (n == 0) {
        return 0;
    } else {
        return n * n + sommaR(n - 1);
    }
}

int main() {
    int a;
    cout << "Dammi un numero" << endl;
    cin >> a;

    if (sommaW(a) == sommaF(a) && sommaF(a) == sommaR(a)) {
        cout << "Tutto va come deve andare, o per lo meno cosi' dicono" << endl;
    }

    return 0;
}