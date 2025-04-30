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
using ll = long long;
using llu = unsigned long long;

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    string s, t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vector<vector<int>> memo(n, vector<int>(m, -1));
    function<void(int, int)> setLCS = [&](int i, int j) {
        if (memo[i][j] != -1) return;
        if (s[i] == t[j]) {
            memo[i][j] = 1;
            if (i + 1 != n && j + 1 != m) {
                setLCS(i + 1, j + 1);
                memo[i][j] += memo[i + 1][j + 1];
            }
        } else if (i + 1 != n && j + 1 != m) {
            setLCS(i + 1, j), setLCS(i, j + 1);
            memo[i][j] = max(memo[i + 1][j], memo[i][j + 1]);
        } else if (i + 1 != n) {
            setLCS(i + 1, j);
            memo[i][j] = memo[i + 1][j];
        } else if (j + 1 != m) {
            setLCS(i, j + 1);
            memo[i][j] = memo[i][j + 1];
        } else {
            memo[i][j] = 0;
        }
    };
    setLCS(0, 0);
    for (int i = 0, j = 0; i < n && j < m;) {
        if (s[i] == t[j]) {
            cout << s[i];
            i++, j++;
        } else if (i + 1 != n && j + 1 != m) {
            (memo[i + 1][j] > memo[i][j + 1] ? i : j)++;
        } else {
            (i + 1 != n ? i : j)++;
        }
    }
}

void precompute() {
}

void IOSetter();
void TCGetter();

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompute();
    IOSetter();
    TCGetter();
}

void TCGetter() {
    int t = T ? nxt<int>() : 1;
    do {
        solve();
    } while (--t && cout << '\n');
};

void IOSetter() {
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
};

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
