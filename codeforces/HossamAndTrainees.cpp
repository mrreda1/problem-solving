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

vector<int> primes;
void setPrimes(int MAXN) {
    vector<bool> isprime(MAXN + 1, true);
    for (int i = 2; i <= MAXN; i++) {
        if (isprime[i]) {
            primes.push_back(i);
            for (int j = 2 * i; j <= MAXN; j += i) {
                isprime[j] = false;
            }
        }
    }
}
void solve() {
    int n = nxt<int>();
    vector<int> a(n);
    vector<bool> found(primes.size(), false);
    map<int, bool> found_mp;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < primes.size(); j++) {
            if (a[i] % primes[j]) {
                continue;
            }
            if (found[j]) {
                cout << "YES";
                return;
            }
            found[j] = true;
            while (a[i] % primes[j] == 0) {
                a[i] /= primes[j];
            }
        }
        if (a[i] != 1) {
            if (found_mp[a[i]]) {
                cout << "YES";
                return;
            }
            found_mp[a[i]] = true;
        }
    }
    cout << "NO";
}

void precompute() {
    setPrimes(sqrt(1e9));
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
