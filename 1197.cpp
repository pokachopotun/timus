#include <iostream>

using namespace std;

int main() {

    int dx[] = {-2, -1, 1, 2, 2, 1, -1, -2};
    int dy[] = {1,2,2,1,-1,-2,-2,-1};

    int t;
    cin >> t;
    for( int k =0 ; k < t; k++ ) {
        string s;
        cin >> s;
        int x = s[0] - 'a';
        int y = s[1] - '1';
        int cnt = 0;
        for( int i =0 ; i < 8; i++) {
            int a = x + dx[i];
            int b = y + dy[i];
            cnt += int(a >=0 && b >= 0 && a < 8 && b < 8) ;
        }
        cout << cnt << endl;
    }

    return 0;
}
