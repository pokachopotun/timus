#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

int main() {

    int n;
    cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        sum[i] = sum[i - 1] + x;
    }

    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        cout << sum[b] - sum[a - 1] << endl;
    }
}
