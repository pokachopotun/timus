#include <iostream>
#include <map>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    map<char, vector<string>> a;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        char c = s.front();
        a[c].push_back(s);
    }
    string s;
    cin >> s;
    const vector<string>& v = a[s.front()];
    for (const string& x : v) {
        cout << x << endl;
    }
}
