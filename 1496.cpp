#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> cnt;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cnt[s]++;
    }
    for (const auto& p : cnt) {
        const string& name = p.first;
        const int c = p.second;
        if (c > 1) {
            cout << name << endl;
        }
    }
}
