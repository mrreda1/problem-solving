#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())
#define pow2(x) ((x) * (x))

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

void grid_parse(const vector<vector<char>> &grid, vector<vector<int>> &edges) {
    int n = grid.size(), m = grid[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == '#') {
                continue;
            }
            bool up = i != 0 && grid[i - 1][j] != '#',
                 down = i != (n - 1) && grid[i + 1][j] != '#',
                 left = j != 0 && grid[i][j - 1] != '#',
                 right = j != (m - 1) && grid[i][j + 1] != '#';
            if (up) {
                edges[i * m + j].push_back((i - 1) * m + j);
            }
            if (down) {
                edges[i * m + j].push_back((i + 1) * m + j);
            }
            if (left) {
                edges[i * m + j].push_back(i * m + j - 1);
            }
            if (right) {
                edges[i * m + j].push_back(i * m + j + 1);
            }
        }
    }
}
int getDir(int src, int dist, int col) {
    if (dist - src == 1) {
        return 0;
    } else if (src - dist == 1) {
        return 1;
    } else if (dist - src == col) {
        return 2;
    }
    return 3;
}
void solve() {
    int n, m, st, ed;
    cin >> n >> m;
    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<int>> edges(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
            if (grid[i][j] == 'S') {
                st = i * m + j;
            } else if (grid[i][j] == 'T') {
                ed = i * m + j;
            }
        }
    }
    grid_parse(grid, edges);
    vector<vector<vector<ll>>> dp(
        n * m, vector<vector<ll>>(4, vector<ll>(4, INT_MAX)));
    for (int i = 0; i < 4; i++) {
        dp[st][i] = {};
    }
    using state = tuple<ll, int, int, int>;
    priority_queue<state, vector<state>, greater<state>> pending;
    for (int neighbor : edges[st]) {
        int dir = getDir(st, neighbor, m);
        pending.push({1, neighbor, dir, 1});
    }
    while (!pending.empty()) {
        auto [cost, current, old_dir, rep] = pending.top();
        pending.pop();
        if (dp[current][old_dir][rep] <= cost) {
            continue;
        }
        dp[current][old_dir][rep] = cost;
        for (int neighbor : edges[current]) {
            int dir = getDir(current, neighbor, m);
            if (dir == old_dir) {
                if (rep == 3) {
                    pending.push({cost + 3, neighbor, dir, 2});
                } else {
                    pending.push({cost + 1, neighbor, dir, rep + 1});
                }
            } else {
                pending.push({cost + 1, neighbor, dir, 1});
            }
        }
    }
    ll res = INT_MAX;
    for (int i = 0; i <= 3; i++) {
        res = min(res, *min_element(all(dp[ed][i])));
    }
    cout << (res == INT_MAX ? -1 : res);
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
