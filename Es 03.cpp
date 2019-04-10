#include <iostream>

using namespace std;

int funz(int n) {
    if (n >= 0) {
        n++;

        return n;
    }
    return n * 2;
}

int main() {
    int n;
    cout << "dammi un numero n" << endl;
    cin >> n;
    cout << "il risultato è" << funz(n) << endl;

    return 0;
}
