#include <iostream>

using namespace std;

void stampa(int a[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}
void somma(int v_2[], int v_1[], unsigned const int n) {
    int v_3[n];
    for (int i = 0; i < n; i++) {
        v_3[i] = v_1[i] + v_2[i];
    }
    stampa(v_3, n);
}
void prodotto(int v_2[], int v_1[], unsigned const int n) {
    int v_3[n];
    for (int i = 0; i < n; i++) {
        v_3[i] = v_1[i] * v_2[i];
    }
    stampa(v_3, n);
}
int s_prodotto(int v_2[], int v_1[], unsigned const int n) {
    int v_3[n];
    for (int i = 0; i < n; i++) {
        v_3[i] = v_1[i] * v_2[i];
    }
    int somma = 0;
    for (int i = 0; i < n; i++) {
        somma = somma + v_3[i];
    }
    return somma;
}
int main() {
    const int dim = 3;
    int a_1[dim] = {1, 2, 3};
    somma(a_1, a_1, 3);
    prodotto(a_1, a_1, 3);
    cout << s_prodotto(a_1, a_1, 3);
}