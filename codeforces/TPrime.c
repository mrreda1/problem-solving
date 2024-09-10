#include <stdio.h>
#include <math.h>

int isPrime(long long n) {
    if (n < 2 || ((n%2==0)&&n!=2)) return 0;
    for(unsigned long i = 3; i*i <= n; i+=2)
        if (n%i == 0) return 0;
    return 1;
}
void solve() {
    unsigned long long x, root;
    scanf("%llu", &x);
    root = sqrt(x);
    puts((x == root*root && isPrime(root))?("YES"):("NO"));
}
int main () {
    int t;
    scanf("%d", &t);
    while(t--) {
        solve();
    }
}
