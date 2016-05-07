// Problem#: 1777
// Submission#: 3280649
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
using namespace std;

struct treeNode {
    int val;
    treeNode * l;
    treeNode * r;
    treeNode(int v = 0, treeNode * ll = NULL, treeNode * rr = NULL) {
        val = v;
        l = ll;
        r = rr;
    }
};

void dfs(treeNode * now) {
    if (now == NULL) return;
    if (now->l != NULL && now->val < now->l->val) {
        cout << now->val << " ";
        dfs(now->l);
        dfs(now->r);
    } else if (now->r != NULL && now->val < now->r->val) {
        dfs(now->l);
        cout << now->val << " ";
        dfs(now->r);
    } else {
        dfs(now->l);
        dfs(now->r);
        cout << now->val << " ";
    }
}

int main() {

    std::ios::sync_with_stdio(false);

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        int n, m;
        treeNode * root = NULL;
        treeNode * t[105];
        cin >> n >> m;
        for (int i = 0; i < n; i++) t[i] = new treeNode(i, NULL, NULL);
        for (int i = 0; i < n; i++) {
            int t1, t2;
            cin >> t1 >> t2;
            if (t1 != -1) t[i]->l = t[t1];
            if (t2 != -1) t[i]->r = t[t2];
        }
        root = t[m];
        dfs(root);
        cout << endl;
        for (int i = 0; i < n; i++) delete t[i], t[i] = NULL;
    }

    return 0;
}                                 