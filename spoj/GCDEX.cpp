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

const int MAX_N = 1e6;
ll phi[MAX_N + 1];

void solve(ll n) {
    ll ans = 0;
    ll m = sqrt(n);
    for (ll d = 1; d <= m; d++) {
        ll a = n / (d + 1) + 1;
        ll b = n / d;
        ans += d * phi[b];
        a = max(a, m + 1);
        if (a > b) continue;
        ll cnt = b - a + 1;
        ll sum_d = (a + b) * cnt / 2;
        ans += sum_d * phi[d];
    }
    ans -= n * (n + 1) / 2;
    cout << ans;
}

void precompute() {
    iota(phi, phi + MAX_N + 1, 0);
    for (int i = 2; i <= MAX_N; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= MAX_N; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    for (int i = 2; i <= MAX_N; i++) {
        phi[i] += phi[i - 1];
    }
}

void IOSetter();
void TCGetter();

int main() { // Don't touch it, compile with "_DEBUG" flag
    precompute();
    IOSetter();
    TCGetter();
}

void TCGetter() {
    while (true) {
        int n = nxt<int>();
        if (n == 0) {
            break;
        }
        solve(n);
        cout << '\n';
    }
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
