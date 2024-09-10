#include <iostream>
typedef long long ll;

using namespace std;
int BSearch (ll a,ll b, ll k, int steps) {
    ll mid = (a + b) / 2;
    if (k < mid) {
        return BSearch(a, mid - 1, k, ++steps);
    } else if (k > mid) {
        return BSearch(mid + 1, b, k, ++steps);
    } else {
        return steps;
    }
}
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    ll a, b, k;
    cin >> a >> b >> k;
    cout << BSearch(a, b, k, 1);
}
