#include <bits/stdc++.h>
#include <functional>

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
const string iofile = "censor";

void solve() {
    string s, t;
    vector<pair<size_t, size_t>> skip;
    stack<size_t> test;
    size_t j = 0, mul = 0;
    cin >> s >> t;

    for (size_t i = 0; i <= s.size(); i++) {
        if (j == t.size()) {
            skip.push_back({i - j - mul * j, i});
            if (test.empty()) {
                j = 0;
                mul = 0;
            } else {
                j = test.top();
                test.pop();
                mul++;
            }
        }
        if (i < s.size()) {
            if (s[i] == t[j]) {
                j++;
            } else if (s[i] == t[0]) {
                test.push(j);
                j = 1;
            } else {
                mul = 0;
                j = 0;
                test = stack<size_t>();
            }
        }
    }
    sort(all(skip), greater<>());

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == t[0]) {
            while (!skip.empty() && skip.back().first <= i) {
                if (skip.back().first < i) {
                    skip.pop_back();
                }
                if (skip.back().first == i) {
                    i = skip.back().second;
                    skip.pop_back();
                }
            }
        }
        cout << s[i];
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
