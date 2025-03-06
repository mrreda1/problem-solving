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

string smallestStringWithSwaps(string s, vector<vector<int>> &pairs) {
    int n = s.size();
    vector<vector<int>> edges(n), forest;
    set<int> undiscovered;
    for (int i = 0; i < n; i++) {
        undiscovered.insert(i);
    }
    for (vector<int> &pair : pairs) {
        edges[pair[0]].push_back(pair[1]);
        edges[pair[1]].push_back(pair[0]);
    }
    while (!undiscovered.empty()) {
        forest.push_back({*undiscovered.begin()});
        stack<int> pending({*undiscovered.begin()});
        undiscovered.erase(undiscovered.begin());
        while (!pending.empty()) {
            int current = pending.top();
            pending.pop();
            for (int neighbor : edges[current]) {
                if (undiscovered.find(neighbor) != undiscovered.end()) {
                    undiscovered.erase(neighbor);
                    forest.back().push_back(neighbor);
                    pending.push(neighbor);
                }
            }
        }
    }
    for (vector<int> &graph : forest) {
        vector<char> toSort(graph.size());
        for (int i = 0; i < graph.size(); i++) {
            toSort[i] = s[graph[i]];
        }
        sort(graph.begin(), graph.end());
        sort(toSort.begin(), toSort.end());
        for (int i = 0; i < graph.size(); i++) {
            s[graph[i]] = toSort[i];
        }
    }
    return s;
}
void solve() {
    string str = nxt<string>();
    int n = nxt<int>();
    vector<vector<int>> a(n, vector<int>(2));
    nxtseq(a);
    cout << smallestStringWithSwaps(str, a);
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
