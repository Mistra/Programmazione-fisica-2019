#include <iostream>

using namespace std;

int powW(int a, int b) {
    int i = 1;
    int risultato = 1;
    while (i <= b) {
        risultato *= a;
        ++i;
    }
    return risultato;
}

int powF(int a, int b) {
    int risultato = 1;
    for (int i = 1; i <= b; ++i) {
        risultato *= a;
    }
    return risultato;
}

int powR(int a, int b) {
    if (b == 0) {
        return 1;
    } else {
        return a * powR(a, b - 1);
    }
}

int main() {
    int a, b;
    cout << "Dammi a" << endl;
    cin >> a;

    cout << "Dammi b" << endl;
    cin >> b;

    if (powW(a, b) == powF(a, b) && powF(a, b) == powR(a, b)) {
        cout << "Tutto va come deve andare, o per lo meno cosi' dicono" << endl;
    }

    return 0;
}