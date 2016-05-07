// Problem#: 4700
// Submission#: 2468992
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, kongzhi1, kongzhi2, kongzhi3, linshi1, linshi2, max1, max2, max3;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        kongzhi1 = kongzhi2 = kongzhi3 = max1 = max2 = max3 = 0;
        while (n--) {
            scanf("%d %d", &linshi1, &linshi2);
            if (linshi1 == 1) {
                kongzhi1 = 1;
                if (max1 < linshi2)
                    max1 = linshi2;
            }
            if (linshi1 == 2) {
                kongzhi2 = 1;
                if (max2 < linshi2)
                    max2 = linshi2;
            }
            if (linshi1 == 3) {
                kongzhi3 = 1;
                if (max3 < linshi2)
                    max3 = linshi2;
            }
        }
        if (kongzhi1 == 1)
            printf("1 %d\n", max1);
        if (kongzhi2 == 1)
            printf("2 %d\n", max2);
        if (kongzhi3 == 1)
            printf("3 %d\n", max3);
    }
    return 0;
}                                 