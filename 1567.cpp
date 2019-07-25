#include <iostream>
#include <string>

using namespace std;

int main() {
    string s;
    int cost[] = {1,2,3, 1,2,3, 1,2,3, 
                  1,2,3, 1,2,3, 1,2,3,
                  1,2,3, 1,2,3, 1,2,3};

    int sum = 0;
    getline(cin, s);
    {
        for(char c : s) {
            switch(c) {
                case ' ':
                    sum += 1;
                    break;
                case '.':
                    sum += 1;
                    break;
                case ',':
                    sum += 2;
                    break;
                case '!':
                    sum += 3;
                    break;
                default:
                    sum += cost[int(c - 'a')];
            }
        }
    }
    cout << sum << endl;
    return 0;
}
        
