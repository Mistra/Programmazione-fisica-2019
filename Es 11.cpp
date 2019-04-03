#include <cmath>
#include <iostream>

using namespace std;

int somma_geometrica_w(int q, int n) {
    int i = 0;
    int result = 0;
    while (i <= n) {
        result += pow(q, i);
        ++i;
    }
    return result;
}

int somma_geometrica_f(int q, int n) {
    int result = 0;
    for (int i = 0; i <= n; i++) {
        result += pow(q, i);
    }
    return result;
}

int somma_geometrica_r(int q, int n) {
    if (n == 0) return pow(q, n);
    return pow(q, n) + somma_geometrica_r(q, n - 1);
}

int main() {
    int q = 5, n = 9;

    cout << "la somma geometrica_w e': " << somma_geometrica_w(q, n) << endl;
    cout << "la somma geometrica_f e': " << somma_geometrica_f(q, n) << endl;
    cout << "la somma geometrica_r e': " << somma_geometrica_r(q, n) << endl;

    return 0;
}
