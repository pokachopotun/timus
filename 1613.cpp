#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;


const int inf = 1e9;

int main() {
    int n;
    cin >> n;
    unordered_map<int, vector<int>> index;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (index.find(x) == index.end()) {
            index[x] = vector<int>();
        }
        index[x].push_back(i + 1);
    }
    int k;
    cin >> k;
    vector<int> res;
    for (int i = 0; i < k; ++i) {
        int l, r, x;
        cin >> l >> r >> x;
        auto it = index.find(x);
        if (it == index.end()) {
            res.push_back(0);
            continue;
        }
        const vector<int>& lst = it->second;
        auto left = lower_bound(lst.begin(), lst.end(), l);
        auto right = upper_bound(lst.begin(), lst.end(), r);
//        cout << "lst: ";
//        for (int x : lst) {
//            cout << x << " ";
//        }
//        cout << endl;
//        cout << l << " " << r  << " " << *left << " " << *right << endl;
        if ( l <= *left && *left <= r) {
            res.push_back(1);
        } else {
            res.push_back(0);
        }
    }
    for (int x : res) {
        cout << x;
    }
    cout << endl;
}
