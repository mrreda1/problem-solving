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

const bool T = 0;
const string iofile = "";

void solve() {
    int n = nxt<int>();
    vector<array<int, 4>> east, north;
    vector<vector<int>> eliminated(n);
    vector<int> score(n, -1);

    for (int i = 0; i < n; i++) {
        (nxt<char>() == 'E' ? east : north)
            .push_back({nxt<int>(), nxt<int>(), false, i});
    }

    sort(all(north));
    sort(all(east),
         [](array<int, 4> x, array<int, 4> y) { return x[1] < y[1]; });

    for (int i = 0; i < east.size(); i++) {
        for (int j = 0; j < north.size(); j++) {
            array<int, 2> diff = {north[j][0] - east[i][0],
                                  east[i][1] - north[j][1]};
            if (!(north[j][2] || (diff[0] | diff[1]) < 0 ||
                  diff[0] == diff[1])) {
                if (diff[0] > diff[1]) {
                    eliminated[north[j][3]].push_back(east[i][3]);
                    break;
                } else {
                    north[j][2] = true;
                    eliminated[east[i][3]].push_back(north[j][3]);
                }
            }
        }
    }
    function<int(int)> calcScore = [&](int i) {
        if (score[i] == -1) {
            score[i] = eliminated[i].size();
            for (int x : eliminated[i]) {
                score[i] += calcScore(x);
            }
        }
        return score[i];
    };
    for (int i = 0; i < n; i++) {
        cout << calcScore(i) << '\n';
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
