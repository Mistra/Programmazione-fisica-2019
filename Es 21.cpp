#include <cmath>
#include <iostream>

using namespace std;
int massimo(int v[], int dim) {
    int massimo = v[0];
    for (int i = 0; i < dim && v[i] >= 0; i++) {
        if (v[i] > massimo) {
            massimo = v[i];
        }
    }
    return massimo;
}

int main() {
    const int dim = 100;
    int v[dim] = {1, 2, 3, 4, 5, 8, -7};
    cout << "Il massimo e':" << massimo(v, dim) << endl;
    return 0;
}