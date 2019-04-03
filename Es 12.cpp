#include <iostream>

using namespace std;

void foo(int n) {
    switch (n % 2) {
        case 0:
            cout << "Il numero e' pari" << endl;
            break;
        case 1:
            cout << "Il numero e' dispari" << endl;
            break;
    }
}

int main() {
    foo(3);
    foo(8);

    return 0;
}