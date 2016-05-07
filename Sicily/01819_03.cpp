// Problem#: 1819
// Submission#: 2795787
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <bitset>
using namespace std;
int main() {
    char temp;
    int case_num, i, j, n;
    bool is_ok;
    scanf("%d", &case_num);
    while (case_num--) {
        scanf("%d", &n);
        bitset<1010> a[1010], b[1010], his_ans[1010];
        for (i = 0; i < n; i++) {
            a[i].reset();
            b[i].reset();
            his_ans[i].reset();
        }
        
        for (i = 0; i < n; i++) {
            getchar();
            for (j = 0; j < n; j++) {
                temp = getchar();
                if (temp == '1')
                    a[i].set(j);
            }
        }
        for (i = 0; i < n; i++) {
            getchar();
            for (j = 0; j < n; j++) {
                temp = getchar();
                if (temp == '1')
                    b[j].set(i);
            }
        }
        for (i = 0; i < n; i++) {
            getchar();
            for (j = 0; j < n; j++) {
                temp = getchar();
                if (temp == '1')
                    his_ans[i].set(j);
            }
        }
        is_ok = true;
        for (i = 0; i < n && is_ok; i++) {
            for (j = 0; j < n && is_ok; j++) {
                if ((a[i] & b[j]).count() % 2) {
                    if (his_ans[i][j] == 0) {
                        is_ok = false;
                        break;
                    }
                } else {
                    if (his_ans[i][j] == 1) {
                        is_ok = false;
                        break;
                    }
                }
            }
        }
        if (is_ok)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}                                 