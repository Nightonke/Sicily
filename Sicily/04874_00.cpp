// Problem#: 4874
// Submission#: 2814103
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

struct cube {
    int u;
    int d;
    int l;
    int r;
    int f;
    int b;
    cube(){};
    cube(int uu, int dd, int ll, int rr, int ff, int bb) {
        u = uu;
        d = dd;
        l = ll;
        r = rr;
        f = ff;
        b = bb;
    }
};

int main() {
    int row, col;
    cube c(1, 6, 4, 3, 5, 2);
    cube next_c;
    scanf("%d %d", &row, &col);
    bool is_go_right = true;
    long long int sum_all = 0;
    for (int i = 0; i < row; i++) {
        
        int sum_4 = c.l + c.r + c.u + c.d;
        int sum_row = (col / 4) * sum_4;
        if (col % 4 == 1) {
            sum_row += c.u;
            cube n_c(c.u, c.d, c.l, c.r, c.f, c.b);
            next_c = n_c;
        } else if (col % 4 == 2) {
            if (is_go_right) {
                sum_row += c.u + c.l;
                cube n_c(c.l, c.r, c.d, c.u, c.f, c.b);
                next_c = n_c;
            } else {
                sum_row += c.u + c.r;
                cube n_c(c.r, c.l, c.u, c.d, c.f, c.b);
                next_c = n_c;
            }
        } else if (col % 4 == 3) {
            if (is_go_right) {
                sum_row += c.u + c.l + c.d;
                cube n_c(c.d, c.u, c.r, c.l, c.f, c.b);
                next_c = n_c;
            } else {
                sum_row += c.u + c.r + c.d;
                cube n_c(c.d, c.u, c.r, c.l, c.f, c.b);
                next_c = n_c;
            }
        } else {
            cube n_c(c.l, c.r, c.u, c.d, c.f, c.b);
            next_c = n_c;
        }
        
        sum_all += sum_row;
        
        c.u = next_c.f;
        c.d = next_c.b;
        c.l = next_c.l;
        c.r = next_c.r;
        c.f = next_c.d;
        c.b = next_c.u;
        is_go_right = !is_go_right;
    }
    printf("%lld\n", sum_all);
    return 0;
}                                 