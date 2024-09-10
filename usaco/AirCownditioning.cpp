#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";

void solve() {
    array<int, 101> stall;
    int n, m, res = INT_MAX;
    cin >> n >> m;
    vector<array<int, 3>> cows(n);
    vector<array<int, 4>> acs(m);
    vector<int> subset;

    for (array<int, 3> &cow : cows) {
        for (int &x : cow) {
            cin >> x;
        }
    }
    for (array<int, 4> &ac : acs) {
        for (int &x : ac) {
            cin >> x;
        }
    }

    function<void(int)> bruteForce = [&](int k) {
        if (k == m) {
            fill(all(stall), 0);
            int cost = 0;
            for (int x : subset) {
                cost += acs[x][3];
                stall[acs[x][0]] += acs[x][2];
                stall[acs[x][1] + 1] -= acs[x][2];
            }
            for (int i = 1; i <= 100; i++) {
                stall[i] += stall[i - 1];
            }
            for (auto cow : cows) {
                for (int i = cow[0]; i <= cow[1]; i++) {
                    if (stall[i] < cow[2]) {
                        return;
                    }
                }
            }
            res = min(res, cost);
        } else {
            bruteForce(k + 1);
            subset.push_back(k);
            bruteForce(k + 1);
            subset.pop_back();
        }
    };
    bruteForce(0);
    cout << res;
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
