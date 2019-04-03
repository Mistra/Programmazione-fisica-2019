/* Scrivere un programma che dato in input un orario espresso in secondi lo
   converta in ore minuti e secondi. Successivamente, migliorare il programma
   stampando le ore e i minuti solo se non risultano nulli */

#include <iostream>

using namespace std;

int main() {
    int secondi;  // input
    int h, m, s;  // orario separati

    cout << "Inserisci i secondi: ";
    cin >> secondi;
    // l'utente ha inserito il valore dei secondi

    h = secondi / 3600;
    m = (secondi % 3600) / 60;
    s = (secondi % 3600) % 60;

    if (secondi < 60)  // se meno di 60 secondi: stampo solo secondi
        cout << s << " secondi";
    else if (secondi < 3600)  // se min 3600: stampo solo min e sec
        cout << m << " minuti " << s << " secondi ";
    else  // se nessuna delle precedenti, cio� >= 3600 stampo tutto
        cout << h << " ore " << m << " minuti " << s << " secondi ";

    return 0;
}
