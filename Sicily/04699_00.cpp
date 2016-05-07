// Problem#: 4699
// Submission#: 2695488
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, m, i, hash_use[10010], hash[10010], a[10010], temp;
    scanf("%d%d", &n, &m);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < m; i++)
        hash_use[i] = 0;
    for (i = 0; i < n; i++) {
        temp = a[i] % m;
        if (hash_use[temp] == 0) {
            hash[temp] = a[i];
            hash_use[temp] = 1;
        } else {
            while (hash_use[temp] == 1) {
                temp++;
                if (temp == m)
                    temp = 0;
            }
            hash[temp] = a[i];
            hash_use[temp] = 1;
        }
    }
    for (i = 0; i < m; i++) {
        if (hash_use[i] == 0)
            printf("%d#NULL\n", i);
        else
            printf("%d#%d\n", i, hash[i]);
    }
    return 0;
}                                 