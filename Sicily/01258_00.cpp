// Problem#: 1258
// Submission#: 2827255
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <string>
#include <vector>
#include <string.h>
#include <cmath>
using namespace std;

bool is_end;
int x_v;

struct term {
    int pol;
    int pow;
    term(int p1, int p2) {
        pol = p1;
        pow = p2;
    }
};

vector<term> t;

void input() {
    string temp;
    cin >> x_v >> temp;
    cout << temp << endl;
    
    //preprocessing
    if (temp[0] != '-') {
        temp = "+" + temp;
    }
    if (temp[temp.size() - 1] == 'x') {
        temp += "^1";
    }
    for (int i = 0; i < temp.size(); i++) { //for pol and pow
        if ((temp[i] == '+' || temp[i] == '-') && temp[i + 1] == 'x') {
            temp.insert(i + 1, 1, '1');
        }
        if ((temp[i + 1] == '+' || temp[i + 1] == '-') && temp[i] == 'x') {
            temp.insert(i + 1, "^1");
        }
    }
    bool x_here = false;
    for (int i = temp.size() - 1; i >= 0; i--) {//for constant
        if (temp[i] == 'x') {
            x_here = true;
        }
        if ((temp[i] == '+' || temp[i] == '-') && x_here == false) {
            temp += "x^0";
        }
    }
    
    //make struct t
    for (int i = 0; i < temp.size(); i++) {
        if (temp[i] == '+' || temp[i] == '-') {
            int positive;
            if (temp[i] == '+') {
                positive = 1;
            } else {
                positive = -1;
            }
            string temp_int; //store the num_char
            int j;
            for (j = i + 1; j < temp.size(); j++) {
                if (temp[j] == 'x') {
                    break;
                }
                temp_int.push_back(temp[j]);
            }
            int pol_sum = 0;
            int pow_sum = 0;
            for (int k = 0; k < temp_int.size(); k++) {
                pol_sum = pol_sum * 10 + temp_int[k] - '0';
            }
            temp_int.clear();
            for (int k = j + 2; k < temp.size(); k++) {
                if (temp[k] == '+' || temp[k] == '-') {
                    break;
                }
                temp_int.push_back(temp[k]);
            }
            for (int k = 0; k < temp_int.size(); k++) {
                pow_sum = pow_sum * 10 + temp_int[k] - '0';
            }
            t.push_back(term(positive * pol_sum, pow_sum));
        }
    }
}

void f_d() {
    int zero_counter = 0;
    for (int i = 0; i < t.size(); i++) {
        t[i].pol *= t[i].pow;
        t[i].pow--;
        if (t[i].pol == 0) {
            zero_counter++;
        }
    }
    if (zero_counter == t.size()) {
        cout << '0' << endl << '0' << endl << '0' << endl << '0' << endl;
        is_end = true;
        return;
    } else {
        for (int i = 0; i < t.size(); i++) {
            if (t[i].pol) {
                if (t[i].pol > 0 && i) {
                    cout << '+';
                }
                if (t[i].pow == 0) {
                    cout << t[i].pol;
                    continue;
                }
                if (t[i].pol == -1) {
                    cout << '-';
                }
                if (t[i].pol != 1 && t[i].pol != -1) {
                    cout << t[i].pol;
                }
                if (t[i].pow) {
                    cout << 'x';
                    if (t[i].pow != 1) {
                        cout << '^' << t[i].pow;
                    }
                }
            }
        }
        cout << endl;
    }
}

void calculate() {
    
    int num_counter = 0;
    
    //output3
    for (int i = 0; i < t.size(); i++) {
        if (t[i].pol) {
            num_counter++; //the num of term whose pol is not zero
            if (t[i].pol > 0 && i) {
                cout << '+';
            }
            if (t[i].pow == 0) {
                cout << t[i].pol;
                continue;
            }
            if (t[i].pol == -1) {
                cout << '-';
            }
            if (t[i].pol != 1 && t[i].pol != -1) {
                cout << t[i].pol;
            }
            if (t[i].pow) {
                cout << '(' << x_v << ')';
                if (t[i].pow != 1) {
                    cout << '^' << t[i].pow;
                }
            }
        }
    }
    cout << endl;
    
    //
    long long int ans[20];
    long long int sum = 0;
    memset(ans, 0, sizeof(ans));
    for (int i = 0; i < t.size(); i++) {
        ans[i] = t[i].pol * (long long int)pow((double)x_v, (double)t[i].pow);
        sum += ans[i];
    }
    
    //output4
    for (int i = 0; i < num_counter; i++) {
        if (ans[i] >= 0 && i) {
            cout << '+';
        }
        cout << ans[i];
    }
    cout << endl;
    
    //output5
    cout << sum << endl;
}

int main() {
    int n;
    cin >> n;
    for (int nn = 1; nn <= n; nn++) {
        t.clear();
        is_end = false;
        cout << "POLYNOMIAL " << nn << endl;
        input();
        f_d();
        if (is_end) {
            continue;
        }
        calculate();
    }
    return 0;
}                                 