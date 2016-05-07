// Problem#: 1268
// Submission#: 3590564
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <string>
#include <stack>
#include <iostream>
#include <vector>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

vector<string> ans_vector_post;
string post_string;

inline int prior(char op) {  // 计算优先级函数
    if (op == '+' || op == '-') {
        return 1;
    } else if (op == '*' || op == '/' || op == '%') {
        return 2;
    } else {
        return 0;
    }
}

long long int string_to_int(string in) {  // 将输入的字符串转化为相应数字函数
    char s[50];
    for (int i = 0; i < 50; i++) {
        s[i] = '\0';
    }
    for (int i = 0; i < in.size(); i++) {
        s[i] = in[i];
    }
    long long int ans;
    sscanf(s, "%lld", &ans);
    return ans;
}

string trans_to_postfix_expression_to_s(string in) {
    
    stack<char> op;  // 操作符栈
    ans_vector_post.clear();  // 后缀表达式存放数组
    for (int i = 0; i < in.size();) {
        char c = in[i];
        if ('0' <= c && c <= '9') {  // 是数字直接插入
            string num;
            int j;
            for (j = i; j < in.size() && '0' <= in[j] && in[j] <= '9'; j++) {
                num.push_back(in[j]);
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

long long int calculate_from_postfix_expression() {
    
    //利用栈对后缀表达式求值，直接从后缀表达式的左往右扫描，遇到数字放入栈中，遇到字符就把栈顶的两个数字拿出来算，然后再放进栈
    
    stack<long long int> ans_post;
    for (int i = 0; i < ans_vector_post.size(); i++) {
        long long int x, y;
        if ('0' <= ans_vector_post[i][0] && ans_vector_post[i][0] <= '9') {
            ans_post.push(string_to_int(ans_vector_post[i]));
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
            } else {
                ans_post.push(x % y);
            }
        }
    }
    return ans_post.top();
}

string predo(string in) {
    int s = in.size();
    string ret;
    for (int i = 0; i < s; i++) {
        if (i == 0 && (in[i] == '-' || in[i] == '+')) {
            ret.push_back('0');
            ret.push_back(in[i]);
        } else if (i > 0 && (in[i] == '-' || in[i] == '+') && in[i - 1] == '(') {
            ret.push_back('0');
            ret.push_back(in[i]);
        } else ret.push_back(in[i]);
    }
    return ret;
}

int main() {
    std::ios::sync_with_stdio(false);
    while (1) {
        string in;
        cin >> in;
        if (cin.eof()) break;
        in = predo(in);
        trans_to_postfix_expression_to_s(in);
        cout << calculate_from_postfix_expression() << endl;
    }
    return 0;
}                                 