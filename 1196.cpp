#include <iostream>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    unordered_set<int> a;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        a.insert(x);
    }
    int k;
    cin >> k;
    int cnt = 0;
    for (int i = 0; i < k; i++) {
        int x;
        cin >> x;
        if (a.find(x) != a.end()) {
            ++cnt;
        }
    }
    cout << cnt << endl;
}
