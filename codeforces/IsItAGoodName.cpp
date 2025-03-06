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

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    int n = nxt<int>(), i, lst;
    vector<string> names(n), team;
    vector<bool> frq(n, 0), vsub;
    nxtseq(names);
    string x = nxt<string>();
    if (count(all(x), '_') != n - 1) {
        cout << "NO";
        return;
    }
    for (i = 0, lst = -1; i < x.size(); i++) {
        if (x[i] == '_') {
            if (i - lst - 1 > 0) {
                team.push_back(x.substr(lst + 1, i - lst - 1));
            } else {
                cout << "NO";
                return;
            }
            lst = i;
        }
    }
    if (i - lst - 1 > 0) {
        team.push_back(x.substr(lst + 1, i - lst - 1));
    } else {
        cout << "NO";
        return;
    }
    vsub = vector<bool>(team.size(), 1);
    for (int i = 0; i < team.size(); i++) {
        bool invalid = true;
        for (int j = 0; j < n; j++) {
            if (names[j].find(team[i]) != string::npos) {
                frq[j] = 1, invalid = false;
            }
        }
        vsub[i] = invalid;
    }
    if (accumulate(all(vsub), 0)) {
        cout << "NO";
        return;
    }
    for (int x : frq) {
        if (!x) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void precompile() {
}

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompile();
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
