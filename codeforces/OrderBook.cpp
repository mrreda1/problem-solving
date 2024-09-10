#include <iostream>
#include <stack>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, s, q, p, i, c, ms = 1e5+1;
    int pb[ms] = {0}, ps[ms] = {0};
    stack<int> b;
    char d;
    cin >> n >> s;
    while (n--) {
        cin >> d >> p >> q;
        switch (d) {
            case 'B':
                pb[p] += q;
                break;
            default:
                ps[p] += q;
        }
    }
    for (i = c = 0; i < ms && c < s; i++) {
        if (ps[i]) {
            b.push(i);
            c++;
        }
    }
    while (!b.empty()) {
        cout << 'S' << ' ' << b.top() << ' ' << ps[b.top()] << '\n';
        b.pop();
    }
    for (c = 0, i = ms-1; i+1 && c < s; i--) {
        if (pb[i]) {
            cout << 'B' << ' ' << i << ' ' << pb[i] << '\n';
            c++;
        }
    }
}
