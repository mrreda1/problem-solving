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
const string iofile = "measurement";

void solve() {
    int n = nxt<int>(), g = nxt<int>(), res = 0;
    vector<array<int, 2>> days(1e6 + 1, {0, 0});
    map<int, int> cows, milk({{0, n}});
    while (n--) {
        int d = nxt<int>();
        days[d] = {nxt<int>(), nxt<int>()};
    }
    for (auto [c, d] : days) {
        if (!c) {
            continue;
        }
        cows[c] += d;
        int new_value = cows[c];
        array<int, 2> mx = {milk.rbegin()->first, milk.rbegin()->second - 1};
        milk[new_value - d]--, milk[new_value]++;
        if (!milk[new_value - d]) {
            milk.erase(new_value - d);
        }
        if (new_value > mx[0]) {
            res += (new_value - d != mx[0] || mx[1]);
        } else if (new_value == mx[0]) {
            res++;
        } else if (new_value - d == mx[0]) {
            res += !(new_value == milk.rbegin()->first && milk.rbegin()->second == 1);
        }
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
