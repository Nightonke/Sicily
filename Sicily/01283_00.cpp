// Problem#: 1283
// Submission#: 2827366
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

char A[1001], B[1001];

inline bool is_digit(char temp) {
    return '0' <= temp && temp <= '9';
}

void compare() {
    int s_a = 0, s_b = 0;
    int a_num = 0, b_num = 0;
    bool end_A = false, end_B = false;
    while (1) {
        
        if (end_A && end_B) {
            break;
        }
        
        int length_a = 0;
        int length_b = 0;
        char a[1001];
        char b[1001];
        memset(a, '\0', sizeof(a));
        memset(b, '\0', sizeof(b));
        int i;
        for (i = s_a; i < strlen(A); i++) {
            if (is_digit(A[s_a]) == is_digit(A[i])) {
                a[length_a++] = A[i];
            } else {
                s_a = i;
                a_num++;
                break;
            }
        }
        if (i == strlen(A)) {
            end_A = 1;
        }
        for (i = s_b; i < strlen(B); i++) {
            if (is_digit(B[s_b]) == is_digit(B[i])) {
                b[length_b++] = B[i];
            } else {
                s_b = i;
                b_num++;
                break;
            }
        }
        if (i == strlen(B)) {
            end_B = 1;
        }
        
        
        if (strcmp(a, b)) {
            if (is_digit(a[0]) && is_digit(b[0])) {
                int s_aa = 0, s_bb = 0;
                for (int i = 0; i < length_a; i++) {
                    if (a[i] == '0') {
                        s_aa++;
                    } else {
                        break;
                    }
                }
                for (int i = 0; i < length_b; i++) {
                    if (b[i] == '0') {
                        s_bb++;
                    } else {
                        break;
                    }
                }
                char num_a[1001];
                char num_b[1001];
                memset(num_a, '\0', sizeof(num_a));
                memset(num_b, '\0', sizeof(num_b));
                int length_aa = 0, length_bb = 0;
                for (int i = s_aa; i < length_a; i++) {
                    num_a[length_aa++] = a[i];
                }
                for (int i = s_bb; i < length_b; i++) {
                    num_b[length_bb++] = b[i];
                }
                if (length_aa < length_bb) {
                    printf("<\n");
                    return;
                } else if (length_aa > length_bb) {
                    printf(">\n");
                    return;
                } else {
                    if (strcmp(num_a, num_b) < 0) {
                        printf("<\n");
                        return;
                    } else if (strcmp(num_a, num_b) > 0) {
                        printf(">\n");
                        return;
                    } else {
                        continue;
                    }
                }
            } else if (!is_digit(a[0]) && !is_digit(b[0])) {
                if (strcmp(a, b) < 0) {
                    printf("<\n");
                    return;
                } else if (strcmp(a, b) > 0) {
                    printf(">\n");
                    return;
                } else {
                    continue;
                }
            } else {
                if (!is_digit(a[0])) {
                    printf(">\n");
                    return;
                } else {
                    printf("<\n");
                    return;
                }
            }
        } else {
            continue;
        }
    }
    if (a_num < b_num) {
        printf("<\n");
    } else if (a_num > b_num) {
        printf(">\n");
    } else {
        printf("=\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        memset(A, '\0', sizeof(A));
        memset(B, '\0', sizeof(B));
        scanf("%s%s", A, B);
        if (!strcmp(A, B)) {
            printf("=\n");
            continue;
        } else {
            compare();
        }
    }
    return 0;
}                                 