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
    ll n = nxt<int>(), m = nxt<int>(), res = 1e10;
    vector<vector<int>> edges(n), scc;
    vector<int> sccid(n, -1);
    while (m--) {
        int u = nxt<int>() - 1, v = nxt<int>() - 1;
        edges[u].push_back(v);
        edges[v].push_back(u);
    }
    for (int st = 0, id = -1; st < n; st++) {
        if (sccid[st] != -1)
            continue;
        stack<int> pending({st});
        scc.push_back({st}), sccid[st] = ++id;
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop();
            for (int neighbor : edges[current]) {
                if (sccid[neighbor] == -1) {
                    sccid[neighbor] = id;
                    scc[id].push_back(neighbor);
                    pending.push(neighbor);
                }
            }
        }
        sort(all(scc[id]));
    }
    if (sccid[0] == sccid[n - 1]) {
        cout << 0;
        return;
    }
    int nc = scc.size();
    vector<vector<int>> distance(2, vector<int>(nc, INT_MAX));
    for (int x = 0; x < 2; x++) {
        int st = sccid[x * (n - 1)];
        for (int i = 0; i < nc; i++) {
            for (int v : scc[i]) {
                auto u = lower_bound(all(scc[st]), v + 1);
                if (u != scc[st].end()) {
                    distance[x][i] = min(distance[x][i], abs(*u - v));
                }
                if (u != scc[st].begin()) {
                    distance[x][i] = min(distance[x][i], abs(*prev(u) - v));
                }
            }
        }
    }
    for (int i = 0; i < nc; i++) {
        res = min(res, ll(distance[0][i]) * ll(distance[0][i]) +
                           ll(distance[1][i]) * ll(distance[1][i]));
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
