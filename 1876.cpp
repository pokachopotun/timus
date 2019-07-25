#include <iostream>

using namespace std;

int main() {

    int a, b;
    const int n = 40;
    cin >> a >> b;
    int res = n + 2 * (a - n) + 2 * (n - 1) + 1;
    int res1 = n + 2 * b;
    cout << max(res, res1) << endl;
    return 0;
}
    
    
