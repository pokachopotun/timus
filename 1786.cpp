#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;



int Cost(int a, int b) {
    if (islower(a) && islower(b) || isupper(a) && isupper(b)) {
        return a == b ? 0 : 5;
    }

    if (isupper(a) && islower(b)) {
        return tolower(a) == b ? 5 : 10;
    }

    if (islower(a) && isupper(b)) {
        return toupper(a) == b ? 5 : 10;
    }
    return 0;
}

int Cost(const string& s, int l, int r) {
    static const string t("Sandro");
    int sum = 0;
    for (int i = l; i < r; ++i) {
        sum += Cost(s[i], t[i - l]);
    }
    return sum;
}

int main() {

    string s;
    cin >> s;
    int res = 1000;
    for (int i = 0; i < s.size(); i++) {
        if (i + 6 <= s.size()) {
            res = min(res, Cost(s, i, i + 6));
        }
    }
    cout << res << endl;
}
