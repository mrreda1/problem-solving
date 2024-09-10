#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "milkorder";


void solve() {
    int n = nxt<int>(), m = nxt<int>(), k = nxt<int>();
    vector<int> hier(m), Q(n + 1, 0), cowOrder(n + 1, 0);
    generate(all(hier), nxt<int>);

    while (k--) {
        int cow = nxt<int>(), pos = nxt<int>();
        cowOrder[cow] = pos;
        Q[pos] = cow;
    }

    if (cowOrder[1]) {
        // If cow 1 is in the k cows
        cout << cowOrder[1];
    } else if (count(all(hier), 1)) {
        // If cow 1 is in the social hierarchy
        // Make all cows early as possible
        int cur = 1;
        for (auto cow : hier) {
            if (cowOrder[cow]) {
                cur = cowOrder[cow] + 1;
            } else {
                while (Q[cur]) {
                    cur++;
                }
                cowOrder[cow] = cur;
                Q[cur] = cow;
                if (cow == 1) {
                    cout << cowOrder[1];
                    return;
                }
            }
        }
    } else {
        // If cow 1 isn't in the social hierarchy
        // Make all cows late as possible
        int cur = n;
        reverse(all(hier));
        for (auto cow : hier) {
            if (cowOrder[cow]) {
                cur = cowOrder[cow] - 1;
            } else {
                while (Q[cur]) {
                    cur--;
                }
                cowOrder[cow] = cur;
                Q[cur] = cow;
            }
        }
        for (int cur = 1; cur <= n; cur++) {
            if (!Q[cur]) {
                cout << cur;
                return;
            }
        }
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
    if (T) {
        int t;
        cin >> t;
        while (t--) {
            solve();
            cout << '\n';
        }
    } else {
        solve();
    }
}
template <typename T> T nxt() {
    T x;
    cin >> x;
    return x;
}
