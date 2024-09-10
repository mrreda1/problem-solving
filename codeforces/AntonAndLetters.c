#include <stdio.h>

int main () {
    char c;
    unsigned freq['z'-'a'+1] = {0}, cnt=0;
    while (scanf("%c", &c)) {
        if (c=='\n') break;
        (c<='z'&&c>='a'&&!freq[c-'a']++)?(cnt++):(0);
    }
    printf("%u", cnt);
}
