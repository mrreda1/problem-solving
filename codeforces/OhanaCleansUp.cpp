#include <iostream>
#include <map>

using namespace std;
int main () {
    map<string, unsigned> strs;
    string str;
    int n, max = 0;
    cin >> n;
    while (n--) {
        cin >> str;
        if (strs.find(str) == strs.end()) {
            strs[str] = 1;
        } else {
            strs[str]++;
        }
        if (strs[str] > max) {
            max = strs[str];
        }
    }
    cout << max;
}
