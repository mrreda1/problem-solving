#include <iostream>

using namespace std;
void printChar(char c, int n, int x = 0) {
    if (x == n) return;
    cout << c;
    printChar(c, n, x + 1);
}

void drawPyramid(int n, int x = 1) {
    if (x == n + 1) return;
    printChar(' ', n - x), printChar('*', 2 * x - 1);
    cout << '\n';
    drawPyramid(n, x + 1);
}

int main() {
    int n;
    cin >> n;
    drawPyramid(n);
}
