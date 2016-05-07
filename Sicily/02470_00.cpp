// Problem#: 2470
// Submission#: 2701654
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, kongzhi, i, j, temp, stand;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        kongzhi = 1;
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++) {
                scanf("%d", &temp);
                if (i == j && i == 0)
                    stand = temp;
                if (i == j && temp != stand)
                    kongzhi = 0;
                if (i != j && temp != 0)
                    kongzhi = 0;
            }
        }
        if (kongzhi)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 