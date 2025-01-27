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
const string iofile = "convention2";

void solve() {
    int n = nxt<int>(), time = 0, res = 0;
    vector<array<int, 3>> cows(n);
    priority_queue<array<int, 3>> waiting;
    while (n--) {
        cows[n] = {n, nxt<int>(), nxt<int>()};
    }
    sort(all(cows), [](const array<int, 3> &x, const array<int, 3> &y) {
        return x[1] < y[1];
    });
    for (auto itr = cows.begin(); !(itr == cows.end() && waiting.empty());) {
        if (waiting.empty()) {
            waiting.push(*itr++);
        }
        auto cow = waiting.top();
        res = max(res, time - cow[1]);
        time = max(time, cow[1]) + cow[2];
        waiting.pop();

        while (itr != cows.end() && (*itr)[1] <= time) {
            waiting.push(*itr++);
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
