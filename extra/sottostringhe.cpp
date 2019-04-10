// data una stringa, si vuole emettere su std output
// l'insieme delle sottostringhe generate, eg.
// abc:
// abc ab bc a b c

#include <iostream>

using namespace std;

void printer(char stringa[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << stringa[i];
    }
    cout << endl;
}

void postfissi(char stringa[], int dim) {
    for (int i = 0; i < dim; ++i) {
        printer(stringa + i, dim - i);
    }
}

void prefissi(char stringa[], int dim) {
    for (int i = 0; i < dim; ++i) {
        postfissi(stringa, dim - i);
    }
}

void cursore(char stringa[], int dim, int lunghezza) {
    for (int i = 0; i <= dim - lunghezza; i++) {
        printer(stringa + i, lunghezza);
    }
}

void selettore(char stringa[], int dim) {
    for (int i = 0; i < dim; ++i) {
        cursore(stringa, dim, dim - i);
    }
}

int main() {
    const int dim = 5;
    char stringa[dim] = {'c', 'i', 'a', 'o', '!'};
    selettore(stringa, dim);
    return 0;
}