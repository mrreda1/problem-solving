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
    int n = nxt<int>();
    vector<ll> a(n), prfx(n), prfxmex(n), taken(n, 0);
    vector<array<ll, 2>> sorted_a(n);
    nxtseq(a), reverse(all(a)), prfx = a;
    if (n == 1) {
        cout << a[0];
        return;
    }
    for (int i = 0; i < n; i++) {
        sorted_a[i] = {a[i], i};
    }
    sort(all(sorted_a));
    for (int i = 1; i < n; i++) {
        prfx[i] += prfx[i - 1];
    }
    if (sorted_a.back()[1] == 0) {
        prfxmex[0] = sorted_a[n - 2][1];
    } else {
        prfxmex[0] = sorted_a[n - 1][1];
    }
    taken[0] = 1;
    for (int i = 1, ptr = n - 1; i < n; i++) {
        prfxmex[i] = prfxmex[i - 1];
        taken[i] = 1;
        if (taken[prfxmex[i]]) {
            while (ptr >= 0 && taken[sorted_a[ptr][1]]) {
                ptr--;
            }
            if (ptr < 0) {
                prfxmex[i] = -1;
                break;
            }
            prfxmex[i] = sorted_a[ptr][1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (prfxmex[i] == -1) {
            while (i < n) {
                cout << prfx[i++] << ' ';
            }
            return;
        }
        if (a[i] < a[prfxmex[i]]) {
            cout << prfx[i] + a[prfxmex[i]] - a[i] << ' ';
        } else {
            cout << prfx[i] << ' ';
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
