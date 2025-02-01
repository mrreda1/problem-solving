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

const bool T = false;     // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    array<ll, 3> devices;
    array<priority_queue<ll, vector<ll>, greater<ll>>, 2> mouses;
    nxtseq(devices);
    ll m = nxt<int>(), cnt = 0, cost = 0;
    while (m--) {
        ll price = nxt<int>();
        mouses[nxt<string>() == "PS/2"].push(price);
    }
    for (int type = 0; type < 2; type++) {
        for (int i = 0; i < devices[type] && !mouses[type].empty(); i++) {
            cnt++;
            cost += mouses[type].top();
            mouses[type].pop();
        }
    }
    while (!mouses[1].empty()) {
        mouses[0].push(mouses[1].top());
        mouses[1].pop();
    }
    for (int i = 0; i < devices[2] && !mouses[0].empty(); i++) {
        cnt++;
        cost += mouses[0].top();
        mouses[0].pop();
    }
    cout << cnt << ' ' << cost;
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
