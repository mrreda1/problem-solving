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
    int n = nxt<int>(), m = nxt<int>(), res = INT_MAX;
    vector<int> student(n), prof(m + 1);
    unordered_set<int> subj;
    nxtseq(student);
    sort(all(student));
    function<void(int, bool)> modifySubjects = [&](int r, bool add) {
        for (int x = 1; x * x <= min(m * m, student[r]); x++) {
            if (!(student[r] % x)) {
                if (!prof[x]) {
                    subj.insert(x);
                } else if (!add && prof[x] == 1) {
                    subj.erase(x);
                }
                prof[x] += add ? 1 : -1;
                if (student[r] != x * x && student[r] / x <= m) {
                    if (!prof[student[r] / x]) {
                        subj.insert(student[r] / x);
                    } else if (!add && prof[student[r] / x] == 1) {
                        subj.erase(student[r] / x);
                    }
                    prof[student[r] / x] += add ? 1 : -1;
                }
            }
        }
    };
    for (int l = 0, r = 0; l < n; l++) {
        for (; subj.size() != m; r++) {
            if (r >= n) {
                cout << (res == INT_MAX ? -1 : res);
                return;
            }
            modifySubjects(r, true);
        }
        res = min(res, student[r - 1] - student[l]);
        modifySubjects(l, false);
    }
    cout << (res == INT_MAX ? -1 : res);
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
