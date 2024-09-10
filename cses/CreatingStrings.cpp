#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "";
set<string> res;
vector<int> permutation;
bool freq[8];
string s;

void perm(int n) {
    if (n == s.size()) {
        vector<char> tmp(permutation.size());
        for (int i = 0; i < permutation.size(); i++) {
            tmp[i] = s[permutation[i]];
        }
        string str(all(tmp));
        res.insert(str);
    } else {
        for (int i = 0; i < s.size(); i++) {
            if (!freq[i]) {
                permutation.push_back(i);
                freq[i] = true;
                perm(n + 1);
                permutation.pop_back();
                freq[i] = false;
            }
        }
    }
}
void solve() {
    cin >> s;
    perm(0);
    cout << res.size() << endl;
    for (string str : res) {
        cout << str << endl;
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
