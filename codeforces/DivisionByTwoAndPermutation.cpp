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

const bool T = 1;         // Multiple test cases?
const string iofile = ""; // I/O file?

void solve() {
    int n, x;
    cin >> n;
    vector<vector<int>> edges(2 * n + 1);
    set<int> matched, unmatched;
    for (int i = 1; i <= n; i++) {
        unmatched.insert(i);
        cin >> x;
        while (x) {
            if (x <= n) {
                edges[i].push_back(x + n);
            }
            x /= 2;
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int v : edges[i]) {
            if (edges[v].empty()) {
                matched.insert(i);
                unmatched.erase(i);
                edges[v].push_back(i);
                break;
            }
        }
    }
    while (!unmatched.empty()) {
        int st = *unmatched.begin(),found = 0;
        vector<int> parent(2 * n + 1, 0);
        stack<int> pending({st});
        parent[st] = -1;
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop();
            for (int neighbor : edges[current]) {
                if (!parent[neighbor]) {
                    parent[neighbor] = current;
                    if (neighbor > n && edges[neighbor].empty()) {
                        found = neighbor;
                        break;
                    } else {
                        pending.push(neighbor);
                    }
                }
            }
            if (found) {
                break;
            }
        }
        if (!found) {
            cout << "NO";
            return;
        }
        while (found != st) {
            if (found > n) {
                edges[found] = {parent[found]};
            }
            found = parent[found];
        }
        unmatched.erase(st);
        matched.insert(st);
    }
    cout << "YES";
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
