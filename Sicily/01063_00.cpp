// Problem#: 1063
// Submission#: 2744383
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct People {
    int id, salary, height, boss, subordinates;
}p[30005];

bool cmp_salary(const People& a, const People& b) {
    return a.salary <= b.salary;
}

bool cmp_id(const People& a, const People &b) {
    return a.id <= b.id;
}

int find(int target, int front, int back) {
    if (front <= back) {
        int mid = (front + back) / 2;
        if (p[mid].id == target)
            return mid;
        else if (target < p[mid].id)
            return find(target, front, mid - 1);
        else
            return find(target, mid + 1, back);
    }
    else return 0;
}

int main() {
    int case_num, p_num, q_num, i, j, target, pos;
    
    scanf("%d", &case_num);
    
    while (case_num--) {
        scanf("%d%d", &p_num, &q_num);
        for (i = 0; i < p_num; i++) {
            scanf("%d%d%d", &p[i].id, &p[i].salary, &p[i].height);
            p[i].boss = 0;
            p[i].subordinates = 0;
        }
        
        sort(p, p + p_num, cmp_salary);
        
        for (i = 0; i < p_num; i++) {
            for (j = i + 1; j < p_num; j++) {
                if (p[j].height >= p[i].height) {
                    p[j].subordinates += p[i].subordinates + 1;
                    p[i].boss = p[j].id;
                    break;
                }
            }
        }
        
        sort(p, p + p_num, cmp_id);
        
        while (q_num--) {
            scanf("%d", &target);
            pos = find(target, 0, p_num - 1);
            printf("%d %d\n", p[pos].boss, p[pos].subordinates);
        }
    }
    return 0;
}                                 