// Problem#: 1205
// Submission#: 2825260
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stack>
#include <string.h>
using namespace std;

char code[128005];
int test[32768];
int bracket_num;
int b_pos[10000][2];

int search_right_pos(int l_pos) {
    for (int i = 0; i < bracket_num; i++) {
        if (b_pos[i][0] == l_pos) {
            return b_pos[i][1];
        }
    }
}

int search_left_pos(int r_pos) {
    for (int i = 0; i < bracket_num; i++) {
        if (b_pos[i][1] == r_pos) {
            return b_pos[i][0];
        }
    }
}

int main() {
    int case_num;
    scanf("%d\n", &case_num);
    for (int case_counter = 1; case_counter <= case_num; ) {
        
        printf("PROGRAM #%d:\n", case_counter);
        case_counter++;
        
        //input
        memset(test, 0, sizeof(test));
        char code_line[10000];
        char *temp_t = code;
        stack<char> s;
        stack<int> bracket_pos;
        bracket_num = 0;
        while (1) {
            gets(code_line);
            if (code_line[0] == 'e' && code_line[1] == 'n' && code_line[2] == 'd') {
                break;
            }
            char *temp;
            for (temp = code_line; *temp != '%' && *temp != '\n' && *temp != '\0'; temp++) {
                if (*temp == '<' || *temp == '>' || *temp == '+' || *temp == '-' || *temp == '.' || *temp == '[' || *temp == ']') {
                    if (*temp == '[' || *temp == ']') {
                        if (s.empty()) {
                            s.push(*temp);
                            bracket_pos.push(temp_t - code);
                        } else {
                            if (s.top() == '[' && *temp == ']') {
                                b_pos[bracket_num][0] = bracket_pos.top();
                                b_pos[bracket_num++][1] = temp_t - code;
                                s.pop();
                                bracket_pos.pop();
                            } else {
                                s.push(*temp);
                                bracket_pos.push(temp_t - code);
                            }
                        }
                    }
                    *temp_t = *temp;
                    temp_t++;
                }
            }
        }
        *temp_t = '\0';
        
        //check []
        if (!s.empty()) {
            printf("COMPILE ERROR\n");
            continue;
        }
        
        //go
        int pointer = 0;
        for (char *code_pos = code; *code_pos != '\0'; code_pos++) {
            if (*code_pos == '>') {
                pointer++;
                if (pointer == 32767) {
                    pointer = 0;
                }
            } else if (*code_pos == '<') {
                pointer--;
                if (pointer == -1) {
                    pointer = 32767;
                }
            } else if (*code_pos == '+') {
                test[pointer]++;
                if (test[pointer] == 256) {
                    test[pointer] = 0;
                }
            } else if (*code_pos == '-') {
                test[pointer]--;
                if (test[pointer] == -1) {
                    test[pointer] = 255;
                }
            } else if (*code_pos == '.') {
                printf("%c", test[pointer]);
            } else if (*code_pos == '[') {
                if (test[pointer] == 0) {
                    int r_pos = search_right_pos(code_pos - code);
                    code_pos = code + r_pos;
                }
            } else if (*code_pos == ']') {
                if (!(test[pointer] == 0)) {
                    int l_pos = search_left_pos(code_pos - code);
                    code_pos = code + l_pos;
                }
            }
        }
        printf("\n");
    }
    return 0;
}                                 