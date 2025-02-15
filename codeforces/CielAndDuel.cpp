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
using ll = int64_t;

const bool T = false;     // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    int n = nxt<int>(), m = nxt<int>(), res = 0;
    array<vector<int>, 2> jiro;
    vector<int> fox(m);
    while (n--) {
        jiro[nxt<string>() == "DEF"].push_back(nxt<int>());
    }
    nxtseq(fox), sort(all(fox)), sort(all(jiro[0]));
    while (n < min(m, int(jiro[0].size()))) {
        int sum = 0;
        for (int j = n++, i = m - 1; j >= 0; j--, i--) {
            if (fox[i] < jiro[0][j]) {
                cout << res;
                return;
            }
            sum += fox[i] - jiro[0][j];
        }
        res = max(res, sum);
    }
    multiset<int> ciel(all(fox));
    if (fox.size() > jiro[0].size() + jiro[1].size()) {
        for (int card : jiro[1]) {
            multiset<int>::iterator itr = ciel.upper_bound(card);
            if (itr == ciel.end()) {
                cout << res;
                return;
            }
            ciel.erase(itr);
        }
        int sum = 0;
        for (int i = jiro[0].size() - 1; i >= 0; i--) {
            if (*ciel.rbegin() < jiro[0][i]) {
                cout << res;
                return;
            }
            sum += *ciel.rbegin() - jiro[0][i];
            ciel.erase(prev(ciel.end()));
        }
        for (int x : ciel) {
            sum += x;
        }
        res = max(res, sum);
    }
    cout << res;
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
