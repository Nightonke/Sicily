// Problem#: 1920
// Submission#: 2620341
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, n, counter, a;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        counter = 0;
        while (n--) {
            scanf("%d", &a);
            if (a % 2 == 0) {
                counter++;
            }
        }
        if (counter % 2 == 0)
        printf("Bob\n");
        else
        printf("Alice\n");
    }
    return 0;
}                                 