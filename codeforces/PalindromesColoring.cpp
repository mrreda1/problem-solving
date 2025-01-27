#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ld = long double;
using ll = long long;

const bool T = 1;
const string iofile = "";

void solve() {
    int n = nxt<int>(), k = nxt<int>(), e = 0, o = 0;
    vector<int> freq('z' + 1, 0);
    while (n--) freq[nxt<char>()]++;
    for (int x : freq) {
        e += x / 2;
        o += x & 1;
    }
    if (k > o) {
        cout << max(((e - (k - o + 1) / 2) / k) * 2 + 1, (e / k) * 2);
    } else {
        cout << (e / k) * 2 + 1;
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
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
