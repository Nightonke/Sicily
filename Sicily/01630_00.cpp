// Problem#: 1630
// Submission#: 3593584
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * Algorithm from F. J. Gruenberger, "What Should We Compute?", RAND
 * Corporation, September 1963
 *
 * Program by Lee Wittenberg, Kean University
 * October 2008
 */
#include <stdio.h>

//#define UNIX
#ifdef UNIX
typedef long long long long;
#define FORMAT  "%d %d %lld\n"
#else
#define FORMAT  "%d %d %lld\n"
#endif

#define NUM_DIGITS  20

int ZERO[NUM_DIGITS] = {0};

void copy_num(int src[], int dest[])
{
    int i;
    for (i = 0; i < NUM_DIGITS; i++)
        dest[i] = src[i];
}

void mult(int a[], int b[], int result[])
{
    int i, j, r;
    copy_num(ZERO, result);
    for (i = 0; i < NUM_DIGITS; i++) {
        if (a[i] == 0) continue;
        for (j = 0; j < NUM_DIGITS; j++) {
            if(b[j] == 0) continue;
            r = i + j;
            if (r < NUM_DIGITS) {
                result[r] += a[i] * b[j];
            }
            if (r < NUM_DIGITS - 1 && result[r] > 9) {
                result[r + 1] += result[r] / 10;
            }
            if (r < NUM_DIGITS) {
                result[r] %= 10;
            }
        }
    }
}

int powtab[50][NUM_DIGITS] = {{2}};
long long ntab[21] = {0, 1};

int digits_ok(int pow[], int r)
{
    int i;
    for(i = 0; i < r; i++) {
        if (pow[i] != 1 && pow[i] != 2)
            return 0 == 1;
    }
    return 1 == 1;
}

void init_powtab()
{
    int i;
    for (i = 0; i < 49; i++) {
        mult(powtab[i],powtab[i],powtab[i+1]);
    }
}

void new_pow(long long n, int result[])
{
    int i;
    copy_num(ZERO, result);
    result[0] = 1;
    for (i = 0; n != 0; i++) {
        if ((n & 0x1) != 0) {
            int temp[NUM_DIGITS];
            mult(result, powtab[i], temp);
            copy_num(temp, result);
        }
        n >>= 1;
    }
}

int main()
{
    int i, r, num_cases;
    int pow[NUM_DIGITS] = {2,3};    // 32
    long long delta, n;

    init_powtab();
    delta = 4; n = 5;
    for (r = 2; r <= 20; r++) {
        while (!digits_ok(pow, r)) {
            n += delta;
            new_pow(n, pow);
        }
        ntab[r] = n;
        delta *= 5;
    }

    scanf("%d\n", &num_cases);
    for (i = 1; i <= num_cases; i++) {
        scanf("%d", &r);
        printf(FORMAT, i, r, ntab[r]);
    }
    return 0;
}                                 