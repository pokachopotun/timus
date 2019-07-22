#include <iostream>
#include <vector>

using namespace std;

int val(const vector<int>& a, int pos) {
	return a[pos - 1] + a[pos] + a[pos + 1];
}

int main() {

	int n;
	cin >> n;
	vector<int> a(n);
	for(int& x : a) {
		cin >> x;
	}
	int pos = 1;
	for(int i = 1; i < a.size() - 1; i++ ) {
		if(val(a, i) > val(a,pos)) {
			pos = i;
		}
	}
	cout << val(a, pos) << " " << pos + 1 << endl;
	return 0;
}
