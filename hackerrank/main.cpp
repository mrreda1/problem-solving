#include <bits/stdc++.h>

using namespace std;

int formingMagicSquare(vector<vector<int>> s) {
    int res = INT_MAX;
    vector<int> matrix(9);
    iota(matrix.begin(), matrix.end(), 1);
    do {
        bool valid = true;
        int di_sum[2]{};
        for (int i = 0; i < 3; i++) {
            int row_sum = 0, col_sum = 0;
            for (int j = 0; j < 3; j++) {
                row_sum += matrix[i * 3 + j];
                col_sum += matrix[j * 3 + i];
            }
            if (!(col_sum == 15 && row_sum == 15)) {
                valid = false;
                break;
            }
            di_sum[0] += matrix[i * 4];
            di_sum[1] += matrix[i * 2 + 2];
        }
        if (valid && di_sum[0] == di_sum[1]) {
            int diff = 0;
            for (int i = 0; i < 3; i++) {
                for (int j = 0; j < 3; j++) {
                    diff += abs(matrix[i * 3 + j] - s[i][j]);
                }
            }
            res = min(res, diff);
        }
    } while (next_permutation(matrix.begin(), matrix.end()));
    return res;
}
