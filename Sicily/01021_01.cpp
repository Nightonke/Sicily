// Problem#: 1021
// Submission#: 2735613
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <stack>
using namespace std;

int couple_relation[200005];
//实际上是利用了stack来清除消失的夫妻

int main() {
    int t1, t2, n, i;
    while (cin >> n && n) {
        stack<int> s;  //这里记住要在while内部，这样在每次用完之后都会生成一个新的，相当于清空
        for (i = 0; i < n; i++) {
            cin >> t1 >> t2;
            couple_relation[t1] = t2;
            couple_relation[t2] = t1;  //建立夫妻之间的关系，等会好解决
        }
        for (i = 1; i <= 2 * n; i++) {
            if (s.empty())  //如果栈中没有夫妻，那就必须假如夫妻
                s.push(i);
            else if (couple_relation[i] == s.top())  //如果非空，并且接下来的夫或妻与栈top的妻或夫是一对（其实也表明了这个时候他们站在一起了）
                s.pop();  //那就去掉栈top，再加上不输入其实相当与清除了夫妻
            else
                s.push(i);  //不是一对就站着先
        }
        if (s.empty())
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}                                 