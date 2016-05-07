// Problem#: 2501
// Submission#: 2752798
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <algorithm>
using namespace std;
int main() {
    int data[9905], n, k;
    scanf("%d%d", &n, &k);
    data[0] = 0;
    data[1] = n;
    for (int i = 2; i <= 9900 && i <= k; i++) {
        data[i] =(data[i - 1] * n + n) % 9901;
    }
    printf("%d\n", ((data[9900] * (k / 9900)) + data[k % 9900]) % 9901);
    return 0;
}                                 