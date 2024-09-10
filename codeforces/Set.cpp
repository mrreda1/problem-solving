#include <iostream>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n = 1e5, m, i, cnt;
    bool freq[n+1] = {0};
    cin >> n >> m;
    pair<unsigned, unsigned> a[n];
    for(i = 0; i < n; i++)
        cin >> a[i].first;
    for(cnt = 0, i = n-1; i >= 0; i--) {
        if (!freq[a[i].first]) {
            cnt++;
            freq[a[i].first] = 1;
        }
        a[i].second = cnt;
    }
    while(m--) {
        cin >> i;
        cout << a[i-1].second << '\n';
    }
}
