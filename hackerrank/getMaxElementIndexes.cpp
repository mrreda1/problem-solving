#include <bits/stdc++.h>

using namespace std;

vector<int> getMaxElementIndexes(vector<int> a, vector<int> rotate) {
    int n = a.size(), m = rotate.size();
    int max_index = max_element(a.begin(), a.end()) - a.begin() + n;
    vector<int> res(m);
    for (int i = 0; i < m; i++) {
        int shift = rotate[i] % n, new_index = (max_index - shift) % n;
        res[i] = new_index;
    }
    return res;
}
