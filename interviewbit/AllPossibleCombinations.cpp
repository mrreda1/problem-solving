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

vector<string> specialStrings(vector<string> &A) {
    vector<string> res;
    vector<char> perm;

    function<void(int)> loops = [&](int k) {
        if (k == A.size()) {
            string x(all(perm));
            res.push_back(x);
            return;
        }
        for (int i = 0; i < A[k].size(); i++) {
            perm.push_back(A[k][i]);
            loops(k + 1);
            perm.pop_back();
        }
    };
    loops(0);
    sort(all(res));
    return res;
}
void solve() {
    vector<string> A = {"ab", "cd"};
    A = specialStrings(A);
    for (string s : A) {
        cout << s << endl;
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
