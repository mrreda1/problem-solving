#include <iostream>

using namespace std;

int minimumNumber(int n, string pwd) {
    int chk = 0, remain = 0;
    string special = "!@#$%^&*()-+";
    for (char c: pwd) {
        if (c >= 'a' && c <= 'z') {
            chk |= 1;
        } else if (c >= 'A' && c <= 'Z') {
            chk |= 2;
        } else if (c >= '0' && c <= '9') {
            chk |= 4;
        } else {
            for (char sp: special) {
                if (sp == c) {
                    chk |= 8;
                    break;
                }
            }
        }
        if (chk == 15) break;
    }
    while (chk) {
        remain += chk&1;
        chk >>= 1;
    }
    remain = 4 - remain;

    return (remain > 6 - n)?(remain):(6 - n);
}

int main () {
    cout << minimumNumber(11, "#HackerRank");
}
