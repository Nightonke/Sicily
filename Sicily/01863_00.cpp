// Problem#: 1863
// Submission#: 2593071
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int m;
struct mat{
    int a[2][2];
}start1;
mat matmul(mat mat1, mat mat2) {
    mat output;
    output.a[0][0] = mat1.a[0][0] * mat2.a[0][0] + mat1.a[0][1] * mat2.a[1][0];
    output.a[0][0] %= m;
    output.a[0][1] = mat1.a[0][0] * mat2.a[0][1] + mat1.a[0][1] * mat2.a[1][1];
    output.a[0][1] %= m;
    output.a[1][0] = mat1.a[1][0] * mat2.a[0][0] + mat1.a[1][1] * mat2.a[1][0];
    output.a[1][0] %= m;
    output.a[1][1] = mat1.a[1][0] * mat2.a[0][1] + mat1.a[1][1] * mat2.a[1][1];
    output.a[1][1] %= m;
    return output;
}
mat getansmat(mat mat1, int n) {
    mat temp;
    if (n == 1) {
        return start1;
    }
    if (n % 2 == 1) {
        return matmul(start1, getansmat(mat1, n - 1));
    }
    if (n % 2 == 0) {
        temp = getansmat(mat1, n / 2);
        return matmul(temp, temp);
    }
}
int solve(int n) {
    mat ans;
    ans = getansmat(start1, n);
    return ans.a[0][1] % m;
}
int main() {
    int t, n;
    start1.a[0][0] = start1.a[1][0] = start1.a[0][1] = 1;
    start1.a[1][1] = 0;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        if (n == 0) {
            printf("0\n");
            continue;
        }
        printf("%d\n", solve(n));
    }
    return 0;
}                                 