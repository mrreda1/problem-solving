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
using llu = uint64_t;
using ll = int64_t;

const bool T = 1;         // Multiple test cases?
const string iofile = ""; // I/O file?

array<ll, 2> getQuarter(ll d, ll n) {
    if (n == 0) {
        return {1, 1};
    }
    ll qrtr = (1 << (2 * n)) / 4, sqqrt = sqrt(qrtr);
    array<ll, 2> res, ret;
    if (d > qrtr * 3) {
        res = {sqqrt, 0};
        ret = getQuarter(d - qrtr * 3, n - 1);
    } else if (d > qrtr * 2) {
        res = {0, sqqrt};
        ret = getQuarter(d - qrtr * 2, n - 1);
    } else if (d > qrtr) {
        res = {sqqrt, sqqrt};
        ret = getQuarter(d - qrtr, n - 1);
    } else {
        res = {0, 0};
        ret = getQuarter(d, n - 1);
    }
    return {res[0] + ret[0], res[1] + ret[1]};
}
ll getValue(ll x, ll y, ll n) {
    if (n == 0) {
        return 1;
    }
    ll dd = (1 << (2 * n)), l = sqrt(dd);
    if (x > l / 2 && y > l / 2) {
        return dd / 4 + getValue(x - l / 2, y - l / 2, n - 1);
    } else if (x > l / 2) {
        return dd / 2 + getValue(x - l / 2, y, n - 1);
    } else if (y > l / 2) {
        return 3 * dd / 4 + getValue(x, y - l / 2, n - 1);
    }
    return getValue(x, y, n - 1);
}
void solve() {
    ll n, q, d, x, y;
    char c;
    cin >> n >> q;
    while (q--) {
        cin >> c >> c;
        if (c == '-') {
            cin >> d;
            array<ll, 2> point = getQuarter(d, n);
            cout << point[1] << ' ' << point[0] << '\n';
        } else {
            cin >> x >> y;
            cout << getValue(x, y, n) << '\n';
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
