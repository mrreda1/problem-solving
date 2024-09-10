#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";


void solve() {
    int n = nxt<int>(), q = nxt<int>();
    array<int, static_cast<int>(2e5 + 1)> ogfreq, freq{}, rp;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        a[i] = nxt<int>();
        freq[a[i]]++;
        rp[a[i]] = a[i];
    }
    ogfreq = freq;
    for (int l = 0, r = 0, og = freq[a[0]]; r < n; r++) {
        if (freq[rp[a[l]]] > r - l + (rp[a[l]] == rp[a[r]])) {
            if (rp[a[l]] != rp[a[r]]) {
                if (og >= freq[rp[a[r]]]) {
                    freq[rp[a[l]]] += freq[rp[a[r]]];
                    freq[rp[a[r]]] = 0;
                    rp[a[r]] = rp[a[l]];
                } else {
                    og = freq[rp[a[r]]];
                    freq[rp[a[r]]] += freq[rp[a[l]]];
                    freq[rp[a[l]]] = 0;
                    rp[a[l]] = rp[a[r]];
                }
            }
        } else {
            l = r + 1;
            if (l < n) {
                og = freq[rp[a[l]]];
            }
        }
    }
    for (int i = 0; i <= static_cast<int>(2e5); i++) {
        q += abs(freq[i] - ogfreq[i]);
    }
    cout << q / 2;
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
