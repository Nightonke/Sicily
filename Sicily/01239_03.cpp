// Problem#: 1239
// Submission#: 2797346
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    int maxx, minn, min_dif, head_dif, head[10][2], head_num, case_num, i, j, k, num_count, num[11], length_minn, length_maxx;
    char temp[25];
    scanf("%d\n", &case_num);
    while (case_num--) {
        gets(temp);
        for (i = head_num = 0, min_dif = head_dif = 99999999, num_count = 0; i < (int)strlen(temp); i += 2) {
            num[i / 2] = temp[i] - '0';
            num_count++;
        }
        if (num_count % 2) {
            for (i = 2, j = num_count - 2, maxx = num[0] ? num[0] * 10 + num[1] : num[1] * 10, minn = num[num_count - 1]; i < j; i++, j--) {
                maxx = maxx * 10 + num[i];
                minn = minn * 10 + num[j];
            }
            printf("%d\n", maxx - minn);
        } else {
            for (i = 0; i < num_count - 1; i++) {
                head_dif = (num[i + 1] - num[i] < head_dif && num[i]) ? num[i + 1] - num[i] : head_dif;
            }
            for (i = 0; i < num_count - 1; i++) {
                if (num[i + 1] - num[i] == head_dif && num[i]) {
                    head[head_num][0] = num[i];
                    head[head_num++][1] = num[i + 1];
                }
            }
            for (i = 0; i < head_num; i++) {
                minn = head[i][0];
                maxx = head[i][1];
                length_minn = length_maxx = num_count / 2 - 1;
                for (j = 0, k = num_count - 1; length_minn || length_maxx; j++, k--) {
                    if (num[k] != head[i][0] && num[k] != head[i][1] && length_minn) {
                        minn = minn * 10 + num[k];
                        length_minn--;
                    }
                    if (num[j] != head[i][1] && num[j] != head[i][0] && length_maxx) {
                        maxx = maxx * 10 + num[j];
                        length_maxx--;
                    }
                }
                min_dif = maxx - minn < min_dif ? maxx - minn : min_dif;
            }
            printf("%d\n", num_count == 2 ? num[1] - num[0] : min_dif);
        }
    }
    return 0;
}                                 