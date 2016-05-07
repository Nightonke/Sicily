// Problem#: 1141
// Submission#: 2572945
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int i, result = 1, n;
    scanf("%d", &n);
    for (i = 0; i < n - 2; i++) {
        result = n * result % 10007;
    }
    for (i = 2; i < n; i++) {
        result = i * result % 10007;
    }
    printf("%d\n", (result + 10007) % 10007);
    return 0;
}                                 