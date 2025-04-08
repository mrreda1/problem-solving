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
using ll = long long;

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

ll getNegRes(ll n, ll k, ll p, ll u, int freq);
ll getPosRes(ll n, ll k, ll p, ll u, int freq) {
    ll steps = (u - p) / k, res, pp = p;
    p += steps * k;
    res = steps + (p == u ? 0 : min(u - p, 1 + min(n, p + k) - u));
    if (freq >= 4) {
        return res;
    }
    return min(res, ll(ceil((n - pp) / double(k))) + getNegRes(n, k, n, u, freq + 1));
}
ll getNegRes(ll n, ll k, ll p, ll u, int freq) {
    ll steps = (p - u) / k, res, pp = p;
    p -= steps * k;
    res = steps + (p == u ? 0 : min(p - u, 1 + u - max(1ll, p - k)));
    if (freq >= 4) {
        return res;
    }
    return min(res, ll(ceil((pp - 1.0) / k)) + getPosRes(n, k, 1, u, freq + 1));
}
void solve() {
    ll n, k, p, u;
    cin >> n >> k >> p >> u;
    if (p < u) {
        ll add = (p - 1) / k + !!((p - 1) % k);
        cout << min(getPosRes(n, k, p, u, 0), add + getPosRes(n, k, 1, u, 0));
    } else {
        ll add = (n - p) / k + !!((n - p) % k);
        cout << min(getNegRes(n, k, p, u, 0), add + getNegRes(n, k, n, u, 0));
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
