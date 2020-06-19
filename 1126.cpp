#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <deque>

using namespace std;

const int inf = 1000;

int main() {

    int m;
    cin >> m;

    multiset<int> s;
    deque<int> q;
    while (true) {
        int x;
        cin >> x;
        if (x == -1) {
            return 0;
        }
        s.insert(x);
        q.push_back(x);
        if (q.size() > m) {
            int val = q.front();
            q.pop_front();
            auto it = s.find(val);
            if (it != s.end()) {
                s.erase(it);
            }
        }
        if (q.size() == m) {
            cout << *s.rbegin() << endl;
        }
    }
}
