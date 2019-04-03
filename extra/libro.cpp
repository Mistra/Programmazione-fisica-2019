#include <cstring>
#include <fstream>
#include <iostream>

using namespace std;

/*  Creare una struct PERSONA con i campi: cognome, nome
    Creare una struct LIBRO contente i campi: autore (di tipo Persona), titolo,
   anno Realizzare le funzioni:
    - stampa libro e stampa autore
    - confronto anno tra due libri

    Creare il main che popoli un array di libri chiamato Biblioteca,
    leggendo gli elementi con i relativi campi file input_libri.txt

    Proporre all'utente un menu per
    1- stampa di tutti i libri letti e inseriti nell'array
    2- ordina alfabeticamente i libri secondo il titolo
    3- ordina alfabeticamente i libri secondo cognome, nome dell'autore (e
   successivamente per titolo) 4- ordina per anno (dal pi� nuovo al pi� vecchio)
    5- Esci

    Ciascuna delle opzioni deve essere realizzata da una funzione apposita
*/
const int MAX_S = 100;  // dimensione massima dei campi stringa
const int MAX_A = 5;    // dimensione massima dell'array di Autori
const int MAX_L = 100;  // dimensione massima dell'array di Libri

struct Persona {
    char cognome[MAX_S];
    char nome[MAX_S];
};

struct Libro {
    Persona autore;
    char titolo[MAX_S];
    int anno;
};

void stampaPersona(Persona p) { cout << p.cognome << " " << p.nome << endl; }

void stampaLibro(Libro l) {
    cout << "Autore: " << l.autore.cognome << " " << l.autore.nome << endl;
    ;
    // stampaPersona(l.autore); // non si pu� mettere l'istruzione in un cout
    // perch� la funzione � void (stampa al suo interno)
    cout << "Titolo: " << l.titolo << endl
         << "Anno: " << l.anno << endl
         << endl;
}

void stampaBiblioteca(Libro l[], int N) {
    for (int i = 0; i < N; i++) stampaLibro(l[i]);
}

// restituisce true se l1 � pi� recente di l2, false altrimenti
bool recente(Libro l1, Libro l2) {
    if (l1.anno > l2.anno) return true;
    // non occorre else, se arriva qui � perch� non � entrato nell'if
    // (altrimenti sarebbe uscito con return)
    return false;
}

// ordina un array di libri per titolo
void ordinaPerTitolo(Libro l[], int N) {
    Libro temp;  // variabile per lo scambio
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (strcmp(l[i].titolo, l[j].titolo) >
                0) {  // significa che l[j] viene prima di l[i], quindi vanno
                      // scambiati nell'array
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
}

// ordina un array di libri per autore (cognome, nome) e successivamente per
// titolo
void ordinaPerAutore(Libro l[], int N) {
    Libro temp;  // variabile per lo scambio
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (strcmp(l[i].autore.cognome, l[j].autore.cognome) >
                0) {  // significa che l[j] viene prima per cognome di l[i],
                      // quindi vanno scambiati nell'array
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            } else if (strcmp(l[i].autore.cognome, l[j].autore.cognome) == 0 &&
                       strcmp(l[i].autore.nome, l[j].autore.nome) >
                           0) {  // significa che l[j] e l[i] hanno cognome
                                 // uguale ma l[j] viene prima per nome di l[i],
                                 // quindi vanno scambiati nell'array
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            } else if (strcmp(l[i].autore.cognome, l[j].autore.cognome) == 0 &&
                       strcmp(l[i].autore.nome, l[j].autore.nome) == 0 &&
                       strcmp(l[i].titolo, l[j].titolo) >
                           0) {  // significa che l[j] e l[i] hanno cognome e
                                 // nome uguale ma l[j] viene prima per titolo
                                 // di l[i], quindi vanno scambiati nell'array
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
}

// ordina un array di libri per anno
void ordinaPerAnno(Libro l[], int N) {
    Libro temp;  // variabile per lo scambio
    for (int i = 0; i < N; i++)
        for (int j = i; j < N; j++)
            if (recente(l[j],
                        l[i])) {  // significa che l[j] viene prima di l[i],
                                  // quindi vanno scambiati nell'array
                temp = l[i];
                l[i] = l[j];
                l[j] = temp;
            }
}

int main() {
    Libro biblioteca[MAX_L];
    int i = 0;
    int scelta;
    char temp[2];  // lettura caratteri inutili
    int dimB;      // dimensione effettiva dell'array biblioteca

    /*
    Persona autori[MAX_A];

    int dimA; // dimensione effettiva array di autori letti da file
    // lettura autori dal file degli autori
    ifstream fa;
    fa.open("input_autori.txt");

    if(fa.fail()){
        cout << "ERRORE apertura file";
        return 0;
    }

    while(!fa.eof() && i < MAX_A){
        fa.getline(autori[i].cognome, MAX_S, ',');
        fa.getline(autori[i].nome, MAX_S, '\n');
        i++;
    }
    dimA = i; // reale dimensione dell'array di autori

    fa.close();
    */

    // lettura libri dal file dei libri
    ifstream fl;
    fl.open("input_libri.txt");

    if (fl.fail()) {
        cout << "ERRORE apertura file";
        return 0;
    }

    while (!fl.eof() && i < MAX_L) {
        fl.getline(biblioteca[i].autore.cognome, MAX_S,
                   ',');  // lettura cognome autore, fino alla "virgola"
        fl.getline(biblioteca[i].autore.nome, MAX_S,
                   '\n');  // lettura nome autore, fino alla nuova linea
        fl.getline(biblioteca[i].titolo, MAX_S,
                   '\n');  // lettura titolo libro, fino alla nuova linea
        fl >> biblioteca[i].anno;  // lettura anno libro, essendo un intero
                                   // occorre leggerlo con >> anzich� getline

        // lettura "a vuoto" del trattino separatore nel file e degli "a capo"
        // precedente e successivo, vengono salvati in una variabile temporanea
        // inutilizzata
        fl.getline(temp, 1, '\n');
        fl.getline(temp, 1, '-');
        fl.getline(temp, 1, '\n');

        i++;  // elemento successivo della biblioteca per passare al prossimo
              // libro
    }
    dimB = i;  // reale dimensione dell'array di autori
    fl.close();

    do {
        cout << "MENU \n1.Stampa biblioteca \n2.Ordina per titolo \n3.Ordina "
                "per autore \n4.Ordina per anno \n5.Esci"
             << endl;
        cin >> scelta;

        switch (scelta) {
            case 1:
                stampaBiblioteca(biblioteca, dimB);
                break;
            case 2:
                ordinaPerTitolo(biblioteca, dimB);
                break;
            case 3:
                ordinaPerAutore(biblioteca, dimB);
                break;
            case 4:
                ordinaPerAnno(biblioteca, dimB);
                break;
            case 5:
                cout << "Arrivederci";
                break;
            default:
                cout << "Scelta non prevista";
        }
    } while (scelta != 5);

    return 0;
}
