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

void grid_parse(const vector<string> &grid, vector<vector<int>> &edges) {
    int n = grid.size(), m = grid[0].size();
    function<void(int, int)> link = [&edges](int u, int v) {
        edges[v].push_back(u);
        edges[u].push_back(v);
    };
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                continue;
            }
            bool up = i != 0 && grid[i - 1][j] == '.',
                 down = i != (n - 1) && grid[i + 1][j] == '.',
                 left = j != 0 && grid[i][j - 1] == '.',
                 right = j != (m - 1) && grid[i][j + 1] == '.';
            if (up) {
                link(i * m + j, (i - 1) * m + j);
            }
            if (down) {
                link(i * m + j, (i + 1) * m + j);
            }
            if (left) {
                link(i * m + j, i * m + j - 1);
            }
            if (right) {
                link(i * m + j, i * m + j + 1);
            }
        }
    }
}
void dfs(int node, vector<bool> &visited, const vector<vector<int>> &edges) {
    for (int neighbor : edges[node]) {
        if (!visited[neighbor]) {
            visited[neighbor] = true;
            dfs(neighbor, visited, edges);
        }
    }
}
void solve() {
    int n = nxt<int>(), m = nxt<int>(), scc = 0;
    vector<string> grid(n);
    vector<vector<int>> edges(n * m);
    vector<bool> visited(n * m, false);
    nxtseq(grid);
    grid_parse(grid, edges);
    for (int i = 0; i < n * m; i++) {
        if (!(grid[i / m][i % m] == '#' || visited[i])) {
            visited[i] = true, scc++;
            dfs(i, visited, edges);
        }
    }
    cout << scc;
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
