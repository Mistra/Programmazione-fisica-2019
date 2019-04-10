#include <iostream>

using namespace std;

void coeff(int v[], const int n);

void stampa(int a[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void coeff_2(int v[], const int n) {
    for (int i = 0; i < n; i++) {
        int derivata = v[i] * (n - 1 - i);
        v[i] = derivata;
    }
    int temp = v[n - 1];
    for (int i = n - 1; i > 0; i--) {
        v[i] = v[i - 1];
    }
    v[0] = temp;
}
int main() {
    const int dim = 4;
    int v[dim] = {4, 4, 3, 2};
    coeff(v, dim);
    coeff_2(v, dim);
    stampa(v, dim);
    coeff_2(v, dim);
    stampa(v, dim);
}

void coeff(int v[], const int n) {
    int d[n];
    for (int i = 0; i < n; i++) {
        int derivata = v[i] * (n - 1 - i);
        d[(i + 1) % n] = derivata;
    }
    stampa(d, n);
}
