#include <iostream>
#include <map>
typedef unsigned long long llu;

llu solve() {
    std::map<int, unsigned> m;
    llu n, x, i, cnt = 0;
    std::cin >> n;
    for(i = 0; i < n; i++) {
        std::cin >> x;
        if(m.find(x - i) == m.end()) {
            m[x-i] = 1;
        } else m[x-i]++;
    }
    for(auto itr = m.begin(); itr != m.end(); itr++)
        cnt+=(((llu)itr->second)*(itr->second-1))/2;
    return cnt;
}
int main() {
    unsigned t;
    std::cin >> t;
    while(t--)
        std::cout << solve() << '\n';
}
