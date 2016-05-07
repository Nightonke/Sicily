// Problem#: 1001
// Submission#: 2739693
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

bool is_letter(char front, char back) {//判断当前字符能否与前面的字符组成新字符
    if (front >= '3' || front == '0')//注意不会有01表示A的情况（不出现前导零）
        return false;
    else if (front =='1')
        return true;
    else if (back > '6')
        return false;
    else
        return true;
}

int main() {
    
    char num[10000];
    int i;
    long long code_num[10000];
    
    while (scanf("%s", num) && num[0] != '0') {
        
        memset(code_num, 0, sizeof(code_num));
        
        code_num[0] = 1;
        if (is_letter(num[0], num[1]) && num[1] != '0') {//特殊处理，注意当num[1] == '0'的时候只能跟前面的字符组成新字符，不能单独表示字符
            code_num[1] = 2;
        } else {
            code_num[1] = 1;
        }
        
        for (i = 2; i < (int)strlen(num); i++) {
            if (num[i] == '0')//假如是零必然要跟前面的组成新字符，相当于处理num[i - 1]的时候num[i - 1]只能单独表示一个字符的情况
                code_num[i] = code_num[i - 2];
            else if (is_letter(num[i - 1], num[i]))//假如可以，一种是单独字符，一种是组合字符
                code_num[i] = code_num[i - 2] + code_num[i - 1];
            else//这是只能单独字符的情况
                code_num[i] = code_num[i - 1];
        }
        printf("%lld\n", code_num[(int)strlen(num) - 1]);
    }
    return 0;
}                                 