#include <iostream>

using namespace std;

int main() {
    int n = 8;

    if ((n % 3) == 0) {
        cout << n << " multiplo di 3 " << endl;
    }
    if ((n % 3) == 1) {
        cout << n << "congruo a 1 modulo 3" << endl;
    }
    if ((n % 3) == 2) {
        cout << n << "congruo a 2 modulo 3" << endl;
    }

    return 0;
}