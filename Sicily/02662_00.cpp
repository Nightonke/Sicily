// Problem#: 2662
// Submission#: 3593157
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXN = 100001;

struct tree {
    int l, r;
    int num;
}Tree[MAXN];

int last, num[MAXN], Index[MAXN];

void makeTree(int root, int n) {
    if (Tree[root].num >= n) {
        if (Tree[root].l == 0) {
            last++;
            Tree[last].num = n;
            Tree[last].l = Tree[last].r = 0;
            Tree[root].l = last;
        } else makeTree(Tree[root].l, n);
    } else {
        if (Tree[root].r == 0) {
            last++;
            Tree[last].num = n;
            Tree[last].l = Tree[last].r = 0;
            Tree[root].r = last;
        } else makeTree(Tree[root].r, n);
    }
}

void preorder(int root) {
    Index[root] = last++;
    if (Tree[root].l) preorder(Tree[root].l);
    if (Tree[root].r) preorder(Tree[root].r);
}

int findIt(int root, int n) {
    if (Tree[root].num >= n)
        if (Tree[root].l == 0) return -1;
        else return findIt(Tree[root].l, n);
    else 
        if (Tree[root].r) {
            int ret = findIt(Tree[root].r, n);
            return ret == -1 ? root : ret;
        } else return root;
}

int main() {
    int n, m, i;
    while (scanf("%d", &n), n) {
        memset(Tree, 0, sizeof(Tree));
        scanf("%d", num);
        Tree[0].num = num[0];
        last = 0;
        for (i = 1; i < n; i++) {
            scanf("%d", num + i);
            makeTree(0, num[i]);
        }
        last = 0;
        preorder(0);
        for (scanf("%d", &m); m--; ) {
            int v;
            scanf("%d", &v);
            int ans = findIt(0, v);
            if (ans == -1) printf("-1\n");
            else printf("%d %d\n", Tree[ans].num, Index[ans]);
        }
        printf("\n");
    }
    return 0;
}                                 