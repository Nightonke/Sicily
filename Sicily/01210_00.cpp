// Problem#: 1210
// Submission#: 3260812
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int main() {
    
    char pre[30], post[30];
    int counter = 0;
    scanf("%s%s", pre, post);
    for (int i = 0; pre[i + 1] != '\0'; i++) {
        for (int j = 0; post[j + 1] != '\0'; j++) {
            if (pre[i + 1] == post[j] && pre[i] == post[j + 1]) {
                counter++;
                break;
            }
        }
    }
    printf("%.0lf", pow(2.0, 1.0 * counter));

    return 0;
}                                 