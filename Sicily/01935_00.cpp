// Problem#: 1935
// Submission#: 3359425
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <vector>
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
vector<char> ans[30];  // 存放广度优先遍历的序列

TreeNode * rebuild(int preS, int preE, int inS, int inE) {  // preS、preE分别是当前前序遍历序列的起始和末尾，inS、inE分别是当前中序遍历序列的起始和末尾
    if (preS > preE || inS > inE) return NULL;  // 如果树是空
    TreeNode * now = new TreeNode(pre[preS]);
    int pos;
    for (pos = inS; pos <= inE; pos++) {  // 在中序遍历中找到当前跟节点
        if (pre[preS] == in[pos]) break;
    }
    now->l = rebuild(preS + 1, preS + pos - inS, inS, pos - 1);  // 递归重建左子树，注意左子树序列长度是pos-inS
    now->r = rebuild(preS + pos - inS + 1, preE, pos + 1, inE);  // 递归重建右子树
    return now;
}

void preOrder(TreeNode * now, int floor) {  // 得到广度优先遍历序列
    if (now->l) preOrder(now->l, floor + 1);
    ans[floor].push_back(now->v);
    if (now->r) preOrder(now->r, floor + 1);
}

int main() {

    int caseNum;
    cin >> caseNum;

    while (caseNum--) {
        cin >> pre >> in;
        TreeNode * root = rebuild(0, pre.size() - 1, 0, in.size() - 1);
        preOrder(root, 0);
        for (int i = 0; ans[i].size() != 0; i++) {  // 输出广度优先遍历序列
            for (int j = 0; j < ans[i].size(); j++) cout << ans[i][j];
            ans[i].clear();
        }
        cout << endl;
    }

    return 0;
}                                 