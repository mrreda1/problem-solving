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

const bool T = 0;                  // Multiple test cases?
const string iofile = "fenceplan"; // I/O file?

void solve() {
    int n = nxt<int>(), m = nxt<int>(), res = INT_MAX;
    vector<vector<int>> moos(n + 1), cows(n + 1), groups;
    vector<int> visited(n + 1, 0);
    set<int> available;
    for (int i = 1; i <= n; i++) {
        available.insert(i);
        cows[i] = {nxt<int>(), nxt<int>()};
    }
    while (m--) {
        int u = nxt<int>(), v = nxt<int>();
        moos[u].push_back(v);
        moos[v].push_back(u);
    }
    while (!available.empty()) {
        stack<int> pending({*available.begin()});
        groups.push_back({});
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop(), available.erase(current);
            groups.back().push_back(current), visited[current] = true;
            for (int neighbor : moos[current]) {
                if (!visited[neighbor]) {
                    pending.push(neighbor);
                }
            }
        }
    }
    for (vector<int> &group : groups) {
        vector<vector<int>> rect({cows[group[0]], cows[group[0]]});
        for (int cow : group) {
            rect[0][0] = min(cows[cow][0], rect[0][0]);
            rect[0][1] = min(cows[cow][1], rect[0][1]);
            rect[1][0] = max(cows[cow][0], rect[1][0]);
            rect[1][1] = max(cows[cow][1], rect[1][1]);
        }
        res = min(res, rect[1][1] - rect[0][1] + rect[1][0] - rect[0][0]);
    }
    cout << 2 * res;
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
