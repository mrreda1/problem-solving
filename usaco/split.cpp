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
const string iofile = "split";

void solve() {
    ll n = nxt<int>(), res = LLONG_MAX;
    vector<array<ll, 2>> point(n), suffmnmx(n);
    nxtseq(point);

    for (int t = 0; t < 2; t++) {
        sort(all(point));
        suffmnmx[n - 1][0] = suffmnmx[n - 1][1] = point[n - 1][1];
        for (int i = n - 2; i >= 0; i--) {
            suffmnmx[i][0] = min(point[i][1], suffmnmx[i + 1][0]);
            suffmnmx[i][1] = max(point[i][1], suffmnmx[i + 1][1]);
        }
        res = min(res, (suffmnmx[0][1] - suffmnmx[0][0]) *
                           (point[n - 1][0] - point[0][0]));
        ll mnmx[]{point[0][1], point[0][1]};
        for (int i = 0; i <= n - 2; i++) {
            mnmx[0] = min(mnmx[0], point[i][1]);
            mnmx[1] = max(mnmx[1], point[i][1]);
            ll area = (point[i][0] - point[0][0]) * (mnmx[1] - mnmx[0]) +
                      (suffmnmx[i + 1][1] - suffmnmx[i + 1][0]) *
                          (point[n - 1][0] - point[i + 1][0]);
            res = min(res, area);
        }
        for (int i = 0; i < n; i++) {
            swap(point[i][0], point[i][1]);
        }
    }
    cout << (suffmnmx[0][1] - suffmnmx[0][0]) *
                    (point[n - 1][1] - point[0][1]) - res;
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
