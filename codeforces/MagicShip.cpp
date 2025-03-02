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
    array<ll, 2> init, dest;
    nxtseq(init), nxtseq(dest);
    ll n = nxt<ll>(), l = 0, r = 1e18;
    vector<array<ll, 2>> prfx(n + 1, {0, 0});
    for (int i = 1; i <= n; i++) {
        prfx[i] = prfx[i - 1];
        char x = nxt<char>();
        prfx[i][0] += x == 'R' ? 1 : x == 'L' ? -1 : 0;
        prfx[i][1] += x == 'U' ? 1 : x == 'D' ? -1 : 0;
    }
    while (l < r) {
        ll days = l + (r - l) / 2;
        array<ll, 2> ship = {
            init[0] + prfx[n][0] * (days / n) + prfx[days % n][0],
            init[1] + prfx[n][1] * (days / n) + prfx[days % n][1]};
        if (abs(ship[0] - dest[0]) + abs(ship[1] - dest[1]) > days) {
            l = days + 1;
        } else {
            r = days;
        }
    }
    cout << (l == 1e18 ? -1 : l);
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
