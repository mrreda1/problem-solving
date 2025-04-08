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
    int n = nxt<int>(), k = nxt<int>(), res = 0, id = 0, sccCount = 0;
    vector<vector<int>> edges(n);
    vector<int> ids(n, -1), low(n);
    vector<bool> onStack(n, false);
    stack<int> stk;
    vector<int> freq(n, 0);

    while (k--) {
        int u = nxt<int>() - 1, v = nxt<int>() - 1;
        if (nxt<int>() > nxt<int>()) {
            edges[u].push_back(v);
        } else {
            edges[v].push_back(u);
        }
    }
    function<void(int)> dfs = [&](int at) {
        stk.push(at);
        onStack[at] = true;
        ids[at] = low[at] = id++;

        for (int to : edges[at]) {
            if (ids[to] == -1) {
                dfs(to);
            }
            if (onStack[to]) {
                low[at] = min(low[at], low[to]);
            }
        }
        if (ids[at] == low[at]) {
            int node;
            do {
                node = stk.top();
                stk.pop();
                onStack[node] = false;
                low[node] = ids[at];
            } while (node != at);
            sccCount++;
        }
    };
    for (int i = 0; i < n; i++) {
        if (ids[i] == -1) {
            dfs(i);
        }
    }
    for (int i = 0; i < n; i++) {
        freq[low[i]]++;
    }
    for (int x : freq) {
        res += x > 1 ? x : 0;
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
