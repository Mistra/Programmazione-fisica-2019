#include <cmath>
#include <iostream>

using namespace std;

float media(float v[], int dim) {
    float somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += v[i];
    }
    return somma / dim;
}

float deviazione(float v[], int dim) {
    float media = ::media(v, dim);
    float somma = 0;
    for (int i = 0; i < dim; i++) {
        somma += pow(v[i] - media, 2);
    }
    return sqrt(somma);
}

int main() {
    float v[6] = {7, 9, 3, 6, 5, 4};
    cout << "La deviazione e':" << deviazione(v, 6) << endl;
    return 0;
}