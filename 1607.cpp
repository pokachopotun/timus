#include <iostream>

using namespace std;

int main() {
    int a, da, c, dc;
    cin >> a >> da >> c >> dc;
    if (a >= c) {
        cout << a << endl;
        return 0;
    }
    while (true) {
            if ( a + da <= c ) {
                a += da;
            }
            else {
                cout << c << endl;
                return 0;
            }
            if ( c - dc >= a ) {
                c -= dc;
            } else {
                cout << a << endl;
                return 0;
            }
    }
    return 0;
}
