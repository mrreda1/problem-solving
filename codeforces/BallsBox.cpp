#include <iostream>

using namespace std;
int main () {
    int a, b, x;
    cin >> a >> b >> x;
    if((a%x == 0 and b%x != 0) or (x%a == 0 and x%b != 0)) cout << "Ouda";
    else if ((x%b == 0 or x%a != 0) and (b%x == 0 and a%x != 0)) cout << "Gom3a";
    else cout << "Draw";
    return 0
}
