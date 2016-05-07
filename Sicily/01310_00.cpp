// Problem#: 1310
// Submission#: 3298451
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

struct treeNode {
    int v;
    treeNode * l, * r;
    treeNode(int val = 0, treeNode * ll = NULL, treeNode * rr = NULL) {
        v = val;
        l = ll;
        r = rr;
    }
};

inline void insertT(treeNode * & now, int & val) {
    if (now == NULL) now = new treeNode(val);
    else if (val <= now->v) insertT(now->l, val);
    else insertT(now->r, val);
}

inline void inOrder(treeNode * & now) {
    if (!now) return;
    inOrder(now->l);
    printf(" %d", now->v);
    inOrder(now->r);
}

inline void preOrder(treeNode * & now) {
    if (!now) return;
    printf(" %d", now->v);
    preOrder(now->l);
    preOrder(now->r);
}

inline void postOrder(treeNode * & now) {
    if (!now) return;
    postOrder(now->l);
    postOrder(now->r);
    printf(" %d", now->v);
}

inline void deleteT(treeNode * & now) {
    if (!now) return;
    deleteT(now->l);
    deleteT(now->r);
    delete now;
}

int main() {

    //std::cout.sync_with_stdio(false);

    bool firstTime = true;
    int n;

    while (scanf("%d", &n) != EOF) {
        if (!firstTime) printf("\n");
        treeNode * root = NULL;
        for (int i = 0; i < n; i++) {
            int temp;
            cin >> temp;
            insertT(root, temp);
        }
        printf("Inorder:"), inOrder(root);
        printf("\n");
        printf("Preorder:"), preOrder(root);
        printf("\n");
        printf("Postorder:"), postOrder(root);
        printf("\n");
        deleteT(root);
        if (firstTime) firstTime = false;
    }

    return 0;
}                                 