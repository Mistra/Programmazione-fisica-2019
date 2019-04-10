#include <iostream>

using namespace std;

int foo(int cont = 1, int prev = 0) {
    int num = 0;
    cout << "Dammi un numero" << endl;
    cin >> num;
    if (num < 0) {
        return (prev / cont);
    }
    return foo(cont + 1, prev + num);
}

int main() {
    cout << "La media positiva e': " << foo() << endl;
    return 0;
}