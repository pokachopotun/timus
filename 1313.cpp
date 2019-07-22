#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector< vector<int> > a(n, vector<int>(n, 0));
	for( int i = 0; i < n; i++ ) {
		for( int j =0 ; j < n; j ++ ) {
			cin >> a[i][j];
		}
	}
	for ( int i = 0; i < n; i++ ) {
		for( int j = 0; j <= i; j++ ) {
			cout << a[i - j][j] << " ";
		}
	}
	
	for( int j = 1; j < n; j++ ) {
		for ( int i = 0; i < n - j; i++ ) {
			cout << a[n  - 1 - i][j + i] << " ";
		}
	}
	cout << endl;
	return 0;
}
