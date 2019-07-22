#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int val = n * (n + 1) / 2;
	if (val & 1)
		cout << "grimy" << endl;
	else 
		cout << "black" << endl;
	return 0;
}
