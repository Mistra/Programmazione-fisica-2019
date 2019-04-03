#include <iostream>

using namespace std;

int foo() {
    int num = 0;
    cout << "Dammi un numero" << endl;
    cin >> num;
    if (num < 0) {
        return 0;
    }
    return foo() + num;
}

int main() {
    cout << "La somma positiva e': " << foo() << endl;
    return 0;
}