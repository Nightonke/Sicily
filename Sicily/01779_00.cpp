// Problem#: 1779
// Submission#: 2739300
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1779
// Submission#: 2700027
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>

int base_index = 9;//基数为10的9次方
long long unit_base = (long long)pow(10, 9);//基数大小
long long unit[2500];//基数为10^9的最大长度数组
long long per_base[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};//构建unit数组用到的
long long a1[2500], a2[2500], a3[2500]; 
int length_a1, length_a2, length_f1, length_f2, ans_length;
char f1[11], f2[11];

int get_length(int length_f) {
    return length_f % 9 == 0 ? length_f / 9 : length_f / 9 + 1;
}

void ready() {//转化数组
    int i, j, k;
    
    memset(a1, 0, sizeof(a1));
    memset(a2, 0, sizeof(a2));
    memset(a3, 0, sizeof(a3));
    
    length_a1 = get_length((int)strlen(f1));
    length_a2 = get_length((int)strlen(f2));
    
    for (i = 0, j = (int)strlen(f1) - 1; i < length_a1; i++) {
        for (k = 0; k < 9 && j >= 0; k++) {
            a1[i] += per_base[k] * (f1[j--] - '0');
        }
    }
    for (i = 0, j = (int)strlen(f2) - 1; i < length_a2; i++) {
        for (k = 0; k < 9 && j >= 0; k++) {
            a2[i] += per_base[k] * (f2[j--] - '0');
        }
    }
}

void multi() {
    int max_length_a3, i, j;
    
    for (length_a1 = 2500 - 1; length_a1 > 0 && a1[length_a1] == 0; length_a1--);//判断两个乘数的长度
    for (length_a2 = 2500 - 1; length_a2 > 0 && a2[length_a2] == 0; length_a2--);
    length_a1++;
    length_a2++;
    
    max_length_a3 = length_a1 + length_a2;
    memset(a3, 0, sizeof(a3));
    
    for (i = 0; i <= length_a1; i++) {//高精度乘法
        for (j = 0; j <= length_a2; j++) {
            a3[i + j] += a1[i] * a2[j];
            a3[i + j + 1] += a3[i + j] / unit_base;
            a3[i + j] %= unit_base;
        }
    }
    
    memset(a1, 0, sizeof(a1));
    for (i = 0; i <= length_a2; i++) {
        a1[i] = a2[i];
    }
    
    memset(a2, 0, sizeof(a2));
    for (i = 0; i <= max_length_a3; i++) {
        a2[i] = a3[i];
    }
    
}

int check_length_a2() {//判断当前长度
    int i, k;
    for (i = 2500 - 1; i > 0 && a2[i] == 0; i--);
    for (k = 8; k >= 0; k--) {
        if (a2[i] >= per_base[k]) {
            break;
        }
    }
    ans_length = i + 1;
    return i * 9 + k + 1;
}

void print(int i) {
    int k;
    if (a2[i] == 0) {
        printf("000000000");
        return;
    }
    for (k = 8; k >= 0 && a2[i] != 0; k--) {
        if (a2[i] >= per_base[k]) {
            break;
        }
    }
    k = 8 - k;
    while (k--) {
        printf("0");
    }
    printf("%lld", a2[i]);
}
    
int main() {
    int t, temp, n, i;
    scanf("%d", &t);
    while (t--) {
        memset(f1, '\0', sizeof(f1));
        memset(f2, '\0', sizeof(f2));
        scanf("%s %s %d", f1, f2, &n);
        
        
        if (n == 1) {//各种预先判断
            printf("%s\n", f1);
            continue;
        }
        if (n == 2) {
            printf("%s\n", f2);
            continue;
        }
        if (f1[0] == '1' && f1[1] == '\0' && f2[0] == '1' && f2[1] == '\0') {
            printf("1\n");
            continue;
        }
        
        if (n >= 20) {//当n达到20就会爆
            printf("Ooops!\n");
            continue;
        }
        
        ready();
        n = n - 2;
        
        while (1) {
            temp = check_length_a2();
            if (!(temp <= 1000 && n--))
                break;
            multi();
        }
        
        if (temp <= 1000) {
            for (i = ans_length - 1; i >= 0; i--) {
                if (i != ans_length - 1) {
                    print(i);
                } else {
                    printf("%lld", a2[i]);
                }
            }
            printf("\n");
        } else {
            printf("Ooops!\n");
        }
    }
    return 0;
}                                 