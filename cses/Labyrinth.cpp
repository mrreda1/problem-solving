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

map<vector<int>, char> dir{
    {{1, 0}, 'U'}, {{-1, 0}, 'D'}, {{0, -1}, 'R'}, {{0, 1}, 'L'}};

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

bool isValid(int i, int j, const vector<vector<char>> &grid,
             const vector<vector<vector<int>>> &parent) {
    int n = grid.size(), m = grid[0].size();
    return (i | j) >= 0 && i < n && j < m && grid[i][j] != '#' &&
           parent[i][j][0] == -1;
}
void solve() {
    int n = nxt<int>(), m = nxt<int>();
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<vector<int>>> parents(n, vector<vector<int>>(m, {-1, -1}));
    vector<int> src, dist;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            grid[i][j] = nxt<char>();
            if (grid[i][j] == 'A') {
                src = {i, j};
            } else if (grid[i][j] == 'B') {
                dist = {i, j};
            }
        }
    }
    queue<vector<int>> pending;
    pending.push(src);
    parents[src[0]][src[1]] = {0};
    while (!pending.empty()) {
        vector<int> p = pending.front();
        pending.pop();
        if (isValid(p[0], p[1] + 1, grid, parents)) {
            parents[p[0]][p[1] + 1] = p;
            pending.push({p[0], p[1] + 1});
        }
        if (isValid(p[0], p[1] - 1, grid, parents)) {
            parents[p[0]][p[1] - 1] = p;
            pending.push({p[0], p[1] - 1});
        }
        if (isValid(p[0] + 1, p[1], grid, parents)) {
            parents[p[0] + 1][p[1]] = p;
            pending.push({p[0] + 1, p[1]});
        }
        if (isValid(p[0] - 1, p[1], grid, parents)) {
            parents[p[0] - 1][p[1]] = p;
            pending.push({p[0] - 1, p[1]});
        }
    }
    if (parents[dist[0]][dist[1]][0] == -1) {
        cout << "NO";
        return;
    }
    cout << "YES\n";
    vector<char> path;
    while (dist != src) {
        vector<int> parent = parents[dist[0]][dist[1]];
        vector<int> diff = {parent[0] - dist[0], parent[1] - dist[1]};
        path.push_back(dir[diff]);
        dist = parent;
    }
    reverse(all(path));
    cout << path.size() << '\n';
    for (char step : path) {
        cout << step;
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
