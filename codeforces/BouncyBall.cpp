#include <iostream>

using namespace std;

void sum(int *x, int y) {
    *x += y;
}
void sub(int *x, int y) {
    *x -= y;
}

void solve() {
    int n, m, i, j, ii, jj, it, jt, iii, jjj, ti, tj, dfi, dfj, df,
        chkinf = 0, chkinf2 = 0, cnt = 0;
    string d;
    char di, dj;
    void (*opi)(int *, int), (*opj)(int *, int);
    cin >> n >> m >> i >> j >> ti >> tj >> d;
    di = d[0], dj = d[1];
    iii = i, jjj = j;

    while (true) {
        ii = i, jj = j;
        if (di == 'D')
            dfi = n - i, opi = sum;
        else
            dfi = i - 1, opi = sub;
        if (dj == 'R')
            dfj = m - j, opj = sum;
        else
            dfj = j - 1, opj = sub;
        if (dfi < dfj)
            df = dfi, di = ((di == 'D') ? ('U') : ('D'));
        else if (dfj < dfi)
            df = dfj, dj = ((dj == 'R') ? ('L') : ('R'));
        else {
            df = dfi, di = ((di == 'D') ? ('U') : ('D'));
            dj = ((dj == 'R') ? ('L') : ('R'));
        }
        opi(&ii, abs(i - ti)), opj(&jj, abs(i - ti));
        if (ii == ti && jj == tj) {
            cout << cnt << endl;
            return;
        }

        ii = i, jj = j;
        opi(&ii, abs(i - iii)), opj(&jj, abs(j - jjj));
        if (ii == iii && jj == jjj)
            chkinf2++;

        opi(&i, df), opj(&j, df);

        if ((i == 1 && j == 1) || (i == 1 && j == m) || (i == n && j == 1) ||
            (i == n && j == m))
            chkinf++;

        if (chkinf >= 2 || chkinf2 >= 5e4) {
            cout << "-1" << endl;
            return;
        }
        cnt++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while (t--)
        solve();
}
