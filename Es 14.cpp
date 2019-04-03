#include <iostream>

using namespace std;

int somma_divisori(int n) {
    int somma = 0;
    for (int i = 1; i < n; ++i) {
        if ((n % i) == 0) somma += i;
    }
    return somma;
}

int perfetto(int n) {
    if (somma_divisori(n) < n) {
        return -1;
    }

    if (somma_divisori(n) == n) {
        return 0;
    }

    return 1;
}

int main() {
    int num = 0;
    cout << "Inserire un numero" << endl;
    cin >> num;

    switch (perfetto(num)) {
        case -1:
            cout << "Numero difettivo" << endl;
            break;
        case 0:
            cout << "Numero perfetto" << endl;
            break;
        case 1:
            cout << "Numero abbondante" << endl;
            break;
    }

    return 0;
}
