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

const bool T = false;     // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll n = nxt<ll>(), m = nxt<ll>(), q = nxt<ll>(), v = 0;
    vector<ll> a(n), b(m), fj(m - n + 1, 0);
    nxtseq(a), nxtseq(b);
    for (int i = 0; i < n; i++) {
        fj[0] += b[i] * (i & 1 ? 1 : -1);
        v += a[i] * (i & 1 ? -1 : 1);
    }
    for (int i = 1, sign = n & 1 ? -1 : 1; i < m - n + 1; i++) {
        fj[i] = -(fj[i - 1] + b[i - 1]) + b[i - 1 + n] * sign;
    }
    sort(all(fj));
    function<ll(ll)> getnearest = [&fj](ll v) {
        vector<ll>::iterator itr = lower_bound(all(fj), -v);
        itr -= (itr == fj.end());
        return min(abs(*itr + v), abs(*(itr - (itr != fj.begin())) + v));
    };
    cout << getnearest(v) << '\n';
    while (q--) {
        ll l = nxt<ll>(), r = nxt<ll>(), x = nxt<ll>();
        v += ((r - l + 1) & 1) * (l & 1 ? 1 : -1) * x;
        cout << getnearest(v) << '\n';
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
