// Problem#: 1034
// Submission#: 2735786
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int deep, width, fs[105], map[105], n;
bool is_ok, is_here[105], is_vis[105];

void find_ans(int father, int d) {
    if (is_vis[father]) {
        is_ok = false;
        return;
    }
    is_vis[father] = true;
    map[d]++;
    if (map[d] > width)
        width = map[d];
    for (int i = 1; i <= n; i++) {
        if (fs[i] == father) {
            if (d + 1 > deep)
                deep = d + 1;
            if (!is_vis[i]) {
                find_ans(i, d + 1);
            } else {
                is_ok = false;
                return;
            }
        }
    }
}

int main() {
    int m, i, father, son;
    bool is_root[105], have_root;
    while (cin >> n >> m && n) {
        is_ok = true;
        have_root = false;
        memset(fs, 0, sizeof(fs));
        memset(is_vis, false, sizeof(is_vis));
        memset(map, 0, sizeof(map));
        memset(is_root, true, sizeof(is_root));
        for (i = 0; i < m; i++) {
            cin >> father >> son;
            if (father == son)
                is_ok = false;
            is_root[son] = false;
            if (fs[son] != 0)
                is_ok = false;
            else
                fs[son] = father;
        }
        if (!is_ok) {
            cout << "INVALID" << endl;
            continue;
        }
        deep = 0;
        width = 0;
        for (i = 1; i <= n; i++) {
            if (is_root[i]) {
                have_root = true;
                find_ans(i, 0);
            }
        }
        if (!have_root) {
            cout << "INVALID" << endl;
            continue;
        }
        for (i = 1; i <= n; i++) {
            if (!is_vis[i]) {
                is_ok = false;
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