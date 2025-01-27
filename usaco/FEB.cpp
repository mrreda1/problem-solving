#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";


void solve() {
    bool seq = false;
    array<int, 2> res;
    int n = nxt<int>(), s = -1, e = n, c = 0, a;
    string str = nxt<string>();
    if (count(all(str), 'F') == str.size()) {
        cout << str.size() << endl;
        for (int i = 0; i < str.size(); i++) {
            cout << i << endl;
        }
        return;
    }
    while (str[++s] == 'F');
    while (str[--e] == 'F');
    for (int i = s; i < e; i++) {
        c += (str[i] != 'F' && str[i] == str[i + 1]);
    }
    res = {c, s + (n - 1 - e) + c};
    seq = res[1] - res[0];
    for (int i = s; i < e; i++) {
        if (str[i] == 'F') {
            int cnt = 1;
            while (str[++i] == 'F') {
                cnt++;
            }
            res[1] += cnt + (a == str[i]);
            res[0] += !((a == str[i] && cnt & 1) || !(a == str[i] || cnt & 1));
        }
        a = str[i];
    }
    cout << (res[1] - res[0]) / (seq ? 1 : 2) + 1 << endl;
    for (int i = res[0], step = (seq ? 1 : 2); i <= res[1]; i += step) {
        cout << i << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifdef _DEBUG
    freopen("../templates/default.in", "r", stdin);
    freopen("../templates/default.out", "w", stdout);
#else
    if (iofile != "") {
        freopen((iofile + ".in").c_str(), "r", stdin);
        freopen((iofile + ".out").c_str(), "w", stdout);
    }
#endif
    if (T) {
        int t;
        cin >> t;
        while (t--) {
            solve();
            cout << '\n';
        }
    } else {
        solve();
    }
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
