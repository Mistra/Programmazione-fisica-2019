#include <cmath>
#include <iostream>

using namespace std;

float media(float v[], int dim) {
    float somma = 0;
    int i = 0;
    for (; i < dim && v[i] >= 0; i++) {
        somma += v[i];
    }
    return somma / i;
}

int main() {
    float v[50] = {1, 2, 3, 4, 5, 8, -7};
    cout << "La media e':" << media(v, 50) << endl;
    return 0;
}