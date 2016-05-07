// Problem#: 1222
// Submission#: 3588494
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1222
// Submission#: 3587761
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int n, m;
char word[10010][15];
int point[10010];
int Index[100010];
int mark[10010];

int find(char * s) {
    int first, last, mid, temp;
    first = 0;
    last = n - 1;
    while (first <= last) {
        mid = (first + last) / 2;
        temp = strcmp(s, word[point[mid]]);
        if (temp == 0) return mid;
        else if (temp < 0) last = mid - 1;
        else first = mid + 1;
    }
    return -1;
}

bool cmp(const int & p1, const int & p2) {
    return strcmp(word[p1], word[p2]) < 0;
}

void init() {
    int i;
    char s[20];
    scanf("%d", &n);
    for (i = 0; i < n; i++) scanf("%s", word[i]);
    for (i = 0; i < n; i++) point[i] = i;
    sort(point, point + n, cmp);
    scanf("%d", &m);
    for (i = 0; i < m; i++) {
        scanf("%s", s);
        Index[i] = find(s);
    }
    memset(mark, 0, sizeof(mark));
}

void work() {
    int first, last, total, Min;
    first = 0;
    last = 0;
    total = Min = 0;
    while (last < m) {
        if (Index[last] >= 0) {
            if (mark[Index[last]] == 0) {
                total++;
                Min = last - first + 1;
            }
            mark[Index[last]]++;
        }
        while (first <= last)
            if ((Index[first] >= 0 && mark[Index[first]] > 1) || Index[first] < 0) {
                mark[Index[first]]--;
                first++;
            } else break;
        if (last - first + 1 < Min) Min = last - first + 1;
        last++;
    }
    printf("%d\n%d\n", total, Min);
}

int main() {
    init();
    work();
    return 0;
}                                 