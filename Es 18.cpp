#include <iostream>

using namespace std;

int foo(int v[], int dim) {
    int contatore = 0;
    for (int i = 0; i < 6; i++) {
        if ((v[i] % 2) == 0) {
            contatore++;
        }
    }
    return contatore;
}

int main() {
    int v[6] = {7, 9, 3, 6, 5, 4};
    cout << "i numeri pari sono:" << foo(v, 6) << endl;
    return 0;
}