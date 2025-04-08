#include <bits/stdc++.h>
#include <numeric>

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

const bool T = 0;                // Multiple test cases?
const string iofile = "moocast"; // I/O file?

void solve() {
    int l = 0, r = 2 * pow(25e3, 2), ans = r, n = nxt<int>();
    vector<array<int, 2>> cows(n);
    nxtseq(cows);
    while (l <= r) {
        int mid = l + (r - l) / 2;
        vector<vector<int>> edges(n);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (pow(cows[i][0] - cows[j][0], 2) +
                        pow(cows[i][1] - cows[j][1], 2) <=
                    mid) {
                    edges[i].push_back(j);
                    edges[j].push_back(i);
                }
            }
        }
        queue<int> pending({0});
        vector<bool> undiscovered(n, true);
        undiscovered[0] = false;
        while (!pending.empty()) {
            int current = pending.front();
            pending.pop();
            for (int neighbor : edges[current]) {
                if (undiscovered[neighbor]) {
                    undiscovered[neighbor] = false;
                    pending.push(neighbor);
                }
            }
        }
        if (accumulate(all(undiscovered), 0)) {
            l = mid + 1;
        } else {
            ans = mid;
            r = mid - 1;
        }
    }
    cout << ans;
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
