// Problem#: 3912
// Submission#: 2368005
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int t, m, d, tianshu, cha;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &m, &d);
        switch (m) {
        case 1:
                tianshu = 0;
                break;
        case 2:
                tianshu = 31;
                break;
        case 3:
                tianshu = 59;
                break;
        case 4:
                tianshu = 90;
                break;
        case 5:
                tianshu = 120;
                break;
        case 6:
                tianshu = 151;
                break;
        case 7:
                tianshu = 181;
                break;
        case 8:
                tianshu = 212;
                break;
        case 9:
                tianshu = 243;
                break;
        case 10:
                tianshu = 273;
                break;
        case 11:
                tianshu = 304;
                break;
        case 12:
                tianshu = 334;
                break;
        }
        tianshu = tianshu + d;
        cha = (tianshu - 1) % 7;
        if (cha == 0)
            printf("Saturday\n");
        if (cha == 1)
            printf("Sunday\n");
        if (cha == 2)
            printf("Monday\n");
        if (cha == 3) 
            printf("Tuesday\n");
        if (cha == 4)
            printf("Wednesday\n");
        if (cha == 5)
            printf("Thursday\n");
        if (cha == 6)
            printf("Friday\n");
    }
    return 0;
}                                 