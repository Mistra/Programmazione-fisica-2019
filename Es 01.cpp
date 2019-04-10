#include <iostream>

using namespace std;

int main() {
    int a;
    int b;
    int c;
    cout << "dammi il valore di a" << endl;
    cin >> a;
    cout << "dammi il valore di b" << endl;
    cin >> b;
    cout << "dammi il valore di c" << endl;
    cin >> c;

    int m = a;

    if (m > b) {
        m = b;
    }
    if (m > c) {
        m = c;
    }

    cout << "il minimo è: " << m << endl;
    return 0;
}