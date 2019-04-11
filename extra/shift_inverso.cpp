#include <iostream>

using namespace std;

void stampa(int a[], const int n) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

void shift_avanti(int a[], unsigned dim) {
    // sol. pulita ma poco efficiente
    for (unsigned i = 0; i < dim; i++) {
        int temp = a[i];
        a[i] = a[0];
        a[0] = temp;
    }
}

void inverti(int a[], unsigned const int dim) {
    for (int i = 0; i < dim / 2; i++) {
        int opp = dim - 1 - i;

        int temp = a[i];
        a[i] = a[opp];
        a[opp] = temp;
    }
}

void shift_indietro(int a[], unsigned dim) {
    inverti(a, dim);
    shift_avanti(a, dim);
    inverti(a, dim);
}

int main() {
    int arr[4] = {1, 2, 3, 4};
    // shift_avanti(arr, 4);
    // inverti(arr, 4);
    shift_indietro(arr, 4);
    stampa(arr, 4);
}
