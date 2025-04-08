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

const int MAXN = 1e5;
vector<int> spf(MAXN + 1, 1);

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
    int n = nxt<int>(), k = nxt<int>();
    ll ans = 0;
    map<vector<array<int, 2>>, int> freq;
    while (n--) {
        int x = nxt<int>();
        vector<array<int, 2>> divisors = getFactorization(x);
        vector<array<int, 2>> rem, invrem;
        for (int i = 0; i < divisors.size(); i++) {
            if (divisors[i][1] % k) {
                rem.push_back({divisors[i][0], divisors[i][1] % k});
                invrem.push_back({rem.back()[0], (k - rem.back()[1]) % k});
            }
        }
        ans += freq[invrem];
        freq[rem]++;
    }
    cout << ans;
}

void precompute() {
    sieve();
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
