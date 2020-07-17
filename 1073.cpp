#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;


const int inf = 1e9;

int main() {
    int n;
    cin >> n;
    vector<int> sq;
    for (int i = 1; i * i <= n; ++i) {
        sq.push_back(i * i);
    }
    vector<int> cnt(n + 1, inf);
    cnt[0] = 0;
    for (int i = 0; i < n; i++) {
        if (cnt[i] == inf) {
            continue;
        }
        for (int cost : sq) {
            if (i + cost >= cnt.size()) {
                continue;
            }
            cnt[i + cost] = min(cnt[i + cost], cnt[i] + 1);
        }
    }
    cout << cnt.back() << endl;
}
