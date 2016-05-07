// Problem#: 1933
// Submission#: 3578872
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
char text[500000];
int main() {
    int caseNum;
    scanf("%d\n", &caseNum);
    while (caseNum--) {
        int n;
        long long sum = 0, ans = 0, m = 0;
        bool isNegative = false;
        scanf("%d\n", &n);
        gets(text);
        for (int i = 0; text[i] != '\0'; i++) {
            if (text[i] == '-') isNegative = true;
            else if (text[i] == ' ') {
                if (sum < 0) ans -= sum;
                else ans += sum;
                if (isNegative) sum -= m;
                else sum += m;
                m = 0;
                isNegative = false;
            } else m = m * 10 + text[i] - '0';
        }
        if (sum < 0) ans -= sum;
        else ans += sum;
        if (isNegative) sum -= m;
        else sum += m;
        m = 0;
        isNegative = false;
        printf("%lld\n", ans);
    }
    return 0;
}                                 