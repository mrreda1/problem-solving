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

#define mul_mod(a, b, m) ((((a) % (m)) * ((b) % (m))) % (m))
#define add_mod(a, b, m) ((((a) % (m)) + ((b) % (m))) % (m))
#define sub_mod(a, b, m) ((((a) % (m)) - ((b) % (m)) + m) % (m))

ll pow_mod(ll b, ll p, int m) {
    ll res = 1;
    b %= m;
    while (p > 0) {
        if (p & 1)
            res = res * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return res;
}
ll inv_mod(ll x) {
    return pow_mod(x, MOD - 2, MOD);
}
ll div_mod(ll x, ll y) {
    return ((x % MOD) * inv_mod(y)) % MOD;
}

void solve() {
    ll q = nxt<int>(), coefficient = 1, constant = 0;
    deque<tuple<int, int>> f;
    while (q--) {
        int t = nxt<int>();
        if (t == 0) {
            int a, b;
            cin >> a >> b;
            f.push_back({a, b});
            coefficient = mul_mod(coefficient, a, MOD);
            constant = add_mod(mul_mod(constant, a, MOD), b, MOD);
        } else if (t == 1) {
            if (f.empty()) continue;
            auto [a, b] = f.front();
            coefficient = div_mod(coefficient, a);
            constant = sub_mod(constant, mul_mod(coefficient, b, MOD), MOD);
            f.pop_front();
        } else {
            int x = nxt<int>();
            cout << add_mod(mul_mod(coefficient, x, MOD), constant, MOD) << '\n';
        }
    }
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
