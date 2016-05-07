// Problem#: 1941
// Submission#: 3589015
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAX_BUFFER_LEN = 30000;
const int MAX_FIELD_NUM = 500;
const int MAX_FIELD_LEN = 100;

char buf[MAX_BUFFER_LEN];
char str[MAX_FIELD_LEN];
int n;

char fields[MAX_FIELD_NUM][MAX_FIELD_LEN];
int nField;

void input() {
    n = 0;
    while ((buf[n] = getchar()) != EOF) n++;
}

void addField(char str[], int len) {
    char * p = str;
    if (p[0] < 0) p++;
    while (len > 0 && (str[len - 1] == ' ' || str[len - 1] == '\t')) len--;
    if (len > 0 && str[len - 1] < 0) len--;
    str[len] = '\0';
    strcpy(fields[nField], p);
    nField++;
}

void parse() {
    bool isValid = true;
    bool isQuoted = false;
    nField = 0;
    int count = 0;
    for (int i = 0; i < n; i++) {
        switch(buf[i]) {
        case '\n':
        case ',':
            if (isQuoted) str[count++] = buf[i];
            else {
                addField(str, count);
                count = 0;
            }
            break;
        case '"':
            if (isQuoted) {
                if (i + 1 < n && buf[i + 1] == '"') {
                    str[count++] = '"';
                    i++;
                } else {
                    str[count++] = -1;
                    isQuoted = false;
                }
            } else {
                if (count == 0) {
                    str[count++] = -1;
                    isQuoted = true;
                } else isValid = false;
            }
            break;
        case ' ':
        case '\t':
            if (isQuoted || count > 0) str[count++] = buf[i];
            break;
        default:
            str[count++] = buf[i];
            break;
        }
        if (!isValid) break;
    }
    if (isQuoted) isValid = false;
    if (!isValid) printf("Wrong Format\n");
    else {
        if (count > 0 || nField == 0) addField(str, count);
        for (int i = 0; i < nField; i++) printf("%s\n", fields[i]);
    }
}

int main() {
    input();
    parse();
    //int n;
    //scanf("%d", &n);
    return 0;
}                                 