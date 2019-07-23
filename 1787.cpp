#include <iostream>

using namespace std;

int main() {
    int k, n;
    int s = 0;
    cin >> k >> n;
    for( int i = 0; i < n; i++ ) {
        int x;
        cin >> x;
        s += x;
        s -= k;
        if ( s < 0 ) 
            s = 0;
    }
    cout << s << endl;
    return 0;
}

