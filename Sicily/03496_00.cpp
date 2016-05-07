// Problem#: 3496
// Submission#: 2332510
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int m, n, jitou;
    while(1) {
        scanf("%d%d", &m,&n);
        if(m==0&&n==0) {
            break;}
        else {
            for(jitou=1;jitou<=m;jitou++) {
                if(jitou*2+(m-jitou)*4==n) {
                    printf("%d %d\n", jitou, m-jitou);
                    break;}}
            if((jitou-1)==m&&(jitou-1)*2!=n)
                printf("No answer\n");}}
    return 0;
}                                 