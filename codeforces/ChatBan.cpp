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
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};
template <typename T>
typename enable_if<!(!is_same<T, string>::value && is_iterable<T>::value)>::type
nxtseq(T &x); template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x);
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = true;      // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll k = nxt<ll>(), x = nxt<ll>(), a = (k * (k + 1)) / 2;
    if (a > x) {
        cout << ll(ceil((-1 + sqrt(1 + 8 * x)) / 2));
    } else if (k * (k - 1) > 2 * (x - a)) {
        cout << ll(2 * k - floor((1 + sqrt(1 + 4 * (k * (k - 1) - 2 * (x - a)))) / 2));
    } else {
        cout << 2 * k - 1;
    }
}


int main() { // Don't touch it, compile with "_DEBUG" flag
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
template <typename T>
typename enable_if<!(!is_same<T, string>::value && is_iterable<T>::value)>::type
nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
template <typename T1, typename T2> void nxtseq(pair<T1, T2> &p) {
    cin >> p.first >> p.second;
}
