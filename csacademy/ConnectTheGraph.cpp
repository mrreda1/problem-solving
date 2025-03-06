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
    int n = nxt<int>(), m = nxt<int>();
    vector<set<int>> edges(n + 1);
    vector<array<int, 2>> cycles;
    vector<int> forest, visited(n + 1, 0);
    set<int> nodes;
    for (int i = 1; i <= n; i++) {
        nodes.insert(i);
    }
    while (m--) {
        int u = nxt<int>(), v = nxt<int>();
        edges[u].insert(v), edges[v].insert(u);
    }
    function<void(int, int)> dfs = [&](int node, int parent) {
        nodes.erase(node), visited[node] = true;
        for (int neighbor : edges[node]) {
            if (neighbor != parent) {
                if (visited[neighbor]) {
                    cycles.push_back({node, neighbor});
                    edges[neighbor].erase(node);
                } else {
                    dfs(neighbor, node);
                }
            }
        }
    };
    while (!nodes.empty()) {
        forest.push_back(*nodes.begin());
        dfs(*nodes.begin(), 0);
    }
    if (cycles.size() < forest.size() - 1) {
        cout << -1;
    } else {
        cout << forest.size() - 1 << '\n';
        for (int i = 0; i < forest.size() - 1; i++) {
            cout << cycles[i][0] << ' ' << cycles[i][1] << ' ' << forest[i]
                 << ' ' << forest[i + 1] << '\n';
        }
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
