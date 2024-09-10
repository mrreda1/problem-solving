#include <iostream>

int main () {
    long blnc = 0, cnt = 0;
    std::string str;
    std::cin >> str;
    for (char c : str) {
        if (c == ')' && blnc) {
            cnt++, blnc--;
        } else if (c == '(') blnc++;
    }
    std::cout << cnt*2;
}
