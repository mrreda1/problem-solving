#include <iostream>
#include <vector>

using namespace std;
int main () {
    bool fnd[256] = {0};
    vector<int> pos;
    string q;
    int k;

    cin >> k >> q;
    for (int i = 0; i < q.size() && pos.size() < k; i++) {
        if (!fnd[q[i]]) {
            fnd[q[i]] = true;
            pos.push_back(i);
        }
    }
    if (pos.size() != k) {
        cout << "NO";
    } else {
        cout << "YES\n";
        pos.push_back(q.size());
        for (int i = 0; i < k; i++) {
            cout << q.substr(pos[i], pos[i+1]) << '\n';
        }
    }
}
