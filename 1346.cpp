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

enum ELastOp {
    None = 0,
    More = 1,
    Less = 2,
    Eq = 3,
    Any = 4
};

ELastOp Compare(ELastOp lastOp, int prev, int cur, vector<int>& add, vector<int>& old) {
    if (prev == cur) {
        int val = min(add.back(), old.back()) + 1;
        add.push_back(val);
        old.push_back(val);
        return ELastOp::Eq;
    }

    ELastOp op = ELastOp::None;
    if (prev < cur) {
        op = ELastOp::More;
    } else {
        op = ELastOp::Less;
    }

    int newAdd = min(add.back(), old.back()) + 1;
    bool acceptable = lastOp == op || lastOp == ELastOp::None;
    int newOld = min(add.back(), old.back() + int(!acceptable));

    add.push_back(newAdd);
    old.push_back(newOld);

    return op;
}

int main() {

    int l, r;
    cin >> l >> r;

    int n = r - l + 1;
    vector<int> a;
    for (int i = 0;  i < n; i++) {
        int x;
        cin >> x;
        if (a.empty() || x != a.back())
            a.push_back(x);
    }

    int cnt = 0;
    ELastOp lastOp = ELastOp::None;
    vector<int> add, old;
    add.push_back(1);
    old.push_back(1);
    for (int i = 1; i < a.size(); i++) {
        lastOp = Compare(lastOp, a[i - 1], a[i], add, old);
    }
/*
    for (int x : add) {
        cout << x << " ";
    }
    cout << endl;

    for (int x : old) {
        cout << x << " ";
    }
    cout << endl; */

    cout << min(old.back(), add.back()) << endl;

    return 0;
}
