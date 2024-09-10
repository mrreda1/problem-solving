#include <algorithm>
#include <climits>
#include <ios>
#include <iostream>
#define int long long

int getFirst(int arr[], size_t low, size_t high, int x, size_t n) {
    if (low >= high) return high;
    size_t mid = (high + low) / 2;
    if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
        return mid;
    else if (x > arr[mid])
        return getFirst(arr, mid + 1, high, x, n);
    else if (mid <= 0) return 0;
    return getFirst(arr, low, mid - 1, x, n);
}
int getLast(int arr[], size_t low, size_t high, int x, size_t n) {
    if (low >= high) return high;
    size_t mid = (high + low) / 2;
    if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
        return mid;
    else if (x < arr[mid]) {
        if (mid <= 0) return 0;
        return getLast(arr, low, mid - 1, x, n);
    }
    return getLast(arr, mid + 1, high, x, n);
}

int solve() {
    int n, l, r, i, cnt, e, s;
    std::cin >> n >> l >> r;
    int a[n+1];
    a[n] = LLONG_MAX;
    for(i = 0; i < n; i++)
        std::cin >> a[i];
    std::sort(a, a + n);
    for(cnt = i = 0; i < n-1; i++) {
        if(2*a[i] > r) return cnt;
        s = getFirst(a, 0, n-1, l - a[i], n);
        if(a[s] < l - a[i]) {
            s = getLast(a, 0, n-1, a[s], n) + 1;
        }
        if (a[s] <= a[i]) s = i + 1;
        e = getLast(a, 0, n-1, r - a[i], n);
        if (a[e] > r - a[i]) {
            e = getFirst(a, 0, n-1, a[e], n) - 1;
        } else if (a[e] < r - a[i]) {
            e = getLast(a, 0, n-1, a[e], n);
        }
        if(e >= n || s >= n || (e | s) < 0) continue;
        cnt += (e-s+1>0)?(e-s+1):(0);
    }
    return cnt;
}
signed main() {
    std::ios_base::sync_with_stdio(false);std::cin.tie(NULL);
    int t;
    std::cin >> t;
    while(t--) {
        std::cout << solve() << '\n';
    }
}
