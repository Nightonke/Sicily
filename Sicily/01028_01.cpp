// Problem#: 1028
// Submission#: 2737296
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <math.h>
#define MAX_LENGTH 105

//通过观察规律可知，位置k上的数就是k可以被而整除的次数+1

int base_index = 9;
long long unit_base = (long long)pow(10, 9);
long long unit[MAX_LENGTH / 9 + 9];
long long per_base[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
char char_a[MAX_LENGTH];
bool is_ok;//

int ready(int length) {
    memset(unit, 0, sizeof(unit));
    int unit_length = length % 9 == 0 ? length / 9 : length / 9 + 1;
    int i, j, k;
    for (i = unit_length - 1, j = length - 1; i >= 0; i--) {
        for (k = 0; j >= 0; j--, k++) {
            if (k == 9)
                break;
            unit[i] += (char_a[j] - '0') * per_base[k];
        }
    }
    return unit_length;
}

int divi(int first_pos, int last_pos) {
    if (unit[last_pos] % 2 == 1) {
        is_ok = false;
        return 0;
    }
    for (int i = first_pos; i <= last_pos; i++) {
        if (unit[i] % 2 == 1) {
            unit[i + 1] += unit_base;
        }
        unit[i] /= 2;
    }
    if (unit[last_pos + 1] > 0) {
        is_ok = false;
        return 0;
    }
    if (unit[first_pos] == 0)
        return first_pos + 1;
    else
        return first_pos;
}

int main() {
    
    int t, i, length, counter, kongzhi = 0, first_pos, j;
    scanf("%d", &t);
    
    for (i = 1; i <= t; i++) {
        
        if (kongzhi)//输出的格式
            printf("\n");
        kongzhi = 1;
        
        memset(char_a, '\0', sizeof(char_a));
        scanf("%s", char_a);
        length = strlen(char_a);
        is_ok = true;
        
        if ((char_a[length - 1] - '0') % 2 == 1) {//假如是单数直接判断
            printf("Case %d: 1\n", i, 1);
            continue;
        }
        
        counter = 0;
        
        if (length <= 20) {//假如小于unsigned long long的最大值18446744073709551615直接判断
            char judge[] = "18446744073709551615";
            if (strcmp(char_a, judge) <= 0 || length <= 19) {
                unsigned long long sum = 0;
                for (j = 0; j < length; j++) {
                    sum = sum * 10 + char_a[j] - '0' ;
                }
                while (sum % 2 == 0) {
                    counter++;
                    sum /= 2;
                }
                printf("Case %d: %d\n", i, counter + 1);
                continue;
            }
        }
        
        int unit_length = ready(length);
        first_pos = 0;
        while (1) {
            first_pos = divi(first_pos, unit_length - 1);
            if (is_ok) {
                counter++;
            } else {
                break;
            }
        }
        printf("Case %d: %d\n", i, counter + 1);
    }
    return 0;
}                                 