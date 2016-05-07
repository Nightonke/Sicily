// Problem#: 1459
// Submission#: 2773645
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
int main() {
    int heads, knights, h[20000], k[20000], last_pos;
    while (scanf("%d%d", &heads, &knights) && heads && knights) {
        
        for (int i = 0; i < heads; i++) {
            scanf("%d", &h[i]);
        }
        for (int i = 0; i < knights; i++) {
            scanf("%d", &k[i]);
        }
        
        if (heads > knights) {
            printf("Loowater is doomed!\n");
            continue;
        }
        
        std::sort(h, h + heads);
        std::sort(k, k + knights);
        
        int counter = 0;
        int sum = 0;
        last_pos = 0;
        for (int i = 0; i < heads; i++) {
            for (int j = last_pos; j < knights; j++) {
                if (h[i] <= k[j]) {
                    counter++;
                    sum += k[j];
                    k[j] = -1;
                    last_pos = j + 1;
                    break;
                }
            }
        }
        
        if (counter == heads) {
            printf("%d\n", sum);
        } else {
            printf("Loowater is doomed!\n");
        }
    }
    return 0;
}                                 