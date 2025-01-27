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
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x);
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 0;
const string iofile = "rental";

void solve() {
    ll n = nxt<ll>(), m = nxt<ll>(), r = nxt<ll>(), res = 0;
    vector<ll> cow(n + 1, 0), rent(r + 1, 0);
    vector<array<ll, 2>> store(m + 1), buy(m + 1);

    store[m] = {ll(1e14), 0};
    generate(1 + all(cow), nxt<ll>);
    for (int i = 0; i < m; i++) {
        generate(all(store[i]), nxt<ll>);
    }
    generate(1 + all(rent), nxt<ll>);

    sort(all(cow)), sort(1 + all(rent), greater<ll>());
    sort(all(store), [](array<ll, 2> a, array<ll, 2> b) { return a[1] > b[1]; });

    buy = store;
    buy[0][1] *= buy[0][0];
    for (int i = 1; i <= n; i++) {
        cow[i] += cow[i - 1];
    }
    for (int i = 1; i <= r; i++) {
        rent[i] += rent[i - 1];
    }
    for (int i = 1; i <= m; i++) {
        buy[i][0] += buy[i - 1][0];
        buy[i][1] = buy[i - 1][1] + store[i][1] * store[i][0];
    }
    for (int i = 0; i <= min(n, r); i++) {
        ll g = cow[n] - cow[i],
           j = lower_bound(all(buy), g,
                           [](array<ll, 2> x, ll v) { return x[0] < v; }) -
               buy.begin();
        res = max(res, rent[i] + buy[j][1] - store[j][1] * (buy[j][0] - g));
    }
    cout << res;
}

int main() {
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
