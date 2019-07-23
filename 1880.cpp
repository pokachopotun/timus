#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> a;
    for(int k =0 ; k < 3; k++) {
        int n;
        cin >> n;
        int x;
        for( int i= 0; i < n; i++) {
            cin >> x;
            a[x]++;
        }
    }
    int cnt = 0;
    for(const auto& p : a) {
        cnt += int(p.second == 3);
    }
    cout << cnt << endl;
    return 0;
}
