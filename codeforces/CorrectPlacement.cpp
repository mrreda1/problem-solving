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
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x);
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x);

using ld = long double;
using llu = uint64_t;
using ll = int64_t;

const bool T = 1;
const string iofile = "";

void solve() {
    int n = nxt<int>(), mn[2]{};
    vector<array<int, 3>> person(2 * n);
    vector<int> res(n, -1);
    for (int i = 0; i < 2 * n; i += 2) {
        person[i + 1] = person[i] = {nxt<int>(), nxt<int>(), (i / 2) + 1};
        swap(person[i + 1][0], person[i + 1][1]);
    }
    sort(all(person));
    for (int i = 0; i < 2 * n; i++) {
        if (person[i][1] < person[mn[1]][1]) {
            if (person[i][0] != person[mn[1]][0]) {
                mn[0] = mn[1];
            }
            mn[1] = i;
        } else if (person[i][1] > person[mn[1]][1] &&
                   person[i][0] != person[mn[1]][0]) {
            res[person[i][2] - 1] = mn[1];
        } else if (person[i][1] > person[mn[0]][1] &&
                   person[i][0] != person[mn[0]][0]) {
            res[person[i][2] - 1] = mn[0];
        }
    }
    for (auto x : res) {
        cout << (x == -1 ? -1 : person[x][2]) << ' ';
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
typename enable_if<!is_iterable<T>::value>::type nxtseq(T &x) {
    cin >> x;
}
template <typename T>
typename enable_if<is_iterable<T>::value>::type nxtseq(T &x) {
    for (auto &v : x) {
        nxtseq(v);
    }
}
