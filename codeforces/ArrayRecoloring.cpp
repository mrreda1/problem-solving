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

const bool T = 1;         // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    ll n, m, res = 0;
    cin >> n >> m;
    vector<ll> a(n);
    nxtseq(a);
    if (m == 1) {
        ll max1 = *max_element(1 + all(a)) + a[0];
        ll max2 = *max_element(all(a) - 1) + a[n - 1];
        cout << max(max1, max2);
        return;
    }
    for (int i = 0; i < n; i++) {
        ll sum = a[i], l = 1, r = 1, k = m;
        vector<ll> l_a(a.begin(), a.begin() + i), r_a(a.begin() + i + 1, a.end());
        sort(rall(l_a)), sort(rall(r_a));
        if (l_a.empty()) {
            sum += accumulate(r_a.begin(), r_a.begin() + k, 0ll);
        } else if (r_a.empty()) {
            sum += accumulate(l_a.begin(), l_a.begin() + k, 0ll);
        } else {
            sum += l_a[0] + r_a[0];
            k -= 2;
            while (k--) {
                if (l >= l_a.size()) {
                    sum += accumulate(r_a.begin() + r, r_a.begin() + r + k + 1, 0ll);
                    break;
                } else if (r >= r_a.size()) {
                    sum += accumulate(l_a.begin() + l, l_a.begin() + l + k + 1, 0ll);
                    break;
                } else if (l_a[l] > r_a[r]) {
                    sum += l_a[l++];
                } else {
                    sum += r_a[r++];
                }
            }
        }
        res = max(res, sum);
    }
    cout << res;
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
