#include <stdio.h>

int main () {
    unsigned char freq['z'-'a'+1] = {0}, c, cnt=0;
    while (scanf("%c", &c)) {
        if (c=='\n') break;
        (freq[c-'a']++)?:(cnt++);
    }
    printf((cnt%2)?("IGNORE HIM!"):("CHAT WITH HER!"));
}
