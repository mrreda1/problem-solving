#include <iostream>
#include <stack>

using namespace std;

void solve() {
    int n, i;
    stack<int> stk;
    cin >> n;
    long long a[n];
    for (i = 0; i < n; i++) {
        cin >> a[i];
        while (!stk.empty() && a[i] > a[stk.top()])
            stk.pop();
        cout << ((!stk.empty())?(stk.top()+1):(-1)) << ' ';
        stk.push(i);    
    }
    cout << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
