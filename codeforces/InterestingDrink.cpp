#include <algorithm>
#include <iostream>
#include <climits>

using namespace std;

int getLast(long arr[], size_t low, size_t high, long x, size_t n) {
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
int getFirst(long arr[], size_t low, size_t high, long x, size_t n) {
    if (low >= high) return high;
    size_t mid = (high + low) / 2;
    if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
        return mid;
    else if (x > arr[mid])
        return getFirst(arr, mid + 1, high, x, n);
    else if (mid <= 0) return 0;
    return getFirst(arr, low, mid - 1, x, n);
}
int main () {
    int s, d, i, day, cnt;
    cin >> s;

    long shop[s+1] = {0};
    for (i = 1; i <= s; i++)
        cin >> shop[i];
    sort(shop, shop + s + 1);

    cin >> d;
    for (i = 0; i < d; i++) {
        cin >> day;
        if (day >= shop[s]) {
            cout << s << '\n';
            continue;
        }
        cnt = getLast(shop, 0, s, day, s+1);
        if (shop[cnt] > day) {
            cnt = getFirst(shop, 0, s, shop[cnt], s+1) - 1;
        } else if (shop[cnt] < day) {
            cnt = getLast(shop, 0, s, shop[cnt], s+1);
        }
        cout << cnt << '\n';
    }
}
