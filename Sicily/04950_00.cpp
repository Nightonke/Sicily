// Problem#: 4950
// Submission#: 2376977
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int v(int a, int b, int c) {
    int v;
    v = a * b * c;
    return v;
}
int main() {
    int l, w, h;
    while(scanf("%d", &l) != EOF) {
    scanf("%d%d", &w, &h);
    printf("%d\n", v(l, w, h));
    }
    return 0;
}                                 