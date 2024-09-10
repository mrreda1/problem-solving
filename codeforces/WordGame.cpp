#include <iostream>
#include <map>

using namespace std;

void solve() {
    map<string, unsigned> words;
    int n, i, j;
    cin >> n;
    int p[3] = {0};
    string pw[3][n], w;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < n; j++) {
            cin >> w;
            pw[i][j] = w;
            if (words.find(w) == words.end()) {
                words[w] = 1;
            } else words[w]++;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < n; j++) {
            switch (words[pw[i][j]]) {
                case 1:
                    p[i] += 3;
                    break;
                case 2:
                    p[i] += 1;
                    break;
            }
        }
    }
    for (i = 0; i < 3; i++) {
        cout << p[i] << ' ';
    }
    cout << '\n';
}
int main () {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}
