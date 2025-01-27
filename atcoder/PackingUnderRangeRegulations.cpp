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
typename enable_if<!(!is_same<T, string>::value && is_iterable<T>::value)>::type
nxtseq(T &x);
template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 1;
const string iofile = "";

void solve() {
    int n = nxt<int>();
    map<int, vector<int>> intervals;
    set<int> st;
    while (n--) {
        int x = nxt<int>();
        intervals[x].push_back(nxt<int>());
        st.insert(x);
    }
    st.insert(1e9 + 1);
    int i = *st.begin();
    priority_queue<int, vector<int>, greater<int>> pq;
    while (i <= 1e9) {
        for (int r : intervals[i])
            pq.push(r);
        pq.pop();
        if (pq.empty()) {
            i = *st.lower_bound(i + 1);
        } else if (pq.top() <= i++) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
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
