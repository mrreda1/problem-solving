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

const bool T = 0;     // Multiple test cases?
const string iofile = ""; // I/O file?

const int MAXN = 1e7 + 1, MOD = 1e9 + 7;
vector<int> spf(MAXN, 1);
void sieve() {
    spf[0] = 0;
    for (int i = 2; i <= MAXN; i++) {
        if (spf[i] == 1) {
            for (int j = i; j <= MAXN; j += i) {
                if (spf[j] == 1) {
                    spf[j] = i;
                }
            }
        }
    }
}
vector<array<int, 2>> getFactorization(int x) {
    vector<array<int, 2>> ret;
    while (x != 1) {
        if (!ret.empty() && ret.back()[0] == spf[x]) {
            ret.back()[1]++;
        } else {
            ret.push_back({spf[x], 1});
        }
        x /= spf[x];
    }
    return ret;
}

void solve() {
    ll n, x, res = 1;
    cin >> n >> x;
    map<int, vector<int>> div_freq;
    for (int i = 0; i < n; i++) {
        vector<array<int, 2>> pfactors = getFactorization(nxt<int>());
        for (array<int, 2> factor : pfactors) {
            div_freq[factor[0]].push_back(factor[1]);
        }
    }
    for (auto [div, freq] : div_freq) {
        sort(all(freq));
        int i = freq.size() - x;
        if (i >= 0) {
            res = ll(res * pow(div, freq[i])) % MOD;
        }
    }
    cout << res;
}

void precompile() {
    sieve();
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
