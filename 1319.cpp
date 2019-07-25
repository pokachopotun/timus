#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector< vector<int>> a(n, vector<int>(n));
    int val = 1;
    for(int j = n - 1; j >= 0; j--) {
        for(int i = 0; i + j < n; i++ ) {
            a[i][i + j] = val++;
        }
    }

    for(int i = 1; i < n; i++) {
        for(int j = 0; i + j < n; j++) {
            a[i + j][j] = val++;
        }
    }
  

    for(auto& v : a) {
        for(int x : v) {
            cout << x << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
    
