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
    ll n = nxt<ll>(), res = 0;
    vector<int> a(n + 1);
    map<ll, ll> freq;
    freq[0] = 1, a[0] = 0;

    for (int i = 1; i <= n; i++) {
        a[i] = a[i - 1] + nxt<char>() - '0' - 1;
        freq[a[i]]++;
    }
    for (auto [_, x] : freq) {
        res += x * (x - 1) / 2;
    }
    cout << res;
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
