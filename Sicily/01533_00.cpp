// Problem#: 1533
// Submission#: 2832943
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
using namespace std;

int RomanNumberToInteger(string in_s) {
    int sum = 0;
    for (int i = 0; i < in_s.size(); ) {
        if (in_s[i] == 'M' && (i == 0 || in_s[i - 1] != 'C')) {
            sum += 1000;
            i++;
        } else if (in_s[i] == 'C' && ((i == in_s.size() - 1) || (in_s[i + 1] != 'D' && in_s[i + 1] != 'M'))) {
            sum += 100;
            i++;
        } else if (in_s[i] == 'C' && i + 1 < in_s.size() && in_s[i + 1] == 'D') {
            sum += 400;
            i += 2;
        } else if (in_s[i] == 'D' && ((i == 0) || (i > 0 && in_s[i - 1] != 'C'))) {
            sum += 500;
            i++;
        } else if (in_s[i] == 'C' && i + 1 < in_s.size() && in_s[i + 1] == 'M') {
            sum += 900;
            i += 2;
        } else if (in_s[i] == 'X' && ((i == in_s.size() - 1) || (in_s[i + 1] != 'L' && in_s[i + 1] != 'C'))) {
            sum += 10;
            i++;
        } else if (in_s[i] == 'X' && i + 1 < in_s.size() && in_s[i + 1] == 'L') {
            sum += 40;
            i += 2;
        } else if (in_s[i] == 'L' && ((i == 0) || (i > 0 && in_s[i - 1] != 'X'))) {
            sum += 50;
            i++;
        } else if (in_s[i] == 'X' && i + 1 < in_s.size() && in_s[i + 1] == 'C') {
            sum += 90;
            i += 2;
        } else if (in_s[i] == 'I' && ((i == in_s.size() - 1) || (in_s[i + 1] != 'V' && in_s[i + 1] != 'X'))) {
            sum += 1;
            i++;
        } else if (in_s[i] == 'I' && i + 1 < in_s.size() && in_s[i + 1] == 'V') {
            sum += 4;
            i += 2;
        } else if (in_s[i] == 'V' && ((i == 0) || (i > 0 && in_s[i - 1] != 'I'))) {
            sum += 5;
            i++;
        } else if (in_s[i] == 'I' && i + 1 < in_s.size() && in_s[i + 1] == 'X') {
            sum += 9;
            i += 2;
        }
    }
    return sum;
}

char r_n[3][9][5] = {"C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

void integerToRomanNumber(int sum) {
    int num[4] = {0, 0, 0, 0}, i = 3;
    while (sum) {
        num[i--] = sum % 10;
        sum /= 10;
    }
    if (num[0]) {
        for (i = 0; i < num[0]; i++) {
            cout << 'M';
        }
    }
    for (i = 1; i < 4; i++) {
        if (num[i]) {
            cout << r_n[i - 1][num[i] - 1];
        }
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    int n, case_counter = 1;
    while (1) {
        cin >> n;
        if (n == 0) {
            break;
        }
        int ans = 0;
        string temp;
        for (int i = 0; i < n; i++) {
            cin >> temp;
            ans += RomanNumberToInteger(temp);
        }
        cout << "Case ";
        integerToRomanNumber(case_counter);
        cout << ": ";
        case_counter++;
        integerToRomanNumber(ans);
        cout << endl;
    }
    return 0;
}                                 