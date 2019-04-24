#include <iostream>
using std::cout, std::endl;

int main() {
    int v[4] = {51, 63, 42, 7};
    int min;
    for (int j = 0; j < 4; j++) {
        int m = j;
        for (int i = j; i < 4; i++) {
            if (v[m] > v[i]) {
                m = i;
            }
        }
        int temp = v[j];
        v[j] = v[m];
        v[m] = temp;
    }

    for (int i = 0; i < 4; i++) {
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}