// Problem#: 1740
// Submission#: 3584674
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

template<class type>
class minwintree {
  public:
    minwintree(type maxtype, int n);
    ~minwintree() {delete []object; delete []prewin;}
    int getminindex() {return prewin[1];}
    type getminobject() {return object[prewin[1]];}
    int getsecondminindex() {return secondminindex;}
    type getsecondminobject() {return object[secondminindex];}
    void replace(int w, type x) {
        if (w != prewin[1] && w != secondminindex) {
            if (x <= object[prewin[1]]) secondminindex = prewin[1];
            else if (x <= object[secondminindex]) secondminindex = w;
            object[w] = x;
            goup(w);
        } else {
            object[w] = x;
            goup(w);
            solvesecondmin();
        }
    }
    void goup(int w);
    int * prewin;
    type * object;
    int num;
    int secondminindex;
    void solvesecondmin();
};
template<class type>
minwintree<type>::minwintree(type maxtype, int n) {
    object = new type[n + 1];
    prewin = new int[n];
    assert(object && prewin && n > 1);
    object[0] = maxtype;
    num = n;
    for (int i = 1; i < n; i++) prewin[i] = 0;
    secondminindex = 0;
}
template<class type>
void minwintree<type>::solvesecondmin() {
    int cur;
    if ((prewin[1] + num - 1) & 1) secondminindex = prewin[1] - 1;
    else secondminindex = prewin[1] + 1;
    if (secondminindex == 0) secondminindex = prewin[num - 1];
    for (cur = (prewin[1] + num - 1) / 2; cur > 1; cur /= 2) {
        if (cur & 1) {
            if (object[prewin[cur - 1]] < object[secondminindex])
                secondminindex = prewin[cur - 1];
        } else {
            if (cur + 1 < num) {
                if (object[prewin[cur + 1]] < object[secondminindex])
                    secondminindex = prewin[cur + 1];
            } else {
                if (object[1] < object[secondminindex])
                    secondminindex = 1;
            }
        }
    }
}
template<class type>
void minwintree<type>::goup(int w) {
    int curnode, curindex, bronode, broindex, fatnode, fatindex;
    curnode = w + num - 1;
    curindex = w;
    while (curnode != 1) {
        fatnode = curnode / 2;
        fatindex = prewin[fatnode];
        if (fatindex == w) {
            bronode = curnode % 2 == 0 ? curnode + 1 : curnode - 1;
            broindex = bronode >= num ? bronode - num + 1 : prewin[bronode];
            if (broindex <= num && object[broindex] < object[curindex]) {
                prewin[fatnode] = broindex;
            } else prewin[fatnode] = curindex;
        } else {
            if (object[curindex] < object[fatindex]) {
                prewin[fatnode] = curindex;
            } else break;
        }
        curnode = fatnode;
        curindex = prewin[curnode];
    }
}

int n, pre[100001];

int main() {
    char str[50];
    int i, u, v, benefit;
    int count = 0;
    while (1) {
        scanf("%s", str);
        if (strcmp(str, "EndOfInput") == 0) break;
        if (str[0] < '0' || str[0] > '9') {
            printf("error\n");
        }
        printf("Case %d:\n", ++count);
        n = atoi(str);
        minwintree<int> tree(2000000000, n);
        for (i = 1; i <= n; i++) {
            scanf("%d", &pre[i]);
            tree.replace(i, (10000 - 0) * 100000 + i - 1);
        }
        while (1) {
            scanf("%s", str);
            if (strcmp(str, "EndOfCurrentCase") == 0) break;
            else if (strcmp(str, "Report") == 0) {
                printf("%d %d\n", tree.getminindex(), tree.getsecondminindex());
            } else {
                if (str[0] <'0' || str[0] > '9') {
                    printf("error\n");
                }
                u = atoi(str);
                scanf("%d", &v);
                benefit = v - pre[u];
                pre[u] = v;
                tree.replace(u, (10000 - benefit) * 100000 + u - 1);
            }
        }
    }
    return 0;
}                                 