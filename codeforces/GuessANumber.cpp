#include <iostream>
#include <climits>
#include <string>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    int n, num, min = INT_MAX, max = INT_MIN, mmin = INT_MIN, mmax = INT_MAX;
    char ans;
    string r;
    cin >> n;
    while (n--) {
        cin >> r >> num >> ans;
        if (ans == 'Y') {
            if (!(r[1] == '=')) {
                num += r[0] - '=';
            }
            if (r[0] == '<') {
                if (num > max && num <= mmax)
                    max = num;
            }
            else {
                if (num < min && num >= mmin)
                    min = num;
            }
        } else {
            if (r[1] == '=') {
                num -= r[0] - '=';
            }
            if (r[0] == '>') {
                mmax = num;
                if (num < max || max == INT_MIN)
                    max = num;
            }
            else {
                mmin = num;
                if (num > min || min == INT_MAX)
                    min = num;
            }
        }
    }
    if (max == INT_MIN)
        max = INT_MAX;
    if (min == INT_MAX)
        min = INT_MIN;

    if (max < min || mmax < mmin) {
        cout << "Impossible";
    } else {
        cout << min;
    }
}
