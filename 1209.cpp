#include <iostream>
#include <set>

using namespace std;

int main() {
    long n;
    long sum = 0;
    set<long> s;
    s.insert(1);
    s.insert(2);
    sum = 2;
    for(long i = 2; i < long(1e5); i++ ) {
        sum += i;
        s.insert(sum);
        if (sum > ((1 << 31) - 1 ))
            break;
    }

    cin >> n;
    while(n--) {
        long x;
        cin >> x;
        if (s.find(x) != s.end() )
            cout << 1;
        else 
            cout << 0;
        cout << " ";
    }
    cout << endl;
    return 0;
}
        
    
