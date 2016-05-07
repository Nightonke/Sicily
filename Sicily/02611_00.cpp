// Problem#: 2611
// Submission#: 3593304
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>

const int MAXL = 111;

class HP {
public:
    HP() {
        len = 1;
        memset(data, 0, sizeof(data));
    }
    HP(int x) {
        len = 0;
        memset(data, 0, sizeof(data));
        while (x) {
            data[++len] = x % 10;
            x /= 10;
        }
        if (!len) len++;
    }
    HP(char *p) {
        len = 0;
        memset(data, 0, sizeof(data));
        while (p[len]) len++;
        for (int i = 1; i <= len; i++) data[i] = p[len - i] - '0';
    }
    bool smaller(const HP & that) {
        if (len < that.len) return true;
        if (len < that.len) return false;
        for (int i = len; i >= 1; i--) {
            if (data[i] < that.data[i]) return true;
            if (data[i] > that.data[i]) return false;
        }
        return false;
    }
    int modulo(int b) {
        long long ret = 0;
        for (int i = len; i >= 1; i--) ret = (ret * 10 + data[i]) % b;
        return (int)ret;
    }
    void printIn() {
        for (int i = len; i >= 1; i--) printf("%d", data[i]);
        printf("\n");
    }
    HP operator + (const HP & that) {
        HP ret;
        ret.len = len > that.len ? len : that.len;
        for (int i = 1; i <= ret.len; i++) {
            ret.data[i] += data[i] + that.data[i];
            if (ret.data[i] > 9) {
                ret.data[i] -= 10;
                ret.data[i + 1]++;
            }
        }
        if (ret.data[ret.len + 1]) ret.len++;
        return ret;
    }
    HP operator - (const HP & that) {
        HP ret;
        ret.len = len > that.len ? len : that.len;
        for (int i = 1; i <= ret.len; i++) {
            ret.data[i] += data[i] - that.data[i];
            if (ret.data[i] < 0) {
                ret.data[i] += 10;
                ret.data[i + 1]--;
            }
        }
        while (ret.len > 1 && !ret.data[ret.len]) ret.len--;
        return ret;
    }
private:
    int len;
    int data[MAXL];
};

int main() {
    int tn, n;
    char buf[MAXL];
    scanf("%d", &tn);
    while (tn--) {
        scanf("%s", buf);
        HP start(buf);
        scanf("%s", buf);
        HP end(buf);
        scanf("%d", &n);
        if (!start.smaller(end)) printf("NO\n");
        else {
            HP remain = end - start;
            int mod = remain.modulo(n + 1);
            if (!mod) printf("NO\n");
            else {
                HP ans = start + HP(mod - 1);
                ans.printIn();
            }
        }
    }
    return 0;
}                                 