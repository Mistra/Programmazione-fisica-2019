#include <iostream>

using namespace std;

int sommatoriaW(int n) {
    int i = 0;
    int somma = 0;
    while (i <= n) {
        somma = somma + i;

        i = i + 2;
    }

    return somma;
}

int sommatoriaF(int n) {
    int somma = 0;
    for (int i = 0; i <= n; i = i + 2) {
        somma = somma + i;
    }

    return somma;
}

int sommatoriaR(int n) {
    if (n == 2) {
        return n;
    } else {
        return n + sommatoriaR(n - 2);
    }
}

int main() {
    int a;
    cout << "Dammi un numero" << endl;
    cin >> a;
    if (a < 0) {
        cout << "Sommatorie negative? No Thanks!" << endl;
        return 0;
    }

    if ((a % 2) == 1) {
        a--;
    }
    cout << sommatoriaW(a);
    cout << sommatoriaF(a);
    cout << sommatoriaR(a);

    if (sommatoriaW(a) == sommatoriaF(a) && sommatoriaF(a) == sommatoriaR(a)) {
        cout << sommatoriaW(a) << endl;
        cout << "Tutto va come deve andare, o per lo meno cosi' dicono" << endl;
    }

    return 0;
}