// Problem#: 1459
// Submission#: 2773638
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int heads, knights, h[20005], k[20005];
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
        
        sort(k, k + knights);
        
        int counter = 0;
        int sum = 0;
        for (int i = 0; i < heads; i++) {
            for (int j = 0; j < knights; j++) {
                if (h[i] <= k[j]) {
                    counter++;
                    sum += k[j];
                    k[j] = -1;
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