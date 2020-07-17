#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>
#include <ios>

using namespace std;


void drop(const vector<int>& sum, int& hold, int k) {

    int l = 0;
    int r = hold;

    while (l + 1 < r) {
        int m = (l + r) / 2;
        if (sum[hold] - sum[m] <= k) {
            r = m;
        } else {
            l = m;
        }
    }

    hold = l;
}

int main() {

    ios::sync_with_stdio(false);
    cin.tie();

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> w(n + 1), sum(n + 1);

    queue<int> q;

    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        w[i] = x;
        sum[i] = sum[i - 1] + x;
    }

    for (int i = 1; i <= m; ++i) {
        int x;
        cin >> x;
        q.push(x);
    }

    int hold = 0;
    int t = 0;
    while (!q.empty()) {
        if (n - hold < q.front() - t) {
            t += n - hold;
            cout << t << endl;
            return 0;
        }
        t++;
        hold += q.front() - t;
        t = q.front();
        q.pop();
        drop(sum, hold, k);
    }

    cout << t + n - hold << endl;

    return 0;
}
