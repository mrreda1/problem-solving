#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

using namespace std;
template <typename T> T nxt();
template <typename T> class is_iterable {
  public:
    template <typename U>
    static auto test(U *u) -> decltype(u->begin(), u->end(), true_type{});
    template <typename> static false_type test(...);
    static constexpr bool value =
        !is_same<T, string>::value && decltype(test<T>(nullptr))::value;
};
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x);
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x);
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p);
template <typename Itr> void nxtseq(Itr begin, Itr end);

using ld = long double;
using ll = long long;
using llu = unsigned long long;

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?
const int MOD = 998244353;

#define mul_mod(a, b) ((((a) % MOD) * ((b) % MOD)) % MOD)
#define add_mod(a, b) ((((a) % MOD) + ((b) % MOD)) % MOD)
#define sub_mod(a, b) ((((a) % MOD) - ((b) % MOD)) % MOD)

ll pow_mod(ll b, ll p) {
    ll res = 1;
    b %= MOD;
    while (p > 0) {
        if (p & 1)
            res = res * b % MOD;
        b = b * b % MOD;
        p >>= 1;
    }
    return res;
}
ll inv_mod(ll x) {
    return pow_mod(x % MOD, MOD - 2);
}
ll div_mod(ll x, ll y) {
    return mul_mod(x, inv_mod(y));
}

void solve() {
    ll n = nxt<int>(), maxn = 1e6 + 1, res = 0;
    vector<vector<int>> gifts(n);
    vector<int> freq(maxn, 0);
    for (int i = 0; i < n; i++) {
        int k = nxt<int>();
        gifts[i].resize(k);
        for (int j = 0; j < k; j++) {
            cin >> gifts[i][j];
            freq[gifts[i][j]]++;
        }
    }
    for (int i = 0; i < n; i++) {
        ll p = 0;
        for (int j = 0; j < gifts[i].size(); j++) {
            p = add_mod(p, div_mod(freq[gifts[i][j]], n));
        }
        res = add_mod(res, div_mod(p, gifts[i].size()));
    }
    cout << div_mod(res, n);
}

void precompute() {
}

void IOSetter();
void TCGetter();

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompute();
    IOSetter();
    TCGetter();
}

void TCGetter() {
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
};

void IOSetter() {
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
};

template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
template <typename T>
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
template <typename Itr> void nxtseq(Itr begin, Itr end) {
    for (Itr itr = begin; itr < end; ++itr) {
        nxtseq(*itr);
    }
}
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p) {
    nxtseq(p.first);
    nxtseq(p.second);
}
