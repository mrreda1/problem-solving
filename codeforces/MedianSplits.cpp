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

bool isValid1(vector<ll> &a, ll k) {
    int n = a.size();
    ll cnt = 0, i = 0;
    for (; i < n; i++) {
        cnt += a[i] <= k;
        if (cnt >= (i + 2) / 2) {
            break;
        }
    }
    int j = i + 1;
    for (cnt = 0; j < n - 1; j++) {
        cnt += a[j] <= k;
        if (cnt >= (j - i + 1) / 2) {
            return true;
        }
    }
    return false;
}
bool isValid2(vector<ll> &a, ll k) {
    int n = a.size();
    ll cnt = 0, i = 0;
    for (; i < n; i++) {
        cnt += a[i] <= k;
        if (cnt >= (i + 2) / 2) {
            break;
        }
    }
    int j = n - 1;
    for (cnt = 0; j > i + 1; j--) {
        cnt += a[j] <= k;
        if (cnt >= (n - j + 1) / 2) {
            return true;
        }
    }
    return false;
}

bool isValid3(vector<ll> &a, ll k) {
    int n = a.size();
    ll cnt = 0, i = 0;
    for (; i < n; i++) {
        cnt += a[i] <= k;
        if (cnt >= (i + 2) / 2) {
            break;
        }
    }
    i += !(i & 1);
    int j = i + 1;
    for (cnt = 0; j < n - 1; j++) {
        cnt += a[j] <= k;
        if (cnt >= (j - i + 1) / 2) {
            return true;
        }
    }
    return false;
}
bool isValid4(vector<ll> &a, ll k) {
    int n = a.size();
    ll cnt = 0, i = 0;
    for (; i < n; i++) {
        cnt += a[i] <= k;
        if (cnt >= (i + 2) / 2) {
            break;
        }
    }
    i += !(i & 1);
    int j = n - 1;
    for (cnt = 0; j > i + 1; j--) {
        cnt += a[j] <= k;
        if (cnt >= (n - j + 1) / 2) {
            return true;
        }
    }
    return false;
}
void solve() {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    nxtseq(a);
    if (isValid1(a, k) || isValid2(a, k) || isValid3(a, k) || isValid4(a, k)) {
        cout << "YES";
        return;
    }
    reverse(all(a));
    if (isValid1(a, k) || isValid2(a, k) || isValid3(a, k) || isValid4(a, k)) {
        cout << "YES";
        return;
    }
    cout << "NO";
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
