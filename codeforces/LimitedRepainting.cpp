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

const bool T = true;      // Multiple test cases?
const string iofile = ""; // I/O file?

ll kadane(const vector<ll> &a, vector<ll> &flip) {
    ll n = a.size(), mn = 0, sum = 0, res = LLONG_MIN, l, r, mnl = 0, f = 0;
    for (int i = 0; i < n; i++) {
        f = (flip[i] ? !f : f);
        sum += a[i] * (f ? -1 : 1);
        if (sum - mn > res) {
            res = sum - mn;
            l = mnl;
            r = i;
        }
        if (sum < mn) {
            mn = sum;
            mnl = i + 1;
        }
    }
    flip[l] = !flip[l];
    flip[r + 1] = !flip[r + 1];
    return res;
}
void solve() {
    ll n = nxt<ll>(), k = nxt<ll>(), res = 0;
    string str = nxt<string>();
    vector<ll> penalty(n, 0), flip(n + 1, 0);
    for (int i = 0; i < n; i++) {
        penalty[i] = nxt<ll>() * (str[i] == 'B' ? 1 : -1);
        res += (str[i] == 'B' ? penalty[i] : 0);
    }
    while (k--) {
        ll mxsub = kadane(penalty, flip);
        if (mxsub <= 0) {
            break;
        } else {
            res -= mxsub;
        }
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
