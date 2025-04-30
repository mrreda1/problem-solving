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
const int MOD = 1e9 + 7;

#define mul_mod(a, b, m) ((((a) % (m)) * ((b) % (m))) % (m))
#define sub_mod(a, b, m) ((((a) % (m)) - ((b) % (m))) % (m))

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
    return mul_mod(x, inv_mod(y), MOD);
}

void solve() {
    ll n = nxt<int>(), sum = 1, mul = 1, quantity = 1;
    vector<array<int, 2>> factors(n);
    vector<ll> suffx(n + 1, 1), prfx(n + 1, 1);
    for (int i = 0; i < n; i++) {
        cin >> factors[i][0] >> factors[i][1];
        quantity = quantity * (factors[i][1] + 1) % MOD;
        prfx[i + 1] = prfx[i] * (factors[i][1] + 1) % (MOD - 1);
    }
    for (int i = n - 1; i >= 0; i--) {
        suffx[i] = suffx[i + 1] * (factors[i][1] + 1) % (MOD - 1);
    }
    for (int i = 0; i < n; i++) {
        array<int, 2> factor = factors[i];
        ll b = factor[0], p = factor[1];
        sum = sum * div_mod(sub_mod(pow_mod(b, p + 1), 1, MOD), b - 1) % MOD;
        mul = mul * pow_mod(b, mul_mod(p * (p + 1) >> 1, suffx[i + 1] * prfx[i], MOD - 1)) % MOD;
    }
    cout << quantity << ' ' << sum << ' ' << mul;
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
