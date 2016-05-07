// Problem#: 9994
// Submission#: 2746011
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct MAN {
    int hours;
    int num;
}man[105];

bool cmp(const MAN& a, const MAN& b) {
    return a.hours > b.hours;
}

int main() {
    int case_num, i, j, k, m, temp;
    scanf("%d", &case_num);
    for (k = 1; k <= case_num; k++) {
        scanf("%d", &m);
        for (i = 0; i < m; i++) {
            man[i].hours = 0;
            man[i].num = i;
            for (j = 0; j < 7; j++) {
                scanf("%d", &temp);
                man[i].hours += temp;
            }
        }
        
        sort(man, man + m, cmp);
        
        printf("test case %d:\n", k);
        for (i = 0; i < m; i++) {
            printf("Employee %d: %d\n", man[i].num, man[i].hours);
        }
    }
    return 0;
}                                 