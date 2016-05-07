// Problem#: 1118
// Submission#: 2801076
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int main() {
    int k, m;
    double killer[101][3];
    while (scanf("%d%d", &k, &m) && k && m) {
        for (int i = 0; i < k; i++) {
            scanf("%lf%lf%lf", &killer[i][0], &killer[i][1], &killer[i][2]);
        }
        int counter = 0;
        while (m--) {
            double x, y, z;
            scanf("%lf%lf%lf", &x, &y, &z);
            for (int i = 0; i < k; i++) {
                double x1 = killer[i][0] - x;
                double y1 = killer[i][1] - y;
                double z1 = killer[i][2] - z;
                double coss = (x1 * x + y1 * y + z1 * z) / (sqrt(x * x + y * y + z * z) * sqrt(x1 * x1 + y1 * y1 + z1 * z1));
                if (coss >= 0) {
                    counter++;
                    break;
                }
            }
        }
        printf("%d\n", counter);
    }
    return 0;
}                                 