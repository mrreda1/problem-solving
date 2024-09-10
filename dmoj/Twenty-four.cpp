#include <bits/stdc++.h>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()

using namespace std;
using llu = unsigned long long;
using ll = long long;

const bool T = 1;
const string iofile = "";

int dv(int a, int b) {
    if (!b || a % b) {
        return INT_MAX;
    } else {
        return a / b;
    }
}
void testAll(vector<int> cards, vector<function<int(int, int)>> op, int *mx) {
    if (!op.size()) {
        if (cards[0] <= 24) {
            *mx = max(*mx, cards[0]);
        }
        return;
    }
    for (int i = 0; i < static_cast<int>(op.size()); i++) {
        int c[2] = {cards[i], cards[i + 1]};
        int res = op[i](c[0], c[1]);
        if (res == INT_MAX) {
            continue;
        }
        cards.erase(cards.begin() + i);
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin() + i, res);
        function<int(int, int)> tmpOP = op[i];
        op.erase(op.begin() + i);
        testAll(cards, op, mx);
        op.insert(op.begin() + i, tmpOP);
        cards.erase(cards.begin() + i);
        cards.insert(cards.begin() + i, c[1]);
        cards.insert(cards.begin() + i, c[0]);
    }
}
void solve() {
    int mx = 0;
    vector<int> cards(4);
    vector<function<int(int, int)>> op = {
        [](int x, int y) { return x + y; }, [](int x, int y) { return x - y; },
        [](int x, int y) { return x * y; }, dv};
    for (int i = 0; i < 4; i++) {
        cin >> cards[i];
    }
    sort(all(cards));

    do {
        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 4; y++) {
                for (int z = 0; z < 4; z++) {
                    testAll(cards, {op[x], op[y], op[z]}, &mx);
                }
            }
        }
    } while (next_permutation(all(cards)));
    cout << mx;
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
