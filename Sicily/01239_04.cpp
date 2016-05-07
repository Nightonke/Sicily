// Problem#: 1239
// Submission#: 2797202
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 999999

bool num_to_used[10];//可以用的数字
int used_num;//可以用的数字的多少
int minn[10][2];//开头的最小差值组合
int min_num;//开头的最小差值组合的树目

void find_min() {
    int miinn = INF;
    min_num = 0;
    for (int i = 0; i < 10; i++) {//找到可以达到的开头最小差值
        for (int j = i + 1; j < 10; j++) {
            if (num_to_used[i] && num_to_used[j] && j - i < miinn && i != 0) {
                miinn = j - i;
            }
        }
    }
    for (int i = 0; i < 10; i++) {//构造开头最小差值组合
        for (int j = i + 1; j < 10; j++) {
            if (num_to_used[i] && num_to_used[j] && (j - i == miinn) && i != 0) {
                minn[min_num][0] = i;
                minn[min_num][1] = j;
                min_num++;
            }
        }
    }
}
    
int do_two() {
    find_min();
    int min_dif = INF;
    int j;
    int temp1[10], temp2[10];
    int permutation[11];
    int tem1, tem2;
    for (int i = 0; i < used_num - 2; i++) {//排列数组
        permutation[i] = i;
    }
    for (int i = 0; i < min_num; i++) {
        temp1[0] = minn[i][0];//两个数字的开头
        temp2[0] = minn[i][1];
        int rest[11];//剩下可以用的数字
        int k = 0;
        for (j = 0; j < 10; j++) {//找到剩下可以用的数字
            if (j != temp1[0] && j != temp2[0] && num_to_used[j]) {
                rest[k++] = j;
            }
        }
        int rest_num = k;
        //下面就是构造这两个数字了
        for (j = 0, tem1 = temp1[0], k = 1; j < rest_num / 2; j++, k++) {
            temp1[k] = rest[permutation[j]];
            tem1 = tem1 * 10 + temp1[k];
        }
        for (j = rest_num / 2, k = 1, tem2 = temp2[0]; j < rest_num; j++, k++) {
            temp2[k] = rest[permutation[j]];
            tem2 = tem2 * 10 + temp2[k];
        }
        if ((int)fabs(tem1 - tem2) < min_dif) {
            min_dif = (int)fabs(tem1 - tem2);
        }
        
        while (next_permutation(permutation, permutation + rest_num)) {//变换排列并构造数字，更新差值
            for (j = 0, tem1 = temp1[0], k = 1; j < rest_num / 2; j++, k++) {
                temp1[k] = rest[permutation[j]];
                tem1 = tem1 * 10 + temp1[k];
            }
            for (j = rest_num / 2, k = 1, tem2 = temp2[0]; j < rest_num; j++, k++) {
                temp2[k] = rest[permutation[j]];
                tem2 = tem2 * 10 + temp2[k];
            }
            if ((int)fabs(tem1 - tem2) < min_dif) {
                min_dif = (int)fabs(tem1 - tem2);
            }
        }
    }
    return min_dif;
}

int do_one() {
    int min_dif = INF;
    int min_head, max_head;
    int i, j, k = 0;
    for (int i = 1; i < 10; i++) {
        if (num_to_used[i]) {
            min_head = i;
            break;
        }
    }
    for (int i = 9; i > 0; i--) {
        if (num_to_used[i]) {
            max_head = i;
            break;
        }
    }
    int permutation[11];
    for (i = 0; i < used_num - 2; i++) {
        permutation[i] = i;
    }
    int rest[10];
    int temp1[10], temp2[10];
    temp1[0] = min_head;
    temp2[0] = max_head;
    int tem1;
    int tem2;
    for (j = 0; j < 10; j++) {
        if (j != temp1[0] && j != temp2[0] && num_to_used[j]) {
            rest[k++] = j;
        }
    }
    int rest_num = k;
    for (j = 0, k = 1, tem1 = temp1[0]; j < rest_num / 2 + 1; j++, k++) {
        temp1[k] = rest[permutation[j]];
        tem1 = tem1 * 10 + temp1[k];
    }
    for (j = rest_num / 2 + 1, k = 1, tem2 = temp2[0]; j < rest_num; j++, k++) {
        temp2[k] = rest[permutation[j]];
        tem2 = tem2 * 10 + temp2[k];
    }
    if ((int)fabs(tem1 - tem2) < min_dif) {
        min_dif = (int)fabs(tem1 - tem2);
    }
    while (next_permutation(permutation, permutation + rest_num)) {
        for (j = 0, k = 1, tem1 = temp1[0]; j < rest_num / 2 + 1; j++, k++) {
            temp1[k] = rest[permutation[j]];
            tem1 = tem1 * 10 + temp1[k];
        }
        for (j = rest_num / 2 + 1, k = 1, tem2 = temp2[0]; j < rest_num; j++, k++) {
            temp2[k] = rest[permutation[j]];
            tem2 = tem2 * 10 + temp2[k];
        }
        if ((int)fabs(tem1 - tem2) < min_dif) {
            min_dif = (int)fabs(tem1 - tem2);
        }
    }
    return min_dif;
}

int main() {
    int case_num;
    scanf("%d\n", &case_num);
    while (case_num--) {
        char temp[25];
        memset(num_to_used, false, sizeof(num_to_used));
        gets(temp);
        used_num = 0;
        for (int i = 0; temp[i] != '\0'; i++) {
            if (temp[i] != ' ') {
                num_to_used[temp[i] - '0'] = true;
                used_num++;
            }
        }
        if (used_num == 2) {//只有两个直接输出即可
            printf("%d\n", (int)fabs(temp[0] - temp[2]));
            continue;
        }
        if (used_num % 2 == 0) {//单双数分别处理
            printf("%d\n", do_two());
        } else {
            printf("%d\n", do_one());
        }
    }
    return 0;
}                                 