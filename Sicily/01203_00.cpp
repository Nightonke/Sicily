// Problem#: 1203
// Submission#: 2586777
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int try1[1000], length;
int target[1000], temp2[1000];

void cube() {
    int temp[1000] = {0}, i, j, length1;
    memset(temp, 0, sizeof(temp));
    memset(temp2, 0, sizeof(temp2));
    for (i = 0; i < length; i++) {
        for (j = 0; j < length; j++) {
            temp[i + j] = try1[i] * try1[j] + temp[i + j];
            temp[i + j + 1] = temp[i + j] / 10 + temp[i + j + 1];
            temp[i + j] = temp[i + j] % 10;
        }
    }
    length1 = 2 * length;
    for (i = 0; i < length1; i++) {
        for (j = 0; j < length1; j++) {
            temp2[i + j] = temp[i] * try1[j] + temp2[i + j];
            temp2[i + j + 1] = temp2[i + j] / 10 + temp2[i + j + 1];
            temp2[i + j] = temp2[i + j] % 10;
        }
    }
}

int tryok(int i) {
    int j;
    cube();
    for (j = 0; j <= i; j++) {
        if (target[j] != temp2[j]) {
            return 0;
        }
    }
    return 1;
}

void solve(int l) {
    int i, j, k;
    for (i = 0; i < l; i++) {
        for (j = 0; j <= 9; j++) {
            try1[i] = j;
            if (tryok(i))
                break;
        }
    }
    for (k = 999; k > 0 && try1[k] == 0; k--);
    for (i = k; i >= 0; i--) {
        printf("%d", try1[i]);
    }
    printf("\n");
}
    
    
int main() {
    int t, i;
    char a[1000];
    scanf("%d\n", &t);
    while (t--) {
        memset(target, 0, sizeof(target));
        memset(try1, 0, sizeof(try1));
        gets(a);
        length = strlen(a);
        for (i = 0; i < length; i++) {
            target[i] = a[length - 1 - i] - '0';
        }
        solve(length);
    }
    return 0;
}                                 