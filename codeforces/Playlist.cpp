#include <iostream>
#include <map>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, x, s, mx, i;
    cin >> n;
    map<unsigned, unsigned> freq;
    for (i = s = 0, mx = 1; i < n; i++) {
        cin >> x;
        auto itr = freq.find(x);
        if (itr != freq.end()) {
            mx = max(mx, i - s);
            s = itr->second + 1;
            freq.erase(itr);
        }
        freq[x] = i;
    }
    mx = max(mx, i - s);
    cout << mx;
}
