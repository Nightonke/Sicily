// Problem#: 1006
// Submission#: 2735803
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int num[105][6], ans;

struct EVERY {
    bool a[6][6];
    int d, b[6];
}p[125];

bool judge(int i1, int i2, int i3, int i4, int i5) {
    bool i[6];
    memset(i, false, sizeof(i));
    i[i1] = true;
    i[i2] = true;
    i[i3] = true;
    i[i4] = true;
    i[i5] = true;
    for (int j = 1; j <= 5; j++) {
        if (!i[j])
            return false;
    }
    return true;
}

void ready_b(int k) {
    for (int i = 1; i <= 5; i++) {
        for (int j = i + 1; j <= 5; j++) {
            p[k].a[p[k].b[i]][p[k].b[j]] = true;
        }
    }
}

void ready() {
    int k = 0;
    int i[6];
    for (i[1] = 1; i[1] <= 5; i[1]++) {
        for (i[2] = 1; i[2] <= 5; i[2]++) {
            for (i[3] = 1; i[3] <= 5 && i[1] != i[2]; i[3]++) {
                for (i[4] = 1; i[4] <= 5 && i[2] != i[3]; i[4]++) {
                    for (i[5] = 1; i[5] <= 5 && i[3] != i[4]; i[5]++) {
                        if (judge(i[1], i[2], i[3], i[4], i[5])) {
                            for (int i6 = 1; i6 <= 5; i6++) {
                                p[k].b[i6] = i[i6];
                            }
                            p[k].d = 0;
                            ready_b(k);
                            k++;
                        }
                    }
                }
            }
        }
    }
}

int main() {
    ready();
    int n, i, k, j, k1, k2, min, flag;
    char temp[6];
    bool num_a[6][6];
    while (cin >> n && n) {
        for (i = 0, k = 0; i < n; i++) {
            cin >> temp;
            for (j = 0; j < 5; j++) {
                num[k][j + 1] = temp[j] - 'A' + 1;
            }
            k++;
        }
        for (i = 0; i < n; i++) {
            memset(num_a, false, sizeof(num_a));
            for (k1 = 1; k1 <= 5; k1++) {
                for (k2 = k1 + 1; k2 <= 5; k2++) {
                    num_a[num[i][k1]][num[i][k2]] = true;
                }
            }
            for (j = 0; j < 120; j++) {
                for (k1 = 1; k1 <= 5; k1++) {
                    for (k2 = k1 + 1; k2 <= 5; k2++) {
                        if ((p[j].a[k1][k2] == false &&  num_a[k1][k2] == true) || (p[j].a[k1][k2] == true &&  num_a[k1][k2] == false)) {
                            p[j].d++;
                        }
                    }
                }
            }
        }
        for (i = 0, min = 9999999; i < 120; i++) {
            if (min > p[i].d) {
                flag = i;
                min = p[i].d;
            }
        }
        for (char temp1, i = 1; i <= 5; i++) {
            temp1 = 'A' + p[flag].b[i] - 1;
            cout << temp1;
        }
        cout << " is the median ranking with value " << min << "." << endl;
        for (i = 0; i < 120; i++) {
            p[i].d = 0;
        }
    }
    return 0;
}                                 