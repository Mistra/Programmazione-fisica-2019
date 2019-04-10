
#include <iostream>

using namespace std;

void printer(char stringa[], int dim) {
    for (int i = 0; i < dim; i++) {
        cout << stringa[i];
    }
    cout << endl;
}

// vecchia soluzione errata
/*
void postfissi(char stringa[], int n) {
    for (int i = 0; i < n; i++) {
        char postfisso[i + 1];
        for (int j = n - 1; j > n - 1 - i; j--) {
            postfisso[j] = stringa[j];
        }
        printer(postfisso, i + 1);
    }
}
*/

// Pongo dimensione = (i + 1) per comodità
// nel ciclo interno procedo da 0 a dim
// copiando dall'n meno dim + il j-esimo elemento

void postfissi(char stringa[], int n) {
    for (int i = 0; i < n; i++) {
        int dim = i + 1;
        char postfisso[dim];
        for (int j = 0; j < dim; j++) {
            postfisso[j] = stringa[(n - dim) + j];
        }
        printer(postfisso, dim);
    }
}

void prefissi(char stringa[], int n) {
    for (int i = 0; i < n; i++) {
        char prefisso[i + 1];
        for (int j = 0; j < i + 1; j++) {
            prefisso[j] = stringa[j];
        }
        // printer(prefisso, i + 1);
        postfissi(prefisso, i + 1);
    }
}

int main() {
    const int dim = 6;
    char stringa[dim] = {'s', 't', 'e', 'l', 'l', 'a'};
    prefissi(stringa, dim);
    // postfissi(stringa, dim);
    return 0;
}