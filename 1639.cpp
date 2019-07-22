nclude <iostream>

using namespace std;

int val = 0;

void f(int a, int b) {
    if ( a > b ) {
        swap(a,b);
    }
    if ( a > 1 ) {
        val += b;
        f(a - 1, b);
    } else {
        if(b > 1) {
            val += a;
            f(a, b - 1);
        }
    }
}

int main() {
    int n,m;
    cin >> n >> m;
    int val;
    f(n,m);
    if (val % 2 == 1)
        cout << "[:=[first]" << endl;
    else
        cout << "[second]=:]" << endl;
    return 0;
}
