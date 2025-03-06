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
        bool connected = true;
        vector<vector<int>> edges(p);
        vector<vector<bool>> matrix(p, vector<bool>(p, false));
        vector<array<int, 2>> conn(c);
        for (int i = 0; i < c; i++) {
            cin >> u >> v;
            matrix[u][v] = 1, matrix[v][u] = 1;
            edges[u].push_back(v), edges[v].push_back(u);
            conn[i] = {u, v};
        }
        for (int i = 0; i < c; i++) {
            stack<int> pending({0});
            vector<bool> unvisited(p, true);
            unvisited[0] = false;
            matrix[conn[i][0]][conn[i][1]] = 0;
            matrix[conn[i][1]][conn[i][0]] = 0;
            while (!pending.empty()) {
                int current = pending.top();
                pending.pop();
                for (int neighbor : edges[current]) {
                    if (matrix[current][neighbor] && unvisited[neighbor]) {
                        pending.push(neighbor);
                        unvisited[neighbor] = false;
                    }
                }
            }
            if (accumulate(all(unvisited), 0)) {
                connected = false;
                break;
            }
            matrix[conn[i][0]][conn[i][1]] = 1;
            matrix[conn[i][1]][conn[i][0]] = 1;
        }
        cout << (connected ? "NO" : "YES") << '\n';
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
