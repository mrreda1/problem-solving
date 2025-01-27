#include <bits/stdc++.h>
#include <queue>

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
const string iofile = "";

void solve() {
    int x = nxt<int>(), n = nxt<int>();
    map<int, int> traffic{{x, 2}};
    set<int> values{0, x};

    auto getmx = [&](int pos) {
        return max(pos == x ? 0 : *next(values.find(pos)) - pos,
                   pos == 0 ? 0 : pos - *prev(values.find(pos)));
    };

    while (n--) {
        int v = nxt<int>();
        vector<map<int, int>::iterator> itr(
            {traffic.find(getmx(*(prev(values.lower_bound(v))))),
             traffic.find(getmx(*(values.lower_bound(v))))});
        for (auto x : itr) {
            if (x->second == 1) {
                traffic.erase(x);
            } else {
                x->second--;
            }
        }
        values.insert(v);
        traffic[getmx(v)]++;
        traffic[getmx(*prev(values.find(v)))]++;
        traffic[getmx(*next(values.find(v)))]++;
        cout << (--traffic.end())->first << ' ';
    }
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
