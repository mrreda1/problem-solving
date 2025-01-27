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
const string iofile = "";

void solve() {
    string s = nxt<string>();
    vector<bool> bit(s.size());
    for (int i = 0; i < bit.size(); i++) {
        bit[i] = s[i] == '1';
    }
    int q = nxt<int>(), x;
    array<multiset<int>, 2> len;
    vector<set<int>> chkpoint(2, set<int>({-1, static_cast<int>(s.size())}));
    for (int i = 0; i < s.size(); i++) {
        chkpoint[bit[i]].insert(i);
    }
    for (int i = 0; i < 2; i++) {
        for (set<int>::iterator itr = chkpoint[!i].begin();
             next(itr) != chkpoint[!i].end(); itr = next(itr)) {
            len[i].insert(*next(itr) - *itr - 1);
        }
    }
    while (q--) {
        x = nxt<int>() - 1;
        bool f = bit[x];
        bit[x] = !bit[x];
        array<int, 2> p[2] = {
            {*prev(chkpoint[f].lower_bound(x)),
             *next(chkpoint[f].lower_bound(x))},
            {*prev(chkpoint[!f].lower_bound(x)), *chkpoint[!f].lower_bound(x)}};
        chkpoint[f].erase(x), chkpoint[!f].insert(x);
        len[!f].erase(len[!f].find(p[0][1] - x - 1)),
            len[!f].erase(len[!f].find(x - p[0][0] - 1));
        len[f].insert(p[1][1] - x - 1), len[f].insert(x - p[1][0] - 1);
        len[!f].insert(p[0][1] - p[0][0] - 1),
            len[f].erase(len[f].find(p[1][1] - p[1][0] - 1));
        cout << max(*len[0].rbegin(), *len[1].rbegin()) << ' ';
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
