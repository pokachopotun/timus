#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool check(int n) {
    int k = 6;
    vector<int> a;
    while(k--) {
        a.push_back(n % 10);
        n /= 10;
    }
    return a[0] + a[1] + a[2] == a[3] + a[5] + a[4];
}

int main() {
    string s;
    cin >> s;
    int n = stoi(s);
    if ( check(n-1) || check(n + 1) ) 
        cout << "Yes";
    else
        cout << "No";
    return 0;
}
    
