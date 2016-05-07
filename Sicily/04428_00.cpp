// Problem#: 4428
// Submission#: 2704894
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int n, max_size, counter;

void dfs(int pos, int size) {
    int i;
    if (size == max_size)
        counter++;
    else {
        for (i = pos + 2; i <= n; i++) {
            dfs(i, size + 1);
        }
    }
    return;
}

int main() {
    int t, i;
    scanf("%d", &t);
    while (t--) {
        counter = 0;
        scanf("%d%d", &n, &max_size);
        if (max_size == 0) {
            printf("1\n");
            continue;
        }
        for (i = 1; i <= n; i++) {
            dfs(i, 1);
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 