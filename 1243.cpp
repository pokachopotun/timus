#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string s;
    cin >> s;
    reverse(s.begin(), s.end());
    vector<long long> a;
    vector<long long> r;
    for(char c : s) {
        a.push_back(static_cast<long long>(c - '0'));
    }
    long long cur = 1;
    for(long long i = 0; i < a.size(); i++) {
        r.push_back(cur);
        cur = ( cur * 10ll ) % 7ll;
    }
    long long ans = 0;
    for(long long i = 0; i < a.size(); i++) {
        ans = (ans + ( r[i] * a[i] ) % 7ll ) % 7ll;
    }
    cout << ans % 7ll;
    return 0;
}       
