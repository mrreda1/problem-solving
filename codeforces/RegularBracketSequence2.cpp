#include <iostream>

int main () {
    std::string str;
    std::cin >> str;
    long i, j, s, e, n = str.size(), c1=0, c2=0;
    for (s = 0; s < n; s++)
        if (str[s]=='(') break;
    for (e = n-1; e >= 0; e--)
        if (str[e]==')') break;
    i = s, j = e;
    while(i <= j) (str[i++]=='(')?(c1++):(c2++);
    if (c1<c2)
    std::cout << 2*((c1>c2)?(c2):(c1));
}
