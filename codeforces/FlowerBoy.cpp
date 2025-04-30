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

const bool T = 1;         // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    int n, m, taken = 0;
    cin >> n >> m;
    vector<int> a(n), b(m);
    nxtseq(a), nxtseq(b);
    for (int x : a) {
        if (x >= b[taken]) {
            if (++taken >= b.size()) {
                break;
            }
        }
    }
    if (taken < b.size()) {
        if (m == 1) {
            cout << b[0];
            return;
        }
        vector<int> prfx(m + 1, -1), sufx(m + 1, -1);
        int res = INT_MAX;
        taken = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= b[taken]) {
                prfx[taken + 1] = i;
                if (++taken >= b.size()) {
                    break;
                }
            }
        }
        taken = m - 1;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] >= b[taken]) {
                sufx[taken] = i;
                if (--taken < 0) {
                    break;
                }
            }
        }
        for (int i = 0; i < m; i++) {
            if ((i == 0 && sufx[i + 1] != -1) ||
                (i == m - 1 && prfx[i] != -1) ||
                (prfx[i] != -1 && sufx[i + 1] != -1 && prfx[i] < sufx[i + 1])) {
                res = min(res, b[i]);
            }
        }
        cout << (res == INT_MAX ? -1 : res);
    } else {
        cout << 0;
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
