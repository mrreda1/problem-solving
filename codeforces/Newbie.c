#include <stdio.h>
#include <math.h>

int main(void) {
    double n, k, a;
    scanf("%lf%lf%lf", &n, &k, &a);
    double equ = (-n + k) * a / 2.0;
    if((double) equ > (long long) equ)
        puts("double");
    else if(equ < -2147483647 || equ > 2147483648)
        puts("long long");
    else puts("int");
}
