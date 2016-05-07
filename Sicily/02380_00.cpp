// Problem#: 2380
// Submission#: 3270428
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int allNum[] = {0, 1, 10, 190, 2890, 38890, 488890, 5888890, 68888890, 788888890, 8888888890};

void cal(int n, int times[]) {

    int originalN = n;

    for (int i = 0; i <= 9; i++) times[i] = 0;

    if (n == 0) {
        times[0] = 1;
        return;
    }

    while (n > 9) {

        int weishu = (int)log10(1.0 * n) + 1;
        int zushu = n / (int)pow(10.0, 1.0 * (weishu - 1));
        int zongshu = zushu * (int)pow(10.0, 1.0 * (weishu - 1)) * (weishu - 1);

        for (int i = 1; i <= 9; i++) {
            times[i] += zongshu / 10;
        }

        for (int i = 1; i < zushu; i++) {
            times[i] += (int)pow(10.0, 1.0 * (weishu - 1));
        }

        times[zushu] += n % (int)pow(10.0, 1.0 * (weishu - 1)) + 1;

        n %= (int)pow(10.0, 1.0 * (weishu - 1));

    }

    for (int i = 1; i <= n; i++) times[i] += 1;

    int originalWeishu = (int)log10(1.0 * originalN) + 1;
    int suoyoushu = allNum[originalWeishu];
    suoyoushu += (originalN - (int)pow(10.0, 1.0 * (originalWeishu - 1)) + 1) * originalWeishu;

    int oneToNineSum = 0;
    for (int i = 1; i <= 9; i++) oneToNineSum += times[i];

    times[0] = suoyoushu - oneToNineSum;

}

int main() {
    
    while (1) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (a == 0 && b == 0) break;
        int aa[15], bb[15];
        cal(a - 1, aa);
        cal(b, bb);
        for (int i = 0; i <= 9; i++) {
            if (i) printf(" ");
            printf("%d", bb[i] - aa[i]);
        }
        printf("\n");
    }

    //getchar();
    //getchar();
    return 0;
}                                 