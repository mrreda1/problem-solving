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

const bool T = 0;                // Multiple test cases?
const string iofile = "moocast"; // I/O file?

void solve() {
    int n = nxt<int>(), res = 0;
    vector<vector<int>> edges(n + 1), cows(n + 1, vector<int>(3));
    nxtseq(1 + all(cows));
    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            int distance = ceil(sqrt(pow(cows[i][0] - cows[j][0], 2) +
                                pow(cows[i][1] - cows[j][1], 2)));
            if (cows[i][2] >= distance) {
                edges[i].push_back(j);
            }
            if (cows[j][2] >= distance) {
                edges[j].push_back(i);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        vector<bool> visited(n + 1, false);
        queue<int> pending({i});
        while (!pending.empty()) {
            int cow = pending.front();
            pending.pop(), visited[cow] = true;
            for (int neighbor : edges[cow]) {
                if (!visited[neighbor]) {
                    pending.push(neighbor);
                }
            }
        }
        res = max(accumulate(all(visited), 0), res);
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
