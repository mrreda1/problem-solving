#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int trap(vector<int> &height) {
        int max_height = 2e5 + 2, res = 0, n = height.size();
        vector<int> levels(max_height, 0);
        vector<array<int, 2>> bounds(max_height, {INT_MAX, 0});
        for (int i = 0; i < n; i++) {
            bounds[height[i]][0] = min(bounds[height[i]][0], i);
            bounds[height[i]][1] = max(bounds[height[i]][1], i);
        }
        for (int i = max_height - 1, mn = INT_MAX, mx = 0; i >= 0; i--) {
            mn = min(mn, bounds[i][0]);
            mx = max(mx, bounds[i][1]);
            bounds[i][0] = mn;
            bounds[i][1] = mx;
        }
        for (int x : height) {
            levels[x + 1]--;
        }
        for (int i = 1; i < max_height; i++) {
            n += levels[i];
            if (n <= 1) return res;
            res += bounds[i][1] - bounds[i][0] + 1 - n;
        }
        return res;
    }
};
