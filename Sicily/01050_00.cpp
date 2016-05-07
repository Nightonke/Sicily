// Problem#: 1050
// Submission#: 2745819
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1050
// Submission#: 2745612
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int target, max_possi;
bool is_ok;

int add(int a, int b) {return a + b;}

int sub_posi(int a, int b) {return a > b ? a - b : b - a;}

int sub_nega(int a, int b) {return a < b ? a - b : b - a;}

int mul(int a, int b) {return a * b;}

int divi(int a, int b) {
    if ((b == 0 && a != 0) || (a == 0 && b != 0))
        return 0;
    else if (a == 0 && b == 0)
        return 99999999;
    else {
        int aa = a > 0 ? a : -a;
        int bb = b > 0 ? b : -b;
        if (aa % bb == 0)
            return a / b;
        else if (bb % aa == 0)
            return b / a;
        else
            return 99999999;
    }
}

void dfs(int a[], int size) {
    int i, j, k, b[5] = {0}, k1;
    for (i = 0; i < size; i++) {
        if (a[i] == target) {
            is_ok = true;
            return;
        } else {
            if (a[i] > max_possi && a[i] <= target) {
                max_possi = a[i];
            }
        }
    }
    
    if (size == 1) {
        if (a[0] > max_possi && a[0] <= target) {
            max_possi = a[0];
            return;
        }
    }
    
    for (i = 0; i < size; i++) {
        for (j = i + 1; j < size; j++) {
            
            b[0] = add(a[i], a[j]);
            for (k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j)
                    b[k1++] = a[k];
            }
            dfs(b, size - 1);
            if (is_ok)
                return;
            
            b[0] = sub_posi(a[i], a[j]);
            for (k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j)
                    b[k1++] = a[k];
            }
            dfs(b, size - 1);
            if (is_ok)
                return;
            
            b[0] = sub_nega(a[i], a[j]);
            for (k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j)
                    b[k1++] = a[k];
            }
            dfs(b, size - 1);
            if (is_ok)
                return;
            
            b[0] = mul(a[i], a[j]);
            for (k1 = 1, k = 0; k < size; k++) {
                if (k != i && k != j)
                    b[k1++] = a[k];
            }
            dfs(b, size - 1);
            if (is_ok)
                return;
            
            b[0] = divi(a[i], a[j]);
            if (b[0] != 99999999) {
                for (k1 = 1, k = 0; k < size; k++) {
                    if (k != i && k != j)
                        b[k1++] = a[k];
                }  
                dfs(b, size - 1);
                if (is_ok)
                    return;
            }
        }
    }
}

int main() {
    int case_num, i, num[5];
    scanf("%d", &case_num);
    while (case_num--) {
        for (i = 0; i < 5; i++) {
            scanf("%d", &num[i]);
        }
        scanf("%d", &target);
        max_possi = -99999999;
        is_ok = false;
        dfs(num, 5);
        if (is_ok)
            printf("%d\n", target);
        else
            printf("%d\n", max_possi);
    }
    return 0;
}                                 