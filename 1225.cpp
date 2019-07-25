#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long n;
    cin >> n;
    vector< vector< long long> > d(max(n, 2ll), vector<long long>(2,0));
    d[0][0] = d[0][1] = d[1][1] = d[1][0] = 1;
    for(long long i = 2; i < n; i++) {
        for(long long j = 0; j < 2; j++) {
            long long t = (j + 1) % 2;
            d[i][j] = d[i - 2][t] + d[i - 1][t];
        }
    }
    cout << d[n - 1][0] + d[n - 1][1] << endl;
    return 0;
} 
