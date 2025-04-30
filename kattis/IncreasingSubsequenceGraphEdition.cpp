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
using ll = long long;
using llu = unsigned long long;

const bool T = 0;         // Multiple test cases?
const string iofile = ""; // I/O file?

bool cmp(vector<array<int, 2>> &x, int k) {
    return x.back()[0] < k;
}
bool cmp_sort(array<int, 2> &x, array<int, 2> &y) {
    if (x[0] == y[0]) {
        return x[1] < y[1];
    }
    return x[0] < y[0];
}
void solve() {
    int n;
    while ((n = nxt<int>())) {
        vector<vector<array<int, 2>>> lis;
        stack<array<int, 2>> res;
        vector<int> a(n), level(n);
        nxtseq(a);
        for (int i = 0; i < n; i++) {
            int pos = lower_bound(all(lis), a[i], cmp) - lis.begin();
            level[i] = pos + 1;
            if (pos == lis.size()) {
                lis.push_back({{a[i], i}});
            } else {
                lis[pos].push_back({a[i], i});
            }
        }
        cout << '\n' << lis.size() << ' ';
        if (lis.size() == 1) {
            cout << *min_element(all(a));
            break;
        }
        vector<vector<int>> edges(n);
        for (int i = 0; i < lis.size() - 1; i++) {
            for (array<int, 2> &x : lis[i]) {
                for (array<int, 2> &y : lis[i + 1]) {
                    if (x[0] < y[0] && x[1] < y[1]) {
                        edges[x[1]].push_back(y[1]);
                    }
                }
            }
        }
        deque<int> path;
        vector<bool> visited(n, false);
        function<bool(int)> dfs = [&](int current) {
            path.push_back(current);
            for (int neighbor : edges[current]) {
                if (level[neighbor] == lis.size()) {
                    path.push_back(neighbor);
                    return true;
                } else if (!visited[neighbor]) {
                    visited[neighbor] = true;
                    if (dfs(neighbor)) {
                        return true;
                    }
                }
            }
            path.pop_back();
            return false;
        };
        for (vector<int> &v : edges) {
            sort(all(v), [&a](int x, int y) {
                if (a[x] == a[y]) {
                    return x < y;
                }
                return a[x] < a[y];
            });
        }
        sort(all(lis[0]), [](array<int, 2> x, array<int, 2> y) {
                if (x[0] == y[0]) {
                    return x[1] < y[1];
                }
                return x[0] < y[0];
        });
        for (array<int, 2> &x : lis[0]) {
            if (dfs(x[1])) {
                for (int x : path) {
                    cout << a[x] << ' ';
                }
                break;
            }
        }
    }
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
