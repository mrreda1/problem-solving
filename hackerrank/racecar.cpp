#include <bits/stdc++.h>

using namespace std;

int minimumMovement(vector<int> obstacleLanes) {
    int n = obstacleLanes.size(), res = 0;
    vector<int> lanes(3, INT_MAX), step(n, 0);
    for (int i = n - 1; i >= 0; i--) {
        lanes[obstacleLanes[i] - 1] = i;
        step[i] = max_element(lanes.begin(), lanes.end()) - lanes.begin() + 1;
    }
    for (int i = 0, current = 2; i < n; i++) {
        while (i < n && obstacleLanes[i] != current) {
            i++;
        }
        if (i < n) {
            current = step[i], res++;
        }
    }
    return res;
}
int main() {
    int n;
    cin >> n;
    vector<int> road(n);
    for (int &x : road) {
        cin >> x;
    }
    cout << minimumMovement(road);
}
