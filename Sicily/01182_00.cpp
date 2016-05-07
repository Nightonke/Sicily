// Problem#: 1182
// Submission#: 3550619
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

double degree[86400];

inline double abs(double a) {
    if (a < 0) return -a;
    return a;
}

void init() {
    double hourHandPos, minuteHandPos, differ;
    for (int i = 0; i < 24; i++) {
        for (int j = 0; j < 60; j++) {
            for (int k = 0; k < 60; k++) {
                hourHandPos = (i % 12) * 30 + (1.0 * j * 60 + k) / 120;
                minuteHandPos = j * 6 + 1.0 * k / 10;
                differ = hourHandPos > minuteHandPos ? 360 - hourHandPos + minuteHandPos : minuteHandPos - hourHandPos;
                degree[i * 3600 + j * 60 + k] = differ;
            }
        }
    }
    degree[86401] = 0;
}

double ERR = 0.08;

inline bool isSame(double d1, double d2) {
    if (d1 == 0) {
        return abs(d1 - d2) < ERR || abs(360.0 - d2) < ERR;
    }
    return abs(d1 - d2) < ERR;
}

int main() {

    init();

    while (1) {
        int h, m, s;
        double d;
        scanf("%lf %d:%d:%d", &d, &h, &m, &s);
        if (d == -1) break;
        int startPos = h * 3600 + m * 60 + s;
        bool found = false;
        int pos;
        for (pos = startPos; pos < 86400; ) {
            if (isSame(d, degree[pos])) break;
            pos++;
            if (pos == 86400) pos = 0;
        }
        printf("%02d:%02d:%02d\n", pos / 3600, (pos % 3600) / 60, pos % 3600 % 60);
    }

    return 0;
}                                 