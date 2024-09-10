#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
int BSearch(vector<int> arr, int left, int right, int x) {
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == x) {
            return mid;
        } else if (arr[mid] < x) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int o, g, x;
    vector<int> ouda;
    vector<int> gom3a;
    cin >> o >> g;
    while (o--) {
        cin >> x;
        if (!ouda.size() || ouda.back() != x)
            ouda.push_back(x);
    }
    while (g--) {
        cin >> x;
        if (!gom3a.size() || gom3a.back() != x)
            gom3a.push_back(x);
    }
    for (auto a : ouda) {
        if (!binary_search(gom3a.begin(), gom3a.end(), a))
            o++;
    }
    for (auto a : gom3a) {
        if (!binary_search(ouda.begin(), ouda.end(), a))
            g++;
    }
    cout << min(g, o) + 1;
}
