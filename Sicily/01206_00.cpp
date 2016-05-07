// Problem#: 1206
// Submission#: 2586958
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

void swap(float *a, float *b) {
    float temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void sort(float a[], int n) {
    int i, j;
    for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1])
                swap(&a[j], &a[j + 1]);
}

int main() {
    float a[100], y;
    int n, i, counter = 1, t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (i = 0; i < n; i++)
        {    
            scanf("%f", &a[i]);
        }
        y = 1;
        sort(a, n);
        for (i = 0; i < n - 1; i++)
            y += sqrt(4 - (a[i + 1] - a[i]) * (a[i + 1] - a[i]) / 4);
        printf("%d: %.4f %.4f\n", counter++, (a[0] + a[n - 1]) / 2, y);
    }
    return 0;
}                                 