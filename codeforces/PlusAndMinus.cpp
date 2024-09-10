#include <iostream>
#include <vector>

using namespace std;
int main () {
    ios_base::sync_with_stdio(false);cin.tie(NULL);
    char c;
    string name;
    long long t, q, p, x, y, shift, sum, i;
    cin >> t;
    while (t--) {
        vector<int> query;
        cin >> name >> q;
        while (q--) {
            cin >> x >> c;
            query.push_back(x*((c=='+')?(1):(-1)));
        }
        long long freq[query.size()] = {0};
        cin >> p;
        while (p--) {
            cin >> x >> y;
            freq[y-1]++;
            (x<2)?:(freq[x-2]--);
        }
        for (sum = 0, i = query.size() - 1; i >= 0; i--) {
            freq[i] += sum;
            sum = freq[i];
        }
        for (i = 0; i < query.size(); i++) {
            shift = (freq[i]%26)*((query[i]<0)?(-1):(1));
            query[i] = ((query[i]<0)?(-1):(1))*query[i] - 1;
            x = name[query[i]] - 'a' + shift;
            x = (x<0)?(x+26):(x%26);
            name[query[i]] = x + 'a';
        }
        cout << name;
    }
}
