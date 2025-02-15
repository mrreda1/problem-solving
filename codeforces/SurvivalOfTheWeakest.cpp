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
nxtseq(T &x);
template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 0;
const string iofile = "";

void solve() {
    ll n = nxt<int>(), mod = 1e9 + 7;
    vector<ll> a(n);
    nxtseq(a), sort(all(a));
    while (n-- > 1) {
        priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<array<ll, 3>>> pq;
        vector<ll> weak(n);
        for (int i = 0; i < n; i++) {
            pq.push({a[i] + a[i + 1], i, i + 1});
        }
        for (int i = 0; i < n; i++) {
            weak[i] = pq.top()[0];
            array<ll, 2> w = {pq.top()[1], pq.top()[2]};
            pq.pop();
            if (w[1] < n) {
                pq.push({a[w[0]] + a[w[1] + 1], w[0], w[1] + 1});
            }
        }
        ll rem = weak[0] / mod;
        for (int i = 0; i < n; i++) {
            weak[i] -= mod * rem;
        }
        a = weak;
    }
    cout << a[0];
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
