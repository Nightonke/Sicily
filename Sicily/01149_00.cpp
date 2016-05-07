// Problem#: 1149
// Submission#: 3279718
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
using namespace std;

class Calculator {
  public:
    string trans_to_postfix_expression_to_s(string);  // 将得到的表达式转化为后缀表达式
    long long int calculate_from_postfix_expression();  // 根据后缀表达式计算值
    bool bracket_check(string);  // 检查括号匹配与否
    bool operator_check(string);  // 检查是否有不合法操作符
  private:
    vector<string> ans_vector_post;  // 存放后缀表达式
    string post_string;  // 存放后缀表达式
};

inline int prior(char op) {  // 计算优先级函数
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else if (op == '^') {
        return 3;
    } else {
        return 0;
    }
}

double string_to_double(string in) {  // 将输入的字符串转化为相应数字函数
    char s[50];
    for (int i = 0; i < 50; i++) {
        s[i] = '\0';
    }
    for (int i = 0; i < in.size(); i++) {
        s[i] = in[i];
    }
    double ans;
    sscanf(s, "%lf", &ans);
    return ans;
}

string erase_blank(string s) {  // 去除空格函数
    for (int i = 0; i < s.size();) {
        if (s[i] == ' ') s.erase(i, 1);
        else i++;
    }
    return s;
}

string dealWithNegative(string s) {  // 负数的预处理，将"-("转化成"-1*("，比如"-(-1)"->"-1*(-1)"
    for (int i = 0; i < s.size() - 1; i++) {
        if (s[i] == '-' && s[i + 1] == '(') s.insert(i + 1, "1*");
    }
    return s;
}

bool Calculator::bracket_check(string in) {
    stack<char> st_bracket;
    for (int i = 0; i < in.size(); i++) {
        if (in[i] == '(' || in[i] == ')') {
            if (st_bracket.empty()) {
                st_bracket.push(in[i]);
            } else {
                if (st_bracket.top() == '(' && in[i] == ')') {
                    st_bracket.pop();
                } else {
                    st_bracket.push(in[i]);
                }
            }
        }
    }
    if (st_bracket.empty()) {
        return 1;
    } else {
        return 0;
    }
}

inline bool isLegal(char c) {  // 判断一个操作符是否合法
    return ('0' <= c && c <= '9') || c == '.' || c == '+' || c =='-' || c == '*' || c == '/' || c == '(' || c == ')' || c == ' '; 
}

inline bool isOperator(char c) {
    return c == '.' || c == '+' || c =='-' || c == '*' || c == '/';
}

bool Calculator::operator_check(string in) {  // 检查是否有不合法操作符

    for (int i = 0; i < in.size(); i++) {
        if (!isLegal(in[i])) return false;  // 出现除0123456789.+-*/() 以外的字符
        if (i > 0 && isOperator(in[i]) && isOperator(in[i - 1])) return false;  // ".+-*/相邻"
        if (i > 0 && in[i] == '(' && in[i - 1] == ')') return false;  // 出现")("
    }
    return true;
}

string Calculator::trans_to_postfix_expression_to_s(string in) {
    
    stack<char> op;  // 操作符栈
    ans_vector_post.clear();  // 后缀表达式存放数组
    bool nextIsNega = false;  // 判断负数
    for (int i = 0; i < in.size();) {
        char c = in[i];
        if ((i > 0 && (in[i - 1] == '+' || in[i - 1] == '-' || in[i - 1] == '*' || in[i - 1] == '/' || in[i - 1] == '(' || in[i - 1] == '^') && in[i] == '-') || (i == 0 && in[i] == '-')) {  // 判断是否为负数
            nextIsNega = true;
            i++;
            continue;
        }
        if (('0' <= c && c <= '9') || c == '.') {  // 是数字直接插入
            string num;
            int j;
            for (j = i; j < in.size() && (('0' <= in[j] && in[j] <= '9') || in[j] == '.'); j++) {
                num.push_back(in[j]);
            }
            if (nextIsNega) {
                num = "-" + num;
                nextIsNega = false;
            }
            ans_vector_post.push_back(num);
            i = j;
        } else {
            if (c == '(') {  // 是开括号直接插入
                op.push('(');
            } else {
                if (c == ')') {  // 是闭括号就把原本栈中的运算符都输出，直到遇到开括号，注意开括号要丢弃
                    while (op.top() != '(') {
                        string temp;
                        temp.push_back(op.top());
                        ans_vector_post.push_back(temp);
                        op.pop();
                    }
                    op.pop();
                } else {  // 假如是加减乘除取余
                    if (op.empty()) {  // 操作符栈是空就直接插入
                        op.push(c);
                    } else {  // 如果扫描到的运算符优先级高于栈顶运算符则，把运算符压入栈。否则的话，就依次把栈中运算符弹出加到数组ans的末尾，直到遇到优先级低于扫描到的运算符或栈空，并且把扫描到的运算符压入栈中
                        if (prior(c) > prior(op.top())) {
                            op.push(c);
                        } else {
                            while (!op.empty() && prior(c) <= prior(op.top())) {
                                string temp;
                                temp.push_back(op.top());
                                ans_vector_post.push_back(temp);
                                op.pop();
                            }
                            op.push(c);
                        }
                    }
                }
            }
            i++;
        }
    }
    while (!op.empty()) {  // 注意把操作符栈中的剩余操作符输出
        string temp;
        temp.push_back(op.top());
        ans_vector_post.push_back(temp);
        op.pop();
    }
    
    post_string.clear();  // 构造string并返回
    for (int i = 0; i < ans_vector_post.size(); i++) {
        post_string += ans_vector_post[i];
    }
    
    return post_string;
}

long long int Calculator::calculate_from_postfix_expression() {
    
    //利用栈对后缀表达式求值，直接从后缀表达式的左往右扫描，遇到数字放入栈中，遇到字符就把栈顶的两个数字拿出来算，然后再放进栈
    
    stack<long long int> ans_post;
    for (int i = 0; i < ans_vector_post.size(); i++) {
        long long int x, y;
        if (('0' <= ans_vector_post[i][0] && ans_vector_post[i][0] <= '9') || (ans_vector_post[i][0] == '-' && '0' <= ans_vector_post[i][1] && ans_vector_post[i][1] <= '9')) {
            ans_post.push(string_to_double(ans_vector_post[i]));
        } else {
            y = ans_post.top();  // 注意顺序，这里好比xy+就是x+y
            ans_post.pop();
            x = ans_post.top();
            ans_post.pop();
            if (ans_vector_post[i][0] == '+') {
                ans_post.push(x + y);
            } else if (ans_vector_post[i][0] == '-') {
                ans_post.push(x - y);
            } else if (ans_vector_post[i][0] == '*') {
                ans_post.push(x * y);
            } else if (ans_vector_post[i][0] == '/') {
                ans_post.push(x / y);
            } else if (ans_vector_post[i][0] == '^') {
                long long int temp = x;
                for (int i = 1; i < y; i++) {
                    x *= temp;
                }
                ans_post.push(x);
            }
        }
    }
    return ans_post.top();
}

int main() {

    std::ios::sync_with_stdio(false);

    string ori;
    string oriTest;
    string temp;
    string choose[30];
    string test[30];
    getline(cin, ori);
    ori = erase_blank(ori);
    int N;
    cin >> N;
    getline(cin, temp);
    for (int i = 0; i < N; i++) {
        getline(cin, choose[i]);
        choose[i] = erase_blank(choose[i]);
    }
    Calculator c;

    bool bingo[30];
    for (int i = 0; i < N; i++) bingo[i] = true;

    for (int i = 0; i <= 9; i++) {
        oriTest = ori;
        for (int k = 0; k < oriTest.size(); k++) {
            if (oriTest[k] == 'a') oriTest[k] = i + '0';
        }
        c.trans_to_postfix_expression_to_s(oriTest);
        long long int ans = c.calculate_from_postfix_expression();
        for (int j = 0; j < N; j++) {
            test[j] = choose[j];
            for (int k = 0; k < test[j].size(); k++) {
                if (test[j][k] == 'a') test[j][k] = i + '0';
            }
            c.trans_to_postfix_expression_to_s(test[j]);
            long long int result = c.calculate_from_postfix_expression();
            if (result != ans) bingo[j] = false;
        }
    }
    for (int i = 0; i < N; i++) if (bingo[i]) cout << (char)('A' + i);
    cout << endl;

    //cin >> ori;

    return 0;
}                                 