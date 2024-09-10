#include <iostream>

int main() {
    long long a, b, c, d, e, f, g, h;
    for(a=1;a<16;a+=2) {
        for(b=1;b<16;b++) {
            for(c=1;c<16;c++) {
                for(d=1;d<16;d++) {
                    for(e=1;e<16;e++) {
                        for(f=1;f<16;f++) {
                            for(g=1;g<16;g++) {
                                for(h=1;h<16;h++) {
                                    if(a!=b && a!=c && a!=d && a!=e && a!=f && a!=g && a!=h) {
                                        if(b!=c && b!=d && b!=e && b!=f && b!=g && b!=h) {
                                            if(c!=d && c!=e && c!=f && c!=g && c!=h) {
                                                if(d!=e && d!=f && d!=g && d!=h) {
                                                    if(e!=f && e!=g && e!=h) {
                                                        if(f!=g && f!=h) {
                                                            if(g!=h) {
                                                                printf("%x\n", (a|(b<<4)|(c<<8)|(d<<12)|(e<<16)|(f<<20)|(g<<24)|(h<<28)));
                                                            }
                                                        }
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}
