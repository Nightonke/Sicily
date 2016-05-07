// Problem#: 1509
// Submission#: 2763513
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stack>
using namespace std;

int main() {
    bool is_ok;
    int after[1005], n, j, pos, i;
    int train[1005];
    while (scanf("%d", &n) && n) {
        while (scanf("%d", &after[0]) && after[0]) {
            for (i = 1, is_ok = true; i < n; i++) {
                scanf("%d", &after[i]);
                if (i >= 2 && after[i - 2] > after[i] && after[i] > after[i - 1])
                    is_ok = false;
            }
            if (!is_ok) {
                printf("No\n");
                continue;
            }
            pos = 1;
            train[pos] = j = 1;
            for (i = 0; i < n; i++) {
            
                while ((pos == 0 || after[i] != train[pos]) && j <= n) {
                    pos++;
                    train[pos] = ++j;
                }
            
                if (after[i] == train[pos])
                    pos--;
            }
            if (pos == 0) {
                printf("Yes\n");
            } else {
                printf("No\n");
            }
        }
        printf("\n");
    }
    return 0;
}                                 