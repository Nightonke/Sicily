// Problem#: 1934
// Submission#: 2759650
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int l[500005], r[500005];

void do_order(int order_num) {
    int kind, x, y;
    while (order_num--) {
        scanf("%d%d%d", &kind, &x, &y);
        
        r[l[x]] = r[x];
        l[r[x]] = l[x];
        
        if (kind == 1) {
            r[l[y]] = x;
            l[x] = l[y];
            l[y] = x;
            r[x] = y;
        } else {
            l[r[y]] = x;
            r[x] = r[y];
            r[y] = x;
            l[x] = y;
        }
    }
}



void print(int n) {
    
    int temp = 0;
    while (n--) {
        
        temp = r[temp];
        printf("%d ", temp);
        
    }
    printf("\n");
}

int main() {
    int case_num, n, order_num;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d%d", &n, &order_num);
        r[0] = 1;
        for (int i = 1; i <= n; i++) {
            l[i] = i - 1;
            r[i] = i + 1;
        }
        do_order(order_num);
        print(n);
    }
    return 0;
}                                 