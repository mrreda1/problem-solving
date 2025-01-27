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
const string iofile = "wormsort";

void solve() {
    ll n = nxt<int>(), m = nxt<int>(), res = LLONG_MAX, mx = 0;
    vector<int> cows(n + 1);
    vector<map<int, ll>> worms(n + 1);
    generate(1 + all(cows), nxt<int>);

    while (m--) {
        ll a = nxt<int>(), b = nxt<int>(), w = nxt<int>();
        worms[a][b] = max(worms[a][b], w);
        worms[b][a] = max(worms[b][a], w);
    }
    for (int i = 1; i <= n; i++) {
        if (cows[i] != i) {
            mx = 0;
            vector<bool>visited(n + 1, 0);
            function<void(int, ll)> search = [&](int x, ll mn) {
                for (auto [c, w] : worms[x]) {
                    if (c == i) {
                        mx = max(mx, min(mn, w));
                    } else if (!visited[c]) {
                        visited[c] = true;
                        search(c, min(mn, w));
                    }
                }
            };
            search(cows[i], LLONG_MAX);
            res = min(res, mx);
        }
    }
    cout << (res == LLONG_MAX ? -1 : res);
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
