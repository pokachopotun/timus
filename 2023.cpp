#include <iostream>
#include <string>

using namespace std;

int main() {
	int cnt = 0;
	int n;
	int pos = 0;
	string a[] = {"APOR", "BMS", "DGJKTW"};
	cin >> n;
	while(n--) {
		string s;
		cin >> s;
		for(int i =0 ; i < 3; i++) {
			if (a[i].find(s[0]) != string::npos) {
				cnt += abs(pos - i);
				pos = i;
			}
		}
	}
	cout << cnt;
	return 0;
}	
