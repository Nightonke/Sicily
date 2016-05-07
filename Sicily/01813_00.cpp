// Problem#: 1813
// Submission#: 2701262
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

int change_to_num(char d) {
    if (d >= '0' && d <= '9')
        return d - '0';
    else
        return d - 55;
}

char change_to_sign(int d) {
    if (d >= 0 && d <= 9)
        return d + '0';
    else
        return d + 55;
}

int change(char c[], int m) {
    int length = (int)strlen(c), sum = 0, i;
    for (i = length - 1; i >= 0; i--) {
        sum += change_to_num(c[i]) * (int)pow(m, length - i - 1);
    }
    return sum;
}

void ans(int n, int m) {
    int i = 0;
    char temp[1000];
    memset(temp, '\0', sizeof(temp));
    if (n == 0) {
        printf("0\n");
        return;
    }
    while (n > 0) {
        temp[i++] = change_to_sign(n % m);
        n /= m;
    }
    for (i--; i >= 0; i--)
        printf("%c", temp[i]);
    printf("\n");
}
    
int main() {
    int t, m, a_in_ten, b_in_ten;
    char a[1000], b[1000];
    scanf("%d", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        memset(b, '\0', sizeof(b));
        scanf("%d%s%s", &m, a, b);
        a_in_ten = change(a, m);
        b_in_ten = change(b, m);
        ans(a_in_ten / b_in_ten, m);
        ans(a_in_ten % b_in_ten, m);
    }
    return 0;
}                                 