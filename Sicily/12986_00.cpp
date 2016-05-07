// Problem#: 12986
// Submission#: 3410771
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <iomanip>
#include <algorithm>
#include <queue>
#include <functional>
#include <map>
#include <string.h>
#include <math.h>
#include <list>
using namespace std;

int main() {

    //std::ios::sync_with_stdio(false);

    int caseNum;
    scanf("%d", &caseNum);

    while (caseNum--) {
        int N;
        scanf("%d", &N);
        bool isOK = false;
        if (N % 2 == 0) {
            for (int k = (((int)sqrt(N)) % 2 == 1 ? (int)sqrt(N) - 1 : (int)sqrt(N)); k >= 2; k -= 2) {
                if (N % k == 0 && (N / k - k + 1) % 2) {
                    printf("%d: [%d, %d]\n", N, N / k - k + 1, N / k + k - 1);
                    isOK = true;
                }
            }
        } else {
            for (int k = (((int)sqrt(N)) % 2 == 0 ? (int)sqrt(N) - 1 : (int)sqrt(N)); k >= 3; k -= 2) {
                if (N % k == 0 && (N / k - k + 1) % 2) {
                    printf("%d: [%d, %d]\n", N, N / k - k + 1, N / k + k - 1);
                    isOK = true;
                }
            }
        }
        if (!isOK) printf("%d: impossible\n", N);
    }

    return 0;
}                                 