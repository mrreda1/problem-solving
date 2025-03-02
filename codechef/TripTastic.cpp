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

const bool T = true;      // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll n, m, k, l = 0, r = 1e6;
    cin >> n >> m >> k;
    vector<vector<ll>> rooms(n + 1, vector<ll>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            rooms[i][j] = nxt<ll>() + rooms[i - 1][j] + rooms[i][j - 1] -
                          rooms[i - 1][j - 1];
        }
    }
    if (rooms[n][m] <= k) {
        cout << -1;
        return;
    }
    while (l < r) {
        ll mid = l + (r - l) / 2, valid = false;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (rooms[i][j] - rooms[i][j - 1] - rooms[i - 1][j] +
                        rooms[i - 1][j - 1] &&
                    rooms[min(i + mid, n)][min(j + mid, m)] -
                            rooms[max(i - mid, 1ll) - 1][min(j + mid, m)] -
                            rooms[min(i + mid, n)][max(j - mid, 1ll) - 1] +
                            rooms[max(i - mid, 1ll) - 1]
                                 [max(j - mid, 1ll) - 1] >
                        k) {
                    r = mid;
                    valid = true;
                    break;
                }
            }
            if (valid) {
                break;
            }
        }
        if (!valid) {
            l = mid + 1;
        }
    }
    cout << l;
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
