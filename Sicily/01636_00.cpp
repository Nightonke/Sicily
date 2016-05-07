// Problem#: 1636
// Submission#: 2305789
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, hsum, nsum=0, zhongshu, danjia, shuliang;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &hsum,&zhongshu);
        while(zhongshu--){
            scanf("%d%d", &danjia,&shuliang);
            nsum = nsum + danjia*shuliang;}
        if(hsum>=nsum)
            printf("%d\n", hsum-nsum);
        else
            printf("Not enough\n");
        nsum=0;}
    return 0;
}                                 