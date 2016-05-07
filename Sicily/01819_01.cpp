// Problem#: 1819
// Submission#: 2795801
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <bitset>
using namespace std;
int main() {
    char temp[1010];
    int case_num, i, j, n;
    bool is_ok;
    scanf("%d\n", &case_num);
    while (case_num--) {
        scanf("%d\n", &n);
        bitset<1010> a[1010], b[1010], his_ans[1010];
        for (i = 0; i < n; i++) {
            fgets(temp, sizeof(temp), stdin);
            for (j = 0; j < n; j++) {
                if (temp[j] == '1')
                    a[i].set(j);
            }
        }
        for (i = 0; i < n; i++) {
            fgets(temp, sizeof(temp), stdin);
            for (j = 0; j < n; j++) {
                if (temp[j] == '1')
                    b[j].set(i);//这里注意是在读取的时候就已经倒置了，方便后面的处理
            }
        }
        for (i = 0; i < n; i++) {
            fgets(temp, sizeof(temp), stdin);
            for (j = 0; j < n; j++) {
                if (temp[j] == '1')
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