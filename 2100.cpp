#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    int cnt = 2 + n;
    for(int i = 0; i < n; i++) {
        string s;
        cin >> s;
        if (s.length() >= 4 && s.substr(s.length() - 4) == "+one")
            cnt++;
    }
    if (cnt == 13)
        cnt++;
    cout << cnt * 100;
    return 0;
}
