// Problem#: 10625
// Submission#: 2808626
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main() {
    bool is_ok = false;
    int letter[26], n;
    scanf("%d\n", &n);
    memset(letter, 0, sizeof(letter));
    while (n--) {
        char temp[35];
        gets(temp);
        letter[temp[0] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (letter[i] >= 5) {
            is_ok = true;
            printf("%c", i + 'a');
        }
    }
    if (!is_ok) {
        printf("PREDAJA");
    }
    printf("\n");
    return 0;
}                                 