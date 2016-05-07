// Problem#: 1219
// Submission#: 3587603
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

const int INF = 2147483647;
const int MAXN = 21;

struct Tree {
    int child, color, weight;
    Tree * next;
} * tree[MAXN];

int n;

void search(int turn, int & value) {
    Tree * tmp, * tmp1, *tmp2;
    int f = 0, r = 1, l[MAXN];
    int max = -INF, min = INF;
    l[0] = 0;
    while (f < r) {
        tmp = tree[l[f++]];
        while ((tmp1 = tmp->next) != NULL) {
            l[r++] = tmp1->child;
            if (tmp1->color == turn) {
                tmp2 = tmp->next;
                tmp->next = tmp1->next;
                int ret = value + turn * tmp1->weight;
                search(-turn, ret);
                if (ret > max) max = ret;
                if (ret < min) min = ret;
                tmp->next = tmp2;
            }
            tmp = tmp1;
        }
    }
    if (max == -INF || min == INF)
        while (r--) value -= turn * tree[l[r]]->weight;
    else
        value = turn > 0 ? max : min;
}

int main() {
    int i, a, b, c, w;
    Tree * tmp;
    scanf("%d", &n);
    for (i = 0; i <= n; i++) {
        tree[i] = new Tree;
        tree[i]->next = NULL;
    }
    tree[0]->weight = 0;
    for (i = 0; i < n; i++) {
        scanf("%d%d%d%d", &a, &b, &c, &w);
        tmp = tree[a]->next;
        tree[a]->next = new Tree;
        tree[a]->next->child = b;
        tree[a]->next->color = c;
        tree[a]->next->weight = w;
        tree[a]->next->next = tmp;
        tree[b]->weight = w;
    }
    int value = 0;
    search(1, value);
    printf("%d\n", value);
    return 0;
}                                 