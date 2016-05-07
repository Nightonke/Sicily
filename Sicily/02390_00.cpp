// Problem#: 2390
// Submission#: 3536312
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stack>
using namespace std;

char text[32005];
char newExpression[100005];
char postfixExpression[100005];
int depth;
int length;
int newLength;
bool oddIsAnd;

void calculateDepth() {
    depth = 0;
    int counter = 0;
    for (int i = 0; i < length; i++) {
        if (text[i] == '(') counter++;
        if (text[i] == ')') counter--;
        if (counter > depth) depth = counter;
    }
}

inline bool valid(int pos) {
    return ((text[pos] == ')' && text[pos + 1] == 'T') 
         || (text[pos] == ')' && text[pos + 1] == 'F') 
         || (text[pos] == ')' && text[pos + 1] == '(') 
         || (text[pos] == 'T' && text[pos + 1] == 'F') 
         || (text[pos] == 'T' && text[pos + 1] == 'T') 
         || (text[pos] == 'T' && text[pos + 1] == '(') 
         || (text[pos] == 'F' && text[pos + 1] == 'F') 
         || (text[pos] == 'F' && text[pos + 1] == 'T') 
         || (text[pos] == 'F' && text[pos + 1] == '('));
}

void deleteBlank() {
    length = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] != ' ') text[length++] = text[i];
    }
    text[length] = '\0';
}

void makeNewExpression() {
    int nowDepth = 0;
    int counter = 0;
    int charPos[32005];
    char charPosChar[32005];
    for (int i = 0; i < length - 1; i++) {
        if (text[i] == '(') {
            nowDepth++;
        } else if (text[i] == ')') {
            nowDepth--;
        }
        if (valid(i)) {
            if (oddIsAnd) {
                if (nowDepth & 1) {
                    charPos[counter] = i;
                    charPosChar[counter++] = '*';
                } else {
                    charPos[counter] = i;
                    charPosChar[counter++] = '+';
                }
            } else {
                if (nowDepth & 1) {
                    charPos[counter] = i;
                    charPosChar[counter++] = '+';
                } else {
                    charPos[counter] = i;
                    charPosChar[counter++] = '*';
                }
            }
        }
    }
    newLength = 0;
    for (int i = 0, j = 0; i < length; i++) {
        newExpression[newLength++] = text[i];
        if (j < counter && charPos[j] == i) newExpression[newLength++] = charPosChar[j++];
    }
    newExpression[newLength] = '\0';
}

inline int prior(char op) {
    if (op == '+') {
        return 1;
    } else if (op == '*') {
        return 2;
    } else {
        return 0;
    }
}

int calculateExpression() {
    int postLength = 0;
    stack<char> op;
    for (int i = 0; i < newLength; i++) {
        char c = newExpression[i];
        if (c == 'T' || c == 'F') {
            if (c == 'T') postfixExpression[postLength++] = '1';
            else postfixExpression[postLength++] = '0';
        } else {
            if (c == '(') {
                op.push('(');
            } else {
                if (c == ')') {
                    while (op.top() != '(') {
                        postfixExpression[postLength++] = op.top();
                        op.pop();
                    }
                    op.pop();
                } else {
                    if (op.empty()) {
                        op.push(c);
                    } else {
                        if (prior(c) > prior(op.top())) {
                            op.push(c);
                        } else {
                            while (!op.empty() && prior(c) <= prior(op.top())) {
                                postfixExpression[postLength++] = op.top();
                                op.pop();
                            }
                            op.push(c);
                        }
                    }
                }
            }
        }
    }
    while (!op.empty()) {
        postfixExpression[postLength++] = op.top();
        op.pop();
    }
    stack<bool> s;
    for (int i = 0; i < postLength; i++) {
        if (postfixExpression[i] == '1' || postfixExpression[i] == '0') {
            s.push(postfixExpression[i] - '0');
        } else {
            bool y = s.top();
            s.pop();
            bool x = s.top();
            s.pop();
            if (postfixExpression[i] == '*') {
                s.push(x & y);
            } else {
                s.push(x | y);
            }
        }
    }
    return s.top();
}

int main() {

    int caseNum = 1;

    while (1) {
        gets(text);
        if (text[0] == '(' && text[1] == ')' && text[2] == '\0') break;

        deleteBlank();

        calculateDepth();
        if (depth & 1) oddIsAnd = true;
        else oddIsAnd = false;

        makeNewExpression();

        printf("%d. %s\n", caseNum++, (calculateExpression() ? "true" : "false"));

    }



    return 0;
}                                 