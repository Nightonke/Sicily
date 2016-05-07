// Problem#: 1512
// Submission#: 2597696
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

int getnum(char a[], int st, int en) {
    int i, sum = 0, k = 0;
    for (i = en; i >= st; i--) {
        sum += (a[i] - '0') * (int)pow(10, k);
        k++;
    }
    return sum;
}

void turnnum(char b[], int num1[], int length, int r, int c) {
    int i, k, j;
    for (i = 0; i < length; i++) {
        if (b[i] == ' ') {
            k = 0;
        }
        else
            k = b[i] - 'A' + 1;
        for (j = (i + 1) * 5 - 1; j >= i * 5; j--) {
            num1[j] = k % 2;
            k = k / 2;
        }
    }
    if (r * c < length * 5)
        for (i = length * 5; i < r * c; i++)
            num1[i] = 0;
}

int main() {
    int t, counter2 = 0, count, length, r, c, i, j, addx, addy, out[30][30], t1, t2, num[10000];
    char a[1000], b[1000];
    scanf("%d\n", &t);
    while (t--) {
        memset(a, '\0', sizeof(a));
        memset(b, '\0', sizeof(b));
        memset(num, 0, sizeof(num));
        counter2++;
        gets(a);
        length = strlen(a);
        for (i = 0; i < length; i++) {
            if (a[i] == ' ') {
                t1 = i;
                break;
            }
        }
        for (i = i + 1; i < length; i++) {
            if (a[i] == ' ') {
                t2 = i;
                break;
            }
        }
        r = getnum(a, 0, t1 - 1);
        c = getnum(a, t1 + 1, t2 - 1);
        j = 0;
        for (i = t2 + 1; i < length; i++) {
            b[j++] = a[i];
        }
        turnnum(b, num, length - t2 - 1, r, c);
        for (i = 0; i < r + 1; i++)
            for (j = 0; j < c + 1; j++)
                out[i][j] = -1;
        addx = 1;
        addy = 1;
        i = 0;
        j = -1;
        count = 0;
        while (count < r * c) {
            while (j + addx < c && j + addx >= 0 && out[i][j + addx] == -1) {
                out[i][j + addx] = num[count++];
                if (count >= r * c)
                    break;
                j = j + addx;
            }
            addx = addx * -1;
            while (i + addy < r && i + addy >= 0 && out[i + addy][j] == -1) {
                out[i + addy][j] = num[count++];
                if (count >= r * c)
                    break;
                i = i + addy;
            }
            addy = addy * -1;
        }
        printf("%d ", counter2);
        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                printf("%d", out[i][j]);
        printf("\n");
    }
    return 0;
}                                 