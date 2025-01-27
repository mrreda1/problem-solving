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
    static constexpr bool value = decltype(test<T>(nullptr))::value;
};
template <typename T>
typename enable_if<!(!is_same<T, string>::value && is_iterable<T>::value)>::type
nxtseq(T &x);
template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 0;
const string iofile = "snowboots";

void solve() {
    int n = nxt<int>(), b = nxt<int>(), max_step = 1;
    vector<int> blocks(n), res(b);
    vector<array<int, 3>> boots(b);
    nxtseq(blocks);
    for (int i = 0; i < b; i++) {
        boots[i] = {nxt<int>(), nxt<int>(), i};
    }
    sort(rall(boots));
    vector<int> depth(n);
    iota(all(depth), 0);
    set<int> valid_blocks(all(depth));
    sort(all(depth), [&blocks](int x, int y) { return blocks[x] > blocks[y]; });
    for (int i = 0, ptr = 0; i < b; i++) {
        while (boots[i][0] < blocks[depth[ptr]]) {
            set<int>::iterator block = valid_blocks.find(depth[ptr++]);
            max_step = max(max_step, *next(block) - *prev(block));
            valid_blocks.erase(block);
        }
        res[boots[i][2]] = max_step <= boots[i][1];
    }
    for (int x : res) {
        cout << x << '\n';
    }
}

int main() {
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
typename enable_if<!(!is_same<T, string>::value && is_iterable<T>::value)>::type
nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<!is_same<T, string>::value && is_iterable<T>::value>::type
nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
