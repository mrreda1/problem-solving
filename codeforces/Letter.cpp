#include <iostream>
#include <string>

#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
#define abs(x) (((x) < 0) ? (-(x)) : ((x)))

using namespace std;
using llu = unsigned long long;
using ll = long long;

void solve() {
    char buff[2][1024] = {{0}, {0}};
    int freq[128] = {0};
    scanf("%[^\n]%*c%[^\n]%*c", buff[0], buff[1]);
    for (int i = 0; buff[0][i]; i++) {
        freq[buff[0][i]]++;
    }
    for (int i = 0; buff[1][i]; i++) {
        if (buff[1][i] != ' ' && !freq[buff[1][i]]) {
            cout << "NO";
            return;
        }
        freq[buff[1][i]]--;
    }
    cout << "YES";
}

void tsolve();
void io();

int main() {
    io();
    solve();
}
void tsolve() {
    int t;
    cin >> t;
    while (t--) {
        solve();
        cout << '\n';
    }
}
void io() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
#ifdef _DEBUG
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
}
