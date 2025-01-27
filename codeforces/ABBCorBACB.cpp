#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 1;
const string iofile = "";


void solve() {
    vector<int> d;
    string s = nxt<string>();
    char f = s[0];
    int c = 1, mx[2]{};
    if (s.size() == 1) {
        cout << 0;
        return;
    }
    for (int i = 1; i < s.size(); i++) {
        if (s[i] == f) {
            c++;
        } else {
            d.push_back(c * (f == 'A' ? 1 : -1));
            c = 1;
        }
        f = s[i];
    }
    d.push_back(c * (f == 'A' ? 1 : -1));
    auto getMax = [&](bool t) {
        int cnt = 0;
        for (int i = t ? d.size() - 1 : 0, a = 0, b = 0; t ? i >= 0 : i < d.size();
             i += t ? -1 : 1) {
            if (d[i] > 0) {
                if (b) {
                    b = 0;
                    cnt += d[i];
                } else {
                    a = d[i];
                }
            } else {
                if (a) {
                    cnt += a;
                    a = 0;
                    b = (d[i] < -1 ? 1 : 0);
                } else {
                    b = 1;
                }
            }
        }
        return cnt;
    };
    cout << max(getMax(0), getMax(1));
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
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << endl);
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
