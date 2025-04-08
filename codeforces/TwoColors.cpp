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

const bool T = 1;     // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll n, m, res = 0;
    cin >> n >> m;
    vector<ll> colors(m), rev(m), suff(m);
    for (int i = 0; i < m; i++) {
        colors[i] = min(nxt<ll>(), n - 1);
    }
    sort(all(colors));
    for (int i = m - 1; i >= 0; i--) {
        rev[i] = n - colors[i] - 1;
    }
    suff[m - 1] = rev[m - 1];
    for (int i = m - 2; i >= 0; i--) {
        suff[i] = suff[i + 1] + rev[i];
    }
    ll ptr = 1;
    while (ptr < m && rev[ptr] > colors[0]) {
        ptr++;
    }
    for (ll i = 0; i < m - 1; i++) {
        if (rev[m - 1] >= colors[i]) {
            continue;
        }
        ptr = min(ptr, m - 1);
        while (ptr > i && rev[ptr] < colors[i]) {
            ptr--;
        }
        if (rev[ptr] >= colors[i]) {
            ptr++;
        }
        ptr = max(i + 1, ptr);
        res += 2 * (colors[i] * (m - ptr) - suff[ptr]);
    }
    cout << res;
}

void precompile() {
}

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompile();
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
