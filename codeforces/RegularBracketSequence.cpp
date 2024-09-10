#include <algorithm>
#include <iostream>
#include <stack>

using namespace std;
long solve (char b, string input) {
    stack<char> bk;
    bool t1 = 0;
    long cnt=0, max=0;
    for(char c : input) {
        if (c == b) {
            t1 = 0;
            bk.push(c);
            cnt++;
        }
        else if (bk.size()!=0) {
            t1 = 1;
            bk.pop();
            cnt++;
        } else {
            (max>cnt)?:(max=cnt);
            cnt = 0;
            t1 = 0;
        }
    }
    if (bk.size() && max < cnt-bk.size()) {
        max = cnt-bk.size();
    } else if (!bk.size() && t1 && max < cnt) {
        max = cnt;
    }
    return max;
}
int main () {
    string input;
    cin >> input;
    long max1 = solve('(', input);
    reverse(input.begin(), input.end());
    long max2 = solve(')', input);
    cout << min(max1, max2);
}
