#include <iostream>
#include <vector>
#include <string>

using namespace std

int main() {
    vector<pair<int, string>> a = {
        {5, "few"}
      , {10, "several"}
      , {20, "pack"}
      , {50, "lots"}
      , {100, "horde"}
      , {250, "throng"}
      , {500, "swarm"}
      , {1000, "zounds"}
      , {5000, "legion"}
    };
    int n;
    cin >> n;
    for(const auto& p : a) {
        if(p.first > n) {
            cout << p.second << endl;
            return 0;
        }
    }
    return 0;
}

    
