// Problem#: 1697
// Submission#: 3589003
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int main() {
    int T, n, x, y, i;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        if (n % 8 == 0) {
            printf("YES\n");
            x = 0, y = 0;
            for (i = 0; i < n / 4; i += 2) {
                printf("%d %d\n", x, y);
                y += i + 1;
                printf("%d %d\n", x, y);
                x += i + 2;
            }
            for (i = n / 4; i < 3 * n / 4; i += 2) {
                printf("%d %d\n", x, y);
                y -= i + 1;
                printf("%d %d\n", x, y);
                x -= i + 2;
            }
            for (i = 3 * n / 4; i < n; i += 2) {
                printf("%d %d\n", x, y);
                y += i + 1;
                printf("%d %d\n", x, y);
                x += i + 2;
            }
        } else printf("NO\n");
    }
    return 0;
}                                 