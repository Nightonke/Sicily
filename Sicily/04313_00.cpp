// Problem#: 4313
// Submission#: 2752577
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string.h>
#include <vector>
#include <queue>
#include <stdio.h>
#include <stack>
#include <math.h>
#include <algorithm>
using namespace std;

bool cmp(const int& a, const int& b) {
    return a > b;
}

int find_pairs(int f_l[], int f_h[], int length_f_l, int length_f_h) {
    int i = 0, j = 0, pairs = 0;
    
    while (i < length_f_l && j < length_f_h) {
        if (-f_l[i] > f_h[j]) {
            pairs++;
            i++;
            j++;
        } else {
            j++;
        }
    }
    
    return pairs;
}

int main() {
    int b_find_l[1001], b_find_h[1001], g_find_l[1001], g_find_h[1001];
    int case_num, n, i, j, k, temp, length_b_l, length_b_h, length_g_l, length_g_h;
    
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        for (i = 0, j = 0, k = 0; i < n; i++) {
            scanf("%d", &temp);
            if (temp > 0)
                b_find_h[j++] = temp;
            else
                b_find_l[k++] = temp;
        }
        
        sort(b_find_l, b_find_l + k);
        length_b_l = k;
        sort(b_find_h, b_find_h + j, cmp);
        length_b_h = j;
        
        for (i = 0, j = 0, k = 0; i < n; i++) {
            scanf("%d", &temp);
            if (temp > 0)
                g_find_h[j++] = temp;
            else
                g_find_l[k++] = temp;
        }
        
        sort(g_find_l, g_find_l + k);
        length_g_l = k;
        sort(g_find_h, g_find_h + j, cmp);
        length_g_h = j;
        
        printf("%d\n", find_pairs(b_find_l, g_find_h, length_b_l, length_g_h) + find_pairs(g_find_l, b_find_h, length_g_l, length_b_h));
    }
    return 0;
}                                 