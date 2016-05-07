// Problem#: 13289
// Submission#: 3520064
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stdio.h>
using namespace std;

int main() {
    
    //std::ios::sync_with_stdio(false);
    
    int caseNum;
    scanf("%d", &caseNum);
    while (caseNum--) {
        int N, A, B;
        scanf("%d%d%d", &N, &A, &B);
        N %= A + B;
        if (0 < N && N <= A) printf("Bob\n");
        else printf("Alice\n");
    }
    
    return 0;
}                                 