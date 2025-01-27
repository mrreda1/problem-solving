#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define make_unique(x) sort(all(x)), x.erase(unique(all(x)), x.end())

template <typename T> T nxt();

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 0;
const string iofile = "family";

void solve() {
    int q = nxt<int>();
    array<string, 2> t{nxt<string>(), nxt<string>()};
    unordered_map<string, vector<string>> children;
    unordered_map<string, string> mother;

    while (q--) {
        array<string, 2> cows{nxt<string>(), nxt<string>()};
        children[cows[0]].push_back(cows[1]);
        mother[cows[1]] = cows[0];
    }

    function<bool(string, string)> SearchDirect = [&](string x, string y) {
        string m = mother[x];
        for (int g = 0; m != ""; m = mother[m], g++) {
            if (m == y) {
                cout << y << " is the ";
                if (g) {
                    while (--g) {
                        cout << "great-";
                    }
                    cout << "grand-mother";
                } else {
                    cout << "mother";
                }
                cout << " of " << x;
                return true;
            }
            for (string child : children[m]) {
                if (child == y) {
                    if (g) {
                        cout << y << " is the ";
                        while (--g) {
                            cout << "great-";
                        }
                        cout << "aunt of " << x;
                    } else {
                        cout << "SIBLINGS";
                    }
                    return true;
                }
            }
        }
        return false;
    };
    function<int(string)> searchRelated = [&](string m) {
        int c = (m == t[0] || m == t[1]);
        for (string child : children[m]) {
            c += searchRelated(child);
        }
        return c;
    };

    if (SearchDirect(t[0], t[1]) || SearchDirect(t[1], t[0])) {
        return;
    }
    for (auto [x, _] : children) {
        if (mother[x] == "" && searchRelated(x) == 1) {
            cout << "NOT RELATED";
            return;
        }
    }
    cout << "COUSINS";
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
