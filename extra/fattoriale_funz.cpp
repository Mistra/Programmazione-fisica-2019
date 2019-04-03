/*  Scrivere due funzioni che calcolino N!, dove N viene preso come parametro:
    una in modo iterativo, una in modo ricorsivo
    Scrivere il main che esegua entrambe le funzioni con un valore preso da
   input
*/

#include <iostream>

using namespace std;

// dato N, calcola N! in modo iterativo
int fattoriale(int n) {
    int f = 1;  // inizializzazione indispensabile per il primo giro del for
    int i;

    for (i = 1; i <= n; i++) f = f * i;

    return f;
}

// dato N, calcola N! in modo ricorsivo
int fattoriale_ric(int n) {
    if (n >= 1)  // caso ricorsivo: f(n) = f(n-1)*n
        return fattoriale_ric(n - 1) * n;
    else  // caso base n = 1
        return 1;
}

int main() {
    int numero;

    cout << "Inserisci un numero ";
    cin >> numero;

    if (numero >= 0) {
        cout << "funzione iterativa: " << numero << "! = " << fattoriale(numero)
             << endl;
        cout << "funzione ricorsiva: " << numero
             << "! = " << fattoriale_ric(numero) << endl;
    } else
        cout << "Errore";

    return 0;
}
