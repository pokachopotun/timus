#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <unordered_set>
#include <unordered_map>
#include <vector>

using namespace std;

const int inf = 1000;

void PrintResult(const auto& number) {
    for (const auto& p : number) {
        const string& name = p.first;
        const int num = p.second;
        cout << name << " ";
        if (num == inf) {
            cout << "undefined";
        } else {
            cout << num;
        }
        cout << endl;
    }
}

int main() {

    int n;
    cin >> n;

    map<string, int> number;
    map<string, vector<int>> person2team;
    vector<vector<string>> team(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 3; j++) {
            string x;
            cin >> x;
            team[i].push_back(x);
            person2team[x].push_back(i);
            number[x] = inf;
        }
    }

    if (number.find("Isenbaev") == number.end()) {
        PrintResult(number);
        return 0;
    }

    number["Isenbaev"] = 0;

    queue<string> q;
    q.push("Isenbaev");
    while (!q.empty()) {
        string v = q.front();
        q.pop();
        int cur = number[v];
        for (int tid : person2team[v]) {
            for (const string& name : team[tid]) {
                int& num = number[name];
                if (num == inf) {
                    num = min(num, cur + 1);
                    if (name != v) {
                        q.push(name);
                    }
                }
            }
        }
    }

    PrintResult(number);
}
