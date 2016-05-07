// Problem#: 1826
// Submission#: 3589617
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

struct T {
    long long leftx, rightx, area;
    bool deleted;
};

long long testcase, n, x, y;
T list[100010];

bool cmp(const T & t1, const T & t2) {
    return t1.leftx < t2.leftx;
}

int main() {
    scanf("%lld", &testcase);
    while (testcase--) {
        memset(list, 0, sizeof(list));
        scanf("%lld", &n);
        for (int i = 0; i < n; i++) {
            scanf("%lld%lld", &x, &y);
            list[i].leftx = x - y;
            list[i].rightx = x + y;
            list[i].area = y * y;
        }
        sort(list, list + n, cmp);
        long long result = 0;
        for (int i = 0; i < n; i++)
            if (!list[i].deleted) {
                result += list[i].area * 4;
                for (int j = i + 1; j < n && list[j].leftx < list[i].rightx; j++) {
                    if (!list[j].deleted && list[j].rightx <= list[i].rightx)
                        list[j].deleted = true;
                    else {
                        result -= (list[j].leftx - list[i].rightx) * (list[j].leftx - list[i].rightx);
                        break;
                    }
                }
            }
        long long result1 = result / (long long)4, result2 = result % (long long)4;
        if (result1 == 0) printf("0");
        else printf("%lld", result1);
        if (result2 == 1) printf(".25");
        else if (result2 == 2) printf(".50");
        else if (result2 == 3) printf(".75");
        else printf(".00");
        printf("\n");
    }
    return 0;
}                                 