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

const bool T = true;     // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll n = nxt<ll>(), l = nxt<ll>(), r = nxt<ll>(), k = l, res;
    vector<ll> a(n + 1), v(n + 1, 0);
    map<ll, ll> mp;
    nxtseq(1 + all(a));
    for (ll i = 1; i <= n; i++) {
        v[i] = v[i - 1] ^ a[i];
    }
    ll b = v[n], c = 0;
    if (!(n & 1)) c = v[n / 2];
    function<ll(ll)> search = [&](ll m) -> ll {
        ll res;
        if (m <= n) 
            return v[(ll) m];
        if (mp.count(m))
            return mp[m];
        if (m & 1LL) {
            res = b ^ c;
        } else {
            res = b ^ search(m / 2) ^ c;
        }
        mp[m] = res;
        return res;
    };
    if (k <= n) {
        res = a[(ll) k];
    } else {
        ll m = k / 2;
        res = search(m);
    }
    cout << res;
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
