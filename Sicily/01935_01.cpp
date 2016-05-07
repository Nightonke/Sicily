// Problem#: 1935
// Submission#: 3352161
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <algorithm>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <string.h>
#include <vector>
#include <iomanip>
#include <map>
#include <stack>
#include <functional>
#include <list>
#include <cmath>
using namespace std;

struct TreeNode {
    char v;
    TreeNode * l, * r;
    TreeNode(char val = 0, TreeNode * ll = NULL, TreeNode * rr = NULL) {
        v = val;
        l = ll;
        r = rr;
    }
};

string pre, in;
vector<char> ans[30];

TreeNode * rebuild(int preS, int preE, int inS, int inE) {
    if (preS > preE || inS > inE) return NULL;
    TreeNode * now = new TreeNode(pre[preS]);
    int pos;
    for (pos = inS; pos <= inE; pos++) {
        if (pre[preS] == in[pos]) break;
    }
    now->l = rebuild(preS + 1, preS + pos - inS, inS, pos - 1);
    now->r = rebuild(preS + pos - inS + 1, preE, pos + 1, inE);
    return now;
}

void preOrder(TreeNode * now, int floor) {
    if (now->l) preOrder(now->l, floor + 1);
    ans[floor].push_back(now->v);
    if (now->r) preOrder(now->r, floor + 1);
}

int main() {

    std::ios::sync_with_stdio(false);
    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> pre >> in;
        TreeNode * root = rebuild(0, pre.size() - 1, 0, in.size() - 1);
        preOrder(root, 0);
        for (int i = 0; ans[i].size() != 0; i++) {
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
            ans[i].clear();
        }
        cout << endl;
    }


    //getchar();
    //getchar();
    
    return 0;
}                                 