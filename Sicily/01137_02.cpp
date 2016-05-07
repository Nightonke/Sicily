// Problem#: 1137
// Submission#: 2582637
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>
int a[30001];

int findmax(int i, int j) {
    int max = a[i];
    for (int k = i; k <= j; k++)
        if (max < a[k])
            max = a[k];
    return max;
}

int findmin(int i, int j) {
    int min = a[i];
    for (int k = i; k <= j; k++)
        if (min > a[k])
            min = a[k];
    return min;
}

int main() {
    int n, cha, i, j, b[30001], max, counter, min, max1;
    scanf("%d %d", &n, &cha);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);
    for (i = 0; i < n; i++) {
        max = min = a[i];
        for (j = i + 1, counter = 1; j < n; j++) {
            min = findmin(i, j);
            max = findmax(i, j);
            if (max - min > cha)
                break;
            counter++;
        }
        b[i] = counter;
    }
    max1 = b[0];
    for (i = 1; i < n; i++)
        if (b[i] > max1)
            max1 = b[i];
    printf("%d\n", max1);
    return 0;
}                                 