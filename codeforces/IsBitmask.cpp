#include <iostream>
#include <vector>

int main () {
    unsigned long long n;
    std::vector<unsigned> bit;
    std::cin >> n;
    for (unsigned i = 0; n; i++) {
        if (n%2) bit.push_back(i);
        n >>= 1;
    }
    unsigned sz = bit.size();
    if (sz) {
        if (sz%2) {
            n = 1<<(bit[sz/2]);
        } else {
            n = (1<<(bit[sz/2]))-(1<<(bit[sz/2-1]+1));
        }
    }
    std::cout << n;
}
