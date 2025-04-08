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

const bool T = 0;                 // Multiple test cases?
const string iofile = "wormsort"; // I/O file?

void solve() {
    int n = nxt<int>(), m = nxt<int>(), l = 1, r = 1e9, ans = l;
    vector<int> cows(n);
    vector<array<int, 3>> wormholes(m);
    nxtseq(cows), nxtseq(wormholes);
    if (is_sorted(all(cows))) {
        cout << -1;
        return;
    }
    while (l <= r) {
        int mid = (l + r) / 2;
        vector<vector<int>> edges(n);
        for (array<int, 3> &wormhole : wormholes) {
            if (wormhole[2] >= mid) {
                edges[wormhole[0] - 1].push_back(wormhole[1] - 1);
                edges[wormhole[1] - 1].push_back(wormhole[0] - 1);
            }
        }
        vector<int> sortedcows(all(cows));
        vector<bool> visited(n, false);
        vector<vector<int>> forest;
        for (int st = 0; st < n; st++) {
            if (visited[st]) continue;
            visited[st] = true;
            queue<int> pending({st});
            forest.push_back({st});
            while (!pending.empty()) {
                int current = pending.front();
                pending.pop();
                for (int neighbor : edges[current]) {
                    if (!visited[neighbor]) {
                        visited[neighbor] = true;
                        pending.push(neighbor);
                        forest.back().push_back(neighbor);
                    }
                }
            }
        }
        for (vector<int> scc : forest) {
            int n = scc.size();
            vector<int> pos(n);
            for (int i = 0; i < n; i++) {
                pos[i] = cows[scc[i]];
            }
            sort(all(scc)), sort(all(pos));
            for (int i = 0; i < n; i++) {
                sortedcows[scc[i]] = pos[i];
            }
        }
        if (is_sorted(all(sortedcows))) {
            l = mid + 1;
            ans = mid;
        } else {
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
