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

void Result(int res) {
    cout << res << endl;
    exit(0);
}

void BFS(int s, const vector<vector<int>>& g, vector<char>& used, set<pair<int, int>>& edges) {
    used[s] = 1;
    queue<int> q;
    q.push(s);

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        for (int to : g[v]) {
            edges.insert({min(v,to), max(v,to)});
            if (used[to]) {
                continue;
            }

            q.push(to);
            used[to] = 1;
        }
    }
};

int main() {
    int x,y;
    vector<vector<int>> g(1001);
    while (cin >> x >> y) {
        g[x].push_back(y);
        g[y].push_back(x);
    }

    vector<char> used(1001);
    for (int i = 0; i < g.size(); i++) {
        if (used[i]) {
            continue;
        }

        set<pair<int, int>> e;
        BFS(i, g, used, e);

        if (e.size() & 1) {
            Result(0);
        }
    }

    Result(1);

    return 0;
}
