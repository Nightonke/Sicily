// Problem#: 1034
// Submission#: 2735794
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int deep, width, fs[105], width_in_per_depth[105], n;//width_in_per_depth数组使用来储存每一层的宽度
bool is_ok, is_vis[105];

void find_ans(int father, int d) {
    if (is_vis[father]) {//每个点是有且仅有一次访问
        is_ok = false;
        return;
    }
    
    is_vis[father] = true;
    width_in_per_depth[d]++;//说明这个点在当前层是合法的，更新宽度
    if (width_in_per_depth[d] > width)
        width = width_in_per_depth[d];//更新最大宽度
    
    for (int i = 1; i <= n; i++) {
        if (fs[i] == father && is_vis[i]) {//找到了儿子然而却已经被访问了，说明出现了两个老爸生一个儿子
            is_ok = false;
            return;
        }
        if (fs[i] == father && !is_vis[i]) {//找儿子，儿子应该是没有访问的
            
            if (d + 1 > deep)
                deep = d + 1;//找到了儿子说明必须往下进行
            
            if (!is_vis[i])
                find_ans(i, d + 1);//往下进行
        }
    }
}

int main() {
    int m, i, father, son;
    bool is_root[105], have_root;
    
    while (cin >> n >> m && n) {
        
        deep = 0;
        width = 0;
        is_ok = true;
        have_root = false;
        memset(fs, 0, sizeof(fs));
        memset(is_vis, false, sizeof(is_vis));
        memset(width_in_per_depth, 0, sizeof(width_in_per_depth));
        memset(is_root, true, sizeof(is_root));
        
        for (i = 0; i < m; i++) {
            cin >> father >> son;
            if (father == son)
                is_ok = false;
            is_root[son] = false;//（有老爸的）儿子就不是祖先
            if (fs[son] != 0)
                is_ok = false;//假如某个儿子已经有了老爸，就不可能有第二个
            else
                fs[son] = father;
        }
        
        if (!is_ok) {
            cout << "INVALID" << endl;
            continue;
        }
        
        for (i = 1; i <= n; i++) {
            if (is_root[i]) {
                have_root = true;
                find_ans(i, 0);
            }
        }
        
        if (!have_root) {//没有祖先必然不可能
            cout << "INVALID" << endl;
            continue;
        }
        
        for (i = 1; i <= n; i++) {
            if (!is_vis[i]) {
                is_ok = false;//每个点都有且仅有一次访问，存在没有访问到的点也是错的
                break;
            }
        }
        
        if (is_ok)
            cout << deep << " " << width << endl;
        else
            cout << "INVALID" << endl;
    }
    
    return 0;
}                                 