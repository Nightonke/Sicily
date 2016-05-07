// Problem#: 1202
// Submission#: 2826738
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

int day_in_months[13][2] = {0, 0, 31, 31, 28, 29, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31, 31, 31, 30, 30, 31, 31, 30, 30, 31, 31};

bool is_leap_year(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

int main() {
    int n;
    scanf("%d", &n);
    for (int nn = 1; nn <= n; nn++) {
        
        int m1, d1, y1, m2, d2;
        scanf("%d/%d/%d %d/%d", &m1, &d1, &y1, &m2, &d2);
        
        if (m1 == m2 && d1 == d2) {
            printf("%d SAME DAY\n", nn);
            continue;
        }
        
        int leap_year;
        if (is_leap_year(y1)) {
            leap_year = 1;
        } else {
            leap_year = 0;
        }
        bool is_ok = false;
        
        //increasing
        int td = d1, tm = m1, ty = y1;
        for (int i = 1; i <= 7 && !is_ok; i++) {
            td++;
            if (td > day_in_months[tm][leap_year]) {
                tm++;
                if (tm > 12) {
                    tm = 1;
                    ty++;
                }
                td = 1;
            }
            if (td == d2 && tm == m2) {
                is_ok = true;
                printf("%d ", nn);
                printf("%d/%d/%d IS %d DAY", m2, d2, ty, i);
                if (i != 1) {
                    printf("S ");
                } else {
                    printf(" ");
                }
                printf("AFTER\n");
                break;
            }
        }
        
        //decreasing
        td = d1, tm = m1, ty = y1;
        for (int i = 1; i <= 7 && !is_ok; i++) {
            td--;
            if (td < 1) {
                tm--;
                if (tm < 1) {
                    tm = 12;
                    ty--;
                }
                td = day_in_months[tm][leap_year];
            }
            if (td == d2 && tm == m2) {
                is_ok = true;
                printf("%d ", nn);
                printf("%d/%d/%d IS %d DAY", m2, d2, ty, i);
                if (i != 1) {
                    printf("S ");
                } else {
                    printf(" ");
                }
                printf("PRIOR\n");
                break;
            }
        }
        
        if (!is_ok) {
            printf("%d OUT OF RANGE\n", nn);
        }
        
    }
    return 0;
}                                 