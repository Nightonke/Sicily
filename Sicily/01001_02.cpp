// Problem#: 1001
// Submission#: 2739509
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string.h>
using namespace std;

bool is_letter(char front, char back) {
    if (front >= '3' || front == '0')
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
    while (cin >> num && num[0] != '0') {
        memset(code_num, 0, sizeof(code_num));
        code_num[0] = 1;
        if (is_letter(num[0], num[1]) && num[1] != '0') {
            code_num[1] = 2;
        } else {
            code_num[1] = 1;
        }
        for (i = 2; i < (int)strlen(num); i++) {
            if (num[i] == '0')
                code_num[i] = code_num[i - 2];
            else if (is_letter(num[i - 1], num[i]))
                code_num[i] = code_num[i - 2] + code_num[i - 1];
            else
                code_num[i] = code_num[i - 1];
        }
        cout << code_num[(int)strlen(num) - 1] << endl;
    }
    return 0;
}                                 