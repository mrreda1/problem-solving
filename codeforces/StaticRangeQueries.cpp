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
    ll n = nxt<ll>(), q = nxt<ll>();
    map<ll, ll> nums, prfx;
    nums[-1] = prfx[-1] = 0;
    while (n--) {
        ll l = nxt<ll>(), r = nxt<ll>(), v = nxt<ll>();
        nums[l] += v;
        nums[r] -= v;
    }
    for (auto a = nums.begin(), b = next(a); b != nums.end(); a++, b++) {
        b->second += a->second;
    }
    prfx = nums;
    for (auto a = prfx.begin(), b = next(a), x = nums.begin(); b != prfx.end();
         a++, b++, x++) {
        b->second += a->second + x->second * (b->first - a->first - 1);
    }
    while (q--) {
        ll l = nxt<ll>() - 1, r = nxt<ll>() - 1;
        auto tl = prev(nums.upper_bound(l)), tr = prev(nums.upper_bound(r));
        cout << prfx[tr->first] + tr->second * (r - tr->first) -
                    prfx[tl->first] - tl->second * (l - tl->first) << '\n';
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
