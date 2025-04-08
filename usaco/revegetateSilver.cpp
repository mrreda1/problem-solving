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

const bool T = 0;                   // Multiple test cases?
const string iofile = "revegetate"; // I/O file?

struct edge {
    int id;
    bool same_color;
};
void solve() {
    int n = nxt<int>(), m = nxt<int>(), components = 0;
    vector<vector<edge>> edges(n);
    vector<int> colors(n, -1);
    while (m--) {
        bool same_color = nxt<char>() == 'S';
        int u = nxt<int>() - 1, v = nxt<int>() - 1;
        edges[u].push_back({v, same_color});
        edges[v].push_back({u, same_color});
    }
    for (int st = 0; st < n; st++) {
        if (colors[st] != -1) {
            continue;
        }
        stack<int> pending({st});
        components++;
        colors[st] = 0;
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop();
            for (edge neighbor : edges[current]) {
                if (colors[neighbor.id] != -1) {
                    if (neighbor.same_color ^
                        (colors[neighbor.id] == colors[current])) {
                        cout << 0;
                        return;
                    }
                    continue;
                }
                if (neighbor.same_color) {
                    colors[neighbor.id] = colors[current];
                } else {
                    colors[neighbor.id] = !colors[current];
                }
                pending.push(neighbor.id);
            }
        }
    }
    cout << '1' << string(components, '0');
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
