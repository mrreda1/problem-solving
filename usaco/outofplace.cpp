#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "outofplace";


void solve() {
    int n = nxt<int>(), x, swaps = 0;
    vector<int> cows;
    cows.push_back(nxt<int>());

    while (n--) {
        x = nxt<int>();
        if (x ^ cows.back()) {
            cows.push_back(x);
        }
    }
    bool notSorted;
    do {
        notSorted = false;
        for (int i = 0; i < cows.size() - 1; i++) {
            if (cows[i] > cows[i + 1]) {
                swap(cows[i], cows[i + 1]);
                notSorted = true;
                swaps++;
                break;
            }
        }
    } while (notSorted);
    cout << swaps;
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
