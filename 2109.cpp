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

using namespace std;

using TGraph = vector<vector<int>>;

const int INF = 1e9;

void dfs(const TGraph& g, int v, vector<int>& order, vector<int>& depth, vector<int>& pos) {
    pos[v] = order.size();
    order.push_back(v);
    for (int to : g[v]) {
        if (depth[to] != INF) {
            continue;
        }

        depth[to] = depth[v] + 1;
        dfs(g, to, order, depth, pos);
        order.push_back(v);
    }
};

class TTree {
public:
    vector<int> Tree; // Id
    const vector<int>& Values;
    const vector<int>& Pos;

    TTree(const vector<int>& values, const vector<int>& pos)
        : Tree(values.size() * 4, INF)
        , Values(values)
        , Pos(pos)
    {
        Build(Values);
    }

    void Build(const vector<int>& values) {
        Tree.assign(4 * values.size(), INF);
        build(1, 0, values.size());
    }

    void build(int v, int l, int r) {
        if (l >= r) {
            return;
        }

        if (l + 1 == r) {
            Tree[v] = Values[l];
            return;
        }

        int m = (l + r) / 2;
        build(2 * v, l, m);
        build(2 * v + 1, m, r);
        int left = Tree[2 * v];
        int right = Tree[2 * v + 1];
        if (Pos[left] < Pos[right]) {
            Tree[v] = left;
        } else {
            Tree[v] = right;
        }
    }

    int GetMin(int v, int tl, int tr, int l, int r) {
        if (tl >= tr) {
            return INF;
        }

        if (tl + 1 == tr) {
            return Tree[v];
        }

        if (tl == l && tr == r) {
            return Tree[v];
        }

        int m = (tl + tr) / 2;

        if (r <= m) {
            return GetMin(2 * v, tl, m, l, r);
        }
        if (l >= m) {
            return GetMin(2 * v + 1, m, tr, l, r);
        }

        int left = GetMin(2 * v, tl, m, l, m);
        int right = GetMin(2 * v + 1, m, tr, m, r);
        if (Pos[left] < Pos[right]) {
            return left;
        } else {
            return right;
        }
    }
};

int main() {

    ios::sync_with_stdio(false);
    cin.tie();

    int n, q;
    cin >> n;
    TGraph g(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> q;
    vector<pair<int, int>> queries;
    for (int i = 0; i < q; i++) {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        queries.push_back({l,r});
    }

    vector<int> order;
    vector<int> depth(n, INF);
    depth[0] = 0;
    vector<int> pos(n, INF);

    dfs(g, 0, order, depth, pos);

    TTree tree(order, depth);

    vector<int> mins(n - 1, INF);
    for (int i = 0; i < n - 1; i++ ) {
        int left = pos[i];
        int right = pos[i + 1];
        if (left > right) {
            swap(left, right);
        }
        mins[i] = tree.GetMin(1, 0, order.size(), left, right + 1);
    }

    TTree tree2(mins, depth);

    for (const pair<int, int>& p : queries) {
        if (n == 1 || p.first == p.second) {
            cout << p.first + 1 << "\n";
            continue;
        }
        int idx = tree2.GetMin(1, 0, mins.size(), p.first, p.second);
        cout << idx  + 1 << "\n";
    }
    return 0;
}
