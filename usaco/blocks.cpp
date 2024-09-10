#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define max(x, y) ((x > y) ? (x) : (y))
#define min(x, y) ((x < y) ? (x) : (y))
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)

using namespace std;
using llu = unsigned long long;
using ll = long long;
const ll MOD = 1e9 + 7;


const bool T = 0;
const string iofile = "blocks";

void solve() {
    int freq['z' + 1]{}, n;
    string word[2];
    cin >> n;

    while (n--) {
        int wfreq[2]['z' + 1]{};
        cin >> word[0] >> word[1];

        for (int c: word[0]) {
            wfreq[0][c]++;
        }
        for (int c: word[1]) {
            wfreq[1][c]++;
        }
        for (int i = 'a'; i <= 'z'; i++) {
            freq[i] += max(wfreq[0][i], wfreq[1][i]);
        }
    }
    for (int i = 'a'; i <= 'z'; i++) {
        cout << freq[i] << endl;
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
