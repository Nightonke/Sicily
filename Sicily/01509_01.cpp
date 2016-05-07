// Problem#: 1509
// Submission#: 2763474
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1509
// Submission#: 2763325
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <queue>
#include <stack>
using namespace std;

int main() {
    int after[1005], n, j, pos;
    int train[1005];
    while (scanf("%d", &n) && n) {
        while (scanf("%d", &after[0]) && after[0]) {
            for (int i = 1; i < n; i++) {
                scanf("%d", &after[i]);
            }
            pos = 1;
            train[pos] = j = 1;
            for (int i = 0; i < n; i++) {
            
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