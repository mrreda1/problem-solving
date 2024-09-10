#include <iostream>

int main () {
    char key[] = "qwertyuiopasdfghjkl;zxcvbnm,./", dir, shift, i;
    std::string in;
    std::cin >> dir >> in;
    if (dir == 'R') shift = -1;
    else shift = 1;
    for (char c : in) {
        for (i = 0; i < 30; i++) {
            if (key[i] == c) {
                std::cout << key[i+shift];
                break;
            }
        }
    }
}
