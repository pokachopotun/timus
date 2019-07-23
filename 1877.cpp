#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    if ( a % 2 != 0 && b % 2 == 0 ) 
        cout << "no";
    else
        cout << "yes";
    cout << endl;
    return 0;
}
