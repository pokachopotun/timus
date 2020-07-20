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
#include <string>
#include <tuple>

using namespace std;

using TGraph = vector<vector<int>>;

const int INF = 1e9;

class Solution {
public:
    const TGraph& g;
    vector<int> stack;
    vector<int> pos;
    vector<char> used;
    vector<vector<int>> result;
    map<pair<int,int>, int> usedEdges;

    Solution(const TGraph& graph)
        : g(graph)
    {
        pos.assign(g.size(), INF);
        used.assign(g.size(), 0);
        for (int v = 0; v < g.size(); ++v) {
            for (int to : g[v]) {
                pair<int, int> id = GetEdgeId({v, to});
                usedEdges[id]++;
            }
        }
    }

    pair<int, int> GetEdgeId(const pair<int, int>& src) {
        return {min(src.first, src.second), max(src.first, src.second)};
    }

    void Print(const string& name, const vector<int>& vec) {
        cout << name << " ";
        for (int x : vec) {
            cout << x << " ";
        }
        cout << endl;
    }

    void dfs(int v) {
        used[v] = 1;
        pos[v] = stack.size();
        stack.push_back(v);
        for (int to : g[v]) {
            pair<int, int> id = GetEdgeId({v, to});
            if (used[to]) {
                if (pos[to] != INF && usedEdges[id] > 0) {
                    //Print("pos", pos);
                    result.push_back({stack.begin() + pos[to], stack.end()});
                    usedEdges[id] -= 2;
                }
                continue;
            }

            usedEdges[id] -= 2;
            dfs(to);
        }
        pos[v] = INF;
        stack.pop_back();
    }

    void Do() {
        for (int v = 0; v < g.size(); v++) {
            if (used[v]) {
                continue;
            }
            dfs(v);
        }
    }

    void PrintResult() {
        cout << result.size() << endl;
        for (const vector<int>& res : result) {
            cout << res.size() << " ";
            for (int x : res) {
                cout << x + 1 << " ";
            }
            cout << endl;
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie();

    int n, m;
    cin >> n >> m;
    TGraph g(n);
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    Solution solve(g);
    solve.Do();
    solve.PrintResult();

    return 0;
}
