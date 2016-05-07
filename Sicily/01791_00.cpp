// Problem#: 1791
// Submission#: 2699644
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct time {
    int y;
    int m;
    int d;
    int is_Sunday;
};

time t[11000];

int get_days(int year, int month) {
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    if (month == 4 || month == 6 || month == 9 || month == 11)
        return 30;
    if (month == 2) {
        if (year % 100 != 0 && year % 4 == 0)
            return 29;
        if (year % 100 == 0 && year % 400 == 0)
            return 29;
        return 28;
    }
}

void make_time() {
    int u = 0, i, j, k, days;
    for (i = 1986; i <= 2012; i++) {
        for (j = 1; j <= 12; j++) {
            days = get_days(i, j);
            for (k = 1; k <= days; k++) {
                t[u].y = i;
                t[u].m = j;
                t[u++].d = k;
            }
        }
    }
}

void make_Sunday() {
    int counter = 0, i;
    for (i = 4; i < 11000; i++, counter++) {
        if (counter % 7 == 0)
            t[i].is_Sunday = 1;
        else
            t[i].is_Sunday = 0;
    }
}
    
void search_Sunday(int pos) {
    int i;
    for (i = pos + 1; i < pos + 10; i++) {
        if (t[i].is_Sunday) {
            if (t[i].m <= 9)
                printf("0%d ", t[i].m);
            else
                printf("%d ", t[i].m);
            if (t[i].d <= 9)
                printf("0%d ", t[i].d);
            else
                printf("%d ", t[i].d);
            printf("%d\n", t[i].y);
            break;
        }
    }
}

int main() {
    int n, tm, td, ty, i;
    make_time();
    make_Sunday();
    scanf("%d", &n);
    while (n--) {
        scanf("%d %d %d", &tm, &td, &ty);
        for (i = 0; ; i++) {
            if (t[i].y == ty && t[i].m == tm && t[i].d == td) {
                if (t[i].is_Sunday) {
                    if (t[i + 7].m <= 9)
                        printf("0%d ", t[i + 7].m);
                    else
                        printf("%d ", t[i + 7].m);
                    if (t[i + 7].d <= 9)
                        printf("0%d ", t[i + 7].d);
                    else
                        printf("%d ", t[i + 7].d);
                    printf("%d\n", t[i + 7].y);
                } else {
                    search_Sunday(i);
                }
                break;
            }
        }
    }
    return 0;
}                                 