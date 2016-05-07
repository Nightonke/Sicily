// Problem#: 9993
// Submission#: 2746175
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

struct MAN {
    char choice[50];
    int point;
    int num;
}man[105];

bool cmp(const MAN& a, const MAN& b) {
    return a.point <= b.point;
}

int main() {
    char temp[50];
    int case_num, i, j, k, m, q;
    scanf("%d\n", &case_num);
    for (k = 1; k <= case_num; k++) {
        scanf("%d\n", &m);
        for (i = 0; i < m; i++) {
            man[i].point = 0;
            man[i].num = i;
            cin.getline(temp, 50);
            for (j = 0, q = 0; j < (int)strlen(temp); j++) {
                if (temp[j] <= 'Z' && temp[j] >= 'A')
                    man[i].choice[q++] = temp[j];
            }
        }
        
        char answer[50];
        cin.getline(temp, 50);
        for (j = 0, q = 0; j < (int)strlen(temp); j++) {
            if (temp[j] <= 'Z' && temp[j] >= 'A')
                answer[q++] = temp[j];
        }
        
        for (i = 0; i < m; i++) {
            for (j = 0; j < (int)strlen(answer) && j < (int)strlen(man[i].choice); j++) {
                if (answer[j] <= 'Z' && answer[j] >= 'A' && man[i].choice[j] == answer[j])
                    man[i].point++;
            }
        }
        
        sort(man, man + m, cmp);
        
        printf("test case %d:\n", k);
        
        for (i = 0; i < m; i++) {
            printf("Student %d: %d\n", man[i].num, man[i].point);
        }
    }
    return 0;
}                                 