/* Chiedere all�utente di inserire N numeri interi,
memorizzarli in un array e poi proporre il seguente menu:
1. Ordinamento crescente,
2. Ordinamento decrescente,
3. Ricerca elemento,
4. Conta apparizioni,
5. Inverti array,
6. Esci.

Ogni opzione viene svolta da una funzione */

#include <iostream>

using namespace std;

const int MAX = 100;

void inverti(int origine[], int dim, int invertito[]) {
    int temp;
    for (int i = 0; i < dim; i++) invertito[i] = origine[i];

    for (int i = 0; i < dim / 2;
         i++) {  // lo scambio tra primo-ultimo, secondo-penultimo ecc... deve
                 // avvenire fino a met� dim/2, altrimenti l'array torna
                 // nell'ordine iniziale
        // scambio
        temp = invertito[i];
        invertito[i] = invertito[dim - i - 1];
        invertito[dim - i - 1] = temp;
    }
}

void ordina_crescente(int origine[], int dim, int ordinato[]) {
    int i, j, temp;

    // copia l'array origine in ordinato
    for (i = 0; i < dim; i++) ordinato[i] = origine[i];

    for (i = 0; i < dim; i++)
        for (j = i + 1; j < dim; j++) {
            if (ordinato[j] < ordinato[i]) {
                // scambio
                temp = ordinato[i];
                ordinato[i] = ordinato[j];
                ordinato[j] = temp;
            }
        }
    // ordinato contiene l'array ordinato
}

// anzich� riscrivere l'algoritmo di ordinamento, sfrutta ordina crescente e
// inverti
void ordina_decrescente(int origine[], int dim, int ordinato[]) {
    ordina_crescente(origine, dim, ordinato);
    // dopo l'esecuzione ordinato risulta in ordine crescente
    inverti(ordinato, dim, ordinato);
    // dopo l'esecuzione ordinato risulta in ordine decrescente
}

int conta(int origine[], int dim, int numero) {
    int i, contatore = 0;

    for (i = 0; i < dim; i++)
        if (origine[i] == numero) contatore++;

    return contatore;
}

bool cerca(int origine[], int dim, int numero) {
    int i;
    bool trovato = false;  // inizialmente non trovato

    for (i = 0; i < dim; i++)
        if (origine[i] == numero) trovato = true;
    // se non trova l'elemento, trovato non viene modificato rispetto al suo
    // valore iniziale (false), quindi restituisce false

    return trovato;
}

int main() {
    int N;  // quantit� di numeri
    int a[MAX], newa[MAX];

    int i;
    int scelta;  // scelta del menu 1-6

    int numero;  // numero da cercare/contare nelle opzioni 3 e 4

    do {
        cout << "Quanti numeri? ";
        cin >> N;
    } while (N <= 0 ||
             N > 100);  // finch� l'utente inserisce qualcosa di sbagliato
    // sicuramente N � corretto

    for (i = 0; i < N; i++) {
        cout << "Inserisci un valore ";
        cin >> a[i];
    }

    do {
        cout << "MENU " << endl
             << "1. Ordinamento crescente " << endl
             << "2. Ordinamento decrescente " << endl
             << "3. Ricerca un elemento " << endl
             << "4. Conta apparizioni " << endl
             << "5. Inverti " << endl
             << "6. Esci" << endl
             << "Opzione scelta: ";
        cin >> scelta;

        switch (scelta) {
            case 1:  // if (scelta == 1)
                // ordinamento crescente
                ordina_crescente(a, N, newa);  // newa � a ordinato
                cout << "Ordinato crescente " << endl;
                for (i = 0; i < N; i++) cout << newa[i] << " ";
                cout << endl;
                break;
            case 2:
                // ordinamento decrescente
                ordina_decrescente(a, N, newa);  // newa � a ordinato
                cout << "Ordinato decrescente " << endl;
                for (i = 0; i < N; i++) cout << newa[i] << " ";
                cout << endl;
                break;
            case 3:
                // ricerca elemento e restituisce trovato/non trovato (bool)
                cout << "Quale elemento vuoi cercare?";
                cin >> numero;
                if (cerca(a, N, numero))  // se true, trovato
                    cout << "il numero " << numero << " e' presente nell'array"
                         << endl;
                else
                    cout << "il numero " << numero
                         << " non e' presente nell'array" << endl;
                break;
            case 4:
                // conta apparizioni
                cout << "Di quale elemento vuoi contare le apparizioni?";
                cin >> numero;
                cout << "il numero " << numero << " compare "
                     << conta(a, N, numero) << " volte" << endl;
                break;
            case 5:
                // inverti
                inverti(a, N, newa);  // newa � a invertito
                cout << "Invertito " << endl;
                for (i = 0; i < N; i++) cout << newa[i] << " ";
                cout << endl;
                break;
            case 6:
                cout << "Esci";
                break;

            default:
                cout << "Errore";
                // scelta = 6; per interrompere a fronte di una scelta sbagliata
        }

    } while (scelta != 6);  // finch� l'utente non sceglie di uscire

    return 0;
}
