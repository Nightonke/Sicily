// Problem#: 1405
// Submission#: 2773720
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

struct name {
    char a[85];
};

bool cmp(const name& aa, const name& bb) {
    return strlen(aa.a) < strlen(bb.a);
}

int main() {
    int control_case = 0, n, k;
    bool is_ok, control_blank = false;
    while (scanf("%d %d", &n, &k) && n && k) {
        scanf("\n");
        is_ok = true;
        name nn[n];
        for (int i = 0; i < n; i++) {
            gets(nn[i].a);
        }
        
        sort(nn, nn + n, cmp);
        
        /*
        for (int i = 0; i < n; i++) {
            printf("%s\n", nn[i].a);
        }
        */
        
        int sum;
        for (int i = 0; i < n && is_ok; i += k) {
            sum = 0;
            for (int j = i; j < i + k; j++) {
                sum += (int)strlen(nn[j].a);
            }
            for (int j = i; j < i + k; j++) {
                if ((int)strlen(nn[j].a) > sum / k + 2) {
                    is_ok = false;
                    break;
                }
            }
        }
        if (control_blank)
            printf("\n");
        control_blank = true;
        control_case++;
        printf("Case %d: ", control_case);
        if (is_ok)
            printf("yes\n");
        else
            printf("no\n");
    }
    return 0;
}                                 