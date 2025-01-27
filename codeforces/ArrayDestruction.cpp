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

const bool T = 1;
const string iofile = "";

void solve() {
    int n = nxt<int>(), x, res;
    multiset<int> a;
    for (int i = 0; i < 2 * n; i++) {
        a.insert(nxt<int>());
    }
    for (auto itr = a.begin(); next(itr) != a.end(); ++itr) {
        multiset<int> cpy(a);
        vector<array<int, 2>> pairs;
        for (res = x = *a.rbegin() + *itr; cpy.size();) {
            auto tmp = cpy.find(x - *cpy.rbegin());
            if (tmp == cpy.end() || next(tmp) == cpy.end()) {
                break;
            }
            x = *cpy.rbegin();
            pairs.push_back({*tmp, *cpy.rbegin()});
            cpy.erase(tmp);
            cpy.erase(prev(cpy.end()));
        }
        if (!cpy.size()) {
            cout << "YES\n" << res;
            for (auto [x, y] : pairs) {
                cout << '\n' << x << ' ' << y;
            }
            return;
        }
    }
    cout << "NO";
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
