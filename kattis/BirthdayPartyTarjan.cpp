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

void solve() {
    int p, c, u, v;
    for (cin >> p >> c; p | c; cin >> p >> c) {
        if (!c) {
            cout << (p > 1 ? "YES" : "NO") << '\n';
            continue;
        }
        int bridges = 0;
        vector<int> parent(p, -1), low(p, INT_MAX), disc(p, INT_MAX);
        vector<vector<int>> edges(p);
        for (int i = 0; i < c; i++) {
            cin >> u >> v;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        function<void(int)> dfs = [&](int node) {
            static int timer = 0;
            low[node] = disc[node] = timer++;
            for (int neighbor : edges[node]) {
                if (disc[neighbor] == INT_MAX) {
                    parent[neighbor] = node;
                    dfs(neighbor);
                    low[node] = min(low[node], low[neighbor]);
                    if (low[neighbor] > disc[node]) {
                        bridges++;
                    }
                } else if (neighbor != parent[node]){
                    low[node] = min(low[node], disc[neighbor]);
                }
            }
        };
        dfs(0);
        for (int time : disc) {
            if (time == INT_MAX) {
                bridges = 1;
                break;
            }
        }
        cout << (bridges ? "YES" : "NO") << '\n';
    }
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
