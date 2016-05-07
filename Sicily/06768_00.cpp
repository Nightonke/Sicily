// Problem#: 6768
// Submission#: 2704551
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

bool is_night_time(int sr, int ss, int s, int e) {
    if (sr >= s && sr >= e)
        return true;
    if (s >= ss && e >= ss)
        return true;
    if (s >= sr && e <= ss)
        return false;
    if (s <= sr && e >= sr) {
        if (sr - s >= e - sr) {
            return true;
        } else {
            return false;
        }
    }
    if (s <= ss && e >= ss) {
        if (e - ss >= ss - s) {
            return true;
        } else {
            return true;
        }
    }
}

int main() {
    int i, n, sum_all, sum_night, srh, srm, ssh, ssm, sh, sm, eh, em, sr, ss, s, e;
    bool is_pass;
    char a[30];
    while (scanf("%d\n", &n), n) {
        for (is_pass = true, i = 0, sum_all = 0, sum_night = 0; i < n; i++) {
            gets(a);
            srh = (a[0] - '0') * 10 + a[1] - '0';
            srm = (a[3] - '0') * 10 + a[4] - '0';
            ssh = (a[6] - '0') * 10 + a[7] - '0';
            ssm = (a[9] - '0') * 10 + a[10] - '0';
            sh = (a[12] - '0') * 10 + a[13] - '0';
            sm = (a[15] - '0') * 10 + a[16] - '0';
            eh = (a[18] - '0') * 10 + a[19] - '0';
            em = (a[21] - '0') * 10 + a[22] - '0';
            sr = srh * 60 + srm;
            ss = ssh * 60 + ssm;
            s = sh * 60 + sm;
            e = eh * 60 + em;
            sum_all += e - s;
            if (e - s > 120)
                is_pass = false;
            if (is_night_time(sr, ss, s, e)) {
                sum_night += e - s;
            }
        }
        if (is_pass && sum_night >= 10 * 60 && sum_all >= 50 * 60) {
            printf("PASS\n");
        } else {
            printf("NON\n");
        }
    }
    return 0;
}                                 