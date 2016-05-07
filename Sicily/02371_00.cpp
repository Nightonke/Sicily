// Problem#: 2371
// Submission#: 2831591
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

string code;
int b_counter;
int p_num;
int b_num;
bool is_cal;

inline int char_to_int(char temp) {
    if ('0' <= temp && temp <= '9') {
        return temp - '0';
    } else {
        return temp - 'A' + 10;
    }
}

void decode() {
    int line_counter = 0;
    int hex[8];
    for (int i = 0; code[i] != '\0'; ) {
        int h = char_to_int(code[i]), l = char_to_int(code[i + 1]);
        for (int j = 3; j >= 0; j--) {
            hex[j] = h % 2;
            hex[j + 4] = l % 2;
            h /= 2;
            l /= 2;
        }
        if (hex[0] == 0) { //non-run
            int sum = 0;
            for (int k = 7; k >= 1; k--) {
                sum = sum + hex[k] * (int)pow((double)2, (double)(7 - k));
            }
            sum = sum + 1;
            if (is_cal) {
                b_counter += sum;
            } else {
                for (int k = i + 2; k < i + 2 + 2 * sum; k++) {
                    cout << code[k];
                    line_counter++;
                    if (line_counter == 80) {
                        line_counter = 0;
                        cout << endl;
                    }
                }
            }
            i = i + 2 + 2 * sum;
        } else {
            int sum = 0;
            for (int k = 7; k >= 1; k--) {
                sum = sum + hex[k] * (int)pow((double)2, (double)(7 - k));
            }
            sum = sum + 3;
            if (is_cal) {
                b_counter += sum;
            } else {
                for (int k = 0; k < sum; k++) {
                    cout << code[i + 2] << code[i + 3];
                    line_counter += 2;
                    if (line_counter == 80) {
                        line_counter = 0;
                        cout << endl;
                    }
                }
            }
            i = i + 4;
        }
    }
    if (is_cal) {
        cout << p_num << " " << b_counter << endl;
    } else if (line_counter) {
        cout << endl;
    }
}

int main() {
    int case_num;
    cin >> case_num;
    for (int case_counter = 1; case_counter <= case_num; case_counter++) {
        is_cal = true;
        b_counter = 0;
        cin >> p_num >> b_num;
        int lines = b_num % 40 ? b_num / 40 + 1 : b_num / 40;
        string temp;
        code.clear();
        for (int lines_counter = 0; lines_counter < lines; lines_counter++) {
            cin >> temp;
            code += temp;
        }
        decode();
        is_cal = false;
        decode();
    }
    return 0;
}                                 