#include <iostream>
#include <stack>

using namespace std;

string superReducedString(string s) {
    stack<char> stk;
    for (int i = 0; s[i]; i++) {
        if (!stk.empty() && stk.top() == s[i]) {
            stk.pop();
        } else {
            stk.push(s[i]);
        }
    }
    if (stk.empty()) {
        return "Empty String";
    }
    s[stk.size()] = 0;
    s = s.substr(0, stk.size());
    while (!stk.empty()) {
        s[stk.size() - 1] = stk.top();
        stk.pop();
    }
    return s;
}

int main() {
    string s = "aaabccddd";
    cout << superReducedString(s);
}
