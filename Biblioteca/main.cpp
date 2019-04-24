#include <cstring>
#include <fstream>
#include <iostream>
using namespace std;

struct Persona {
    char nome[30];
    char cognome[30];
};

struct Libro {
    char titolo[30];
    int anno;
    Persona autore;
};

Libro leggilibro() {
    Libro libro;
    cout << "inserisci libro:" << endl;
    cout << "dammi il titolo:" << endl;
    cin.getline(libro.titolo, 30);
    cout << "dammi l'anno:" << endl;
    cin >> libro.anno;
    cin.get();
    cout << "nome autore:" << endl;
    cin.getline(libro.autore.nome, 30);
    cout << "cognome autore:" << endl;
    cin.getline(libro.autore.cognome, 30);
    return libro;
}

void stampalibro(Libro libro) {
    cout << "il titolo e': " << libro.titolo << endl;
    cout << "l'anno e': " << libro.anno << endl;
    cout << "autore: " << libro.autore.nome << " " << libro.autore.cognome
         << endl;
}

int menu() {
    cout << "cosa vuoi fare?" << endl;
    cout << "opzione 1: inserisci libro" << endl;
    cout << "opzione 2: salva" << endl;
    cout << "opzione 3: carica" << endl;
    cout << "opzione 4: visualizza tutto" << endl;
    cout << "opzione 5: esci" << endl;
    int scelta;
    cin >> scelta;
    cin.get();
    return scelta;
}

void visualizzatutto(Libro biblioteca[], int max) {
    cout << endl;
    for (int i = 0; i < max; i++) {
        stampalibro(biblioteca[i]);
        cout << endl;
    }
    cout << endl;
}

void salvatutto(Libro biblioteca[], int max) {
    ofstream salva;
    salva.open("Biblioteca/biblioteca.txt");
    if (salva.fail()) {
        cout << "Errore!";
        salva.close();
        return;
    }
    int i;
    for (i = 0; i < max; i++) {
        salva << biblioteca[i].titolo << ",";
        salva << biblioteca[i].anno << ",";
        salva << biblioteca[i].autore.nome << ",";
        salva << biblioteca[i].autore.cognome;
        if (i != max - 1) {
            salva << endl;
        }
    }
    salva.close();
}

int caricatutto(Libro biblioteca[], int max) {
    ifstream carica;
    carica.open("Biblioteca/biblioteca.txt");
    if (carica.fail()) {
        cout << "Errore!";
        carica.close();
        return 0;
    }
    int i;
    for (i = 0; !carica.eof(); i++) {
        carica.getline(biblioteca[i].titolo, 30, ',');
        carica >> biblioteca[i].anno;
        carica.get();
        carica.getline(biblioteca[i].autore.nome, 30, ',');
        carica.getline(biblioteca[i].autore.cognome, 30);
    }
    carica.close();
    return i;
}

void ordinatitolo(Libro biblioteca[], int max) {
    for (int i = 0; i < max; i++) {
    }
}

int main() {
    Libro biblioteca[100];
    int indice = 0;
    while (true) {
        switch (menu()) {
            case 1: {
                biblioteca[indice] = leggilibro();
                indice++;
            }; break;
            case 2:
                salvatutto(biblioteca, indice);
                break;

            case 3:
                indice = caricatutto(biblioteca, 100);
                break;

            case 4:
                visualizzatutto(biblioteca, indice);
                break;

            case 5:
                return 0;

            default:
                cout << "scelta sbagliata!" << endl;
                break;
        }
    }
    return 0;
}

/*void boh(char titolo[], char autore[], int max) {
    ofstream out;
    out.open("progetto/testo.txt");
    out << titolo << "," << autore << endl;
    out.close();
}

void boh2(char titolo[], char autore[], int max) {
    ifstream in;
    in.open("progetto/testo.txt");
    if (in.fail()) {
        cout << "Errore!";
        in.close();
        return;
    }
    in.getline(titolo, max, ',');
    in.getline(autore, max);
    in.close();
}
*/