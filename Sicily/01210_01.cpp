// Problem#: 1210
// Submission#: 2723582
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstring>
using namespace std;
int main() {
    char preorder[30], postorder[30];
    int ans, i, length, j;
    cin >> preorder >> postorder;
    ans = 1;
    length = strlen(preorder);
    for (i = 0; i < length - 1; i++) {
        for (j = 0; j < length - 1; j++) {
            if (preorder[i] == postorder[j + 1] && preorder[i + 1] == postorder[j])
                ans *= 2;
        }
    }
    cout << ans;
    return 0;
}                                 