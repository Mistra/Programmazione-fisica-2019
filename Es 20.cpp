// Creare una funzione che legga una sequenza di interi positivi
// terminata da un numero negativo e memorizzi gli elementi (positivi) letti in
// un array. Gli elementi positivi letti possono essere in numero compreso tra 0
// e 50 (estremi inclusi). La funzione deve restituire la media degli elementi
// memorizzati nell’array. Creare il main nel quale viene richiamata la funzione
// precedente.

#include <iostream>

using namespace std;

float media(int v[], const int n) {
    float el_letti = 0;
    for (int i = 0; i < n; i++) {
        el_letti = el_letti + v[i];
    }
    return el_letti / n;
}

int riempimento(int v[], const int max) {
    cout << "Dammi una sequenza di numeri positivi terminati da un negativo:"
         << endl;
    for (int i = 0; i < max; ++i) {
        cin >> v[i];
        if (v[i] < 0) return i;
    }
    return max;
}

int main() {
    // dichiaro massimo nel main
    const int massimo = 50;
    int vett[massimo] = {0};

    // riempimento modifica "vett", e restituisce la dim. effettiva
    const int dim = riempimento(vett, massimo);

    // media viene chiamata nel main
    cout << "la media vale: " << media(vett, dim) << endl;

    return 0;
}
