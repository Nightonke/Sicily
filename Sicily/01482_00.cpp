// Problem#: 1482
// Submission#: 2517747
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
struct people{
    int xuehao;
    int yu;
    int shu;
    int ying;
    int zong;
}stu[10000];
int main() {
    int konghang = 0, n, i, max, jilu, j, counter, k;
    people zj;
    while (1) {
        if (scanf("%d", &n) != 1)
            break;
        for (i = 0; i < n; i++) {
            stu[i].xuehao = i + 1;
            scanf("%d %d %d", &stu[i].yu, &stu[i].shu, &stu[i].ying);
            stu[i].zong = stu[i].yu + stu[i].shu + stu[i].ying;
        }
        for (i = 0; i < n - 1; i++) {
            max = stu[i].zong;
            jilu = i;
            for (j = i + 1; j < n; j++) {
                if (stu[j].zong > max) {
                    max = stu[j].zong;
                    jilu = j;
                }
            }
            zj = stu[jilu];
            stu[jilu] = stu[i];
            stu[i] = zj;
        }
        for (i = 0; i < n - 1; i++) {
            max = stu[i].yu;
            jilu = i;
            for (j = i + 1; j < n && stu[i].zong == stu[j].zong; j++) {
                if (stu[j].yu > max) {
                    max = stu[j].yu;
                    jilu = j;
                }
            }
            zj = stu[jilu];
            stu[jilu] = stu[i];
            stu[i] = zj;
        }
        if (konghang)
            printf("\n");
        for (i = 0; i < 5; i++) {
            printf("%d %d\n", stu[i].xuehao, stu[i].zong);
        }
        konghang = 1;
    }
    return 0;
}                                 