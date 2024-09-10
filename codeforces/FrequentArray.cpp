#include <iostream>

using namespace std;

int main() {
    int n, m, x;
    cin >> n >> m;
    int A[m] = {0};

    while(n--) {
        cin >> x;
        A[x - 1]++;
    }
    for(int i = 0; i < m; i++)
        cout << A[i] << endl;
}
