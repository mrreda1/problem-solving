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

ll getNum(array<int, 32> &l, array<int, 32> &r) {
    bitset<32> bits = 0;
    for (int i = 0; i < 32; i++) {
        bits[i] = !!(r[i] - l[i]);
    }
    return bits.to_ullong();
}
void solve() {
    ll n = nxt<int>();
    vector<array<int, 32>> a(n + 1, array<int, 32>{});
    vector<ll> nums(n);
    nxtseq(nums);
    array<ll, 3> res{1, n, accumulate(all(nums), 0ll, [](ll acc, ll x) { return acc | x; })};
    for (int i = 1; i <= n; i++) {
        bitset<32> bits = nums[i - 1];
        for (int j = 0; j < 32; j++) {
            a[i][j] = a[i - 1][j] + bits[j];
        }
    }
    for (ll i = 1; i <= n; i++) {
        ll l = i, r = n;
        while (l <= r) {
            ll mid = (l + r) / 2, x = getNum(a[i - 1], a[mid]);
            if (x > res[2] || (x == res[2] && mid - i < res[1] - res[0])) {
                res = {i, mid, x};
                r = mid - 1;
            } else if (x == res[2]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    cout << res[1] - res[0] + 1;
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
