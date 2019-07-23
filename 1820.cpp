#include <iostream>

using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    int a = n / k;
    int r = n % k;
    if ( a == 0 ) 
        cout << 2 << endl;
    else 
        cout << 2 * n / k + int(( 2 * n % k) > 0) << endl;
    return 0;
}
