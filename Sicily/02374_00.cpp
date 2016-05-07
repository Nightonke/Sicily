// Problem#: 2374
// Submission#: 3593624
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * G - Old Fashioned Typesetting
 * ACM International Collegiate Programming Contest
 * Greater New York Region
 * October 24, 2010
 */     

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define BUFSIZE 1002        /* max of 1000 chars + '\n' + '\0' */

static struct {
    char *outstr;
    int backup;
} accept[] = {
    {0, 0},
    {"[AE]", 0}, {"[ae]", 0}, {"[OE]", 0}, {"[oe]", 0}, {"[ct]", 0},
    {"[fi]", 0}, {"[fl]", 0}, {"[ff]", 1}, {"[ffi]", 0}, {"[ffl]", 0},
    {"[longs]", 1}, {"[longsi]", 0}, {"[longsh]", 0}, {"[longsl]", 0},
    {"[longst]", 0}, {"[longss]", 1}, {"[longssi]", 0}, {"[longs]s", 1}
};

static int transtab[256][10];

void init_transtab()
{
    int i;

    /* State 1: A... */
    transtab['A'][0] = 1;
    transtab['e'][1] = transtab['E'][1] = -1;

    /* State 2: a... */
    transtab['a'][0] = 2;
    transtab['e'][2] = transtab['E'][2] = -2;

    /* State 3: O... */
    transtab['O'][0] = 3;
    transtab['e'][3] = transtab['E'][3] = -3;

    /* State 4: o... */
    transtab['o'][0] = 4;
    transtab['e'][4] = transtab['E'][4] = -4;

    /* State 5: c... */
    transtab['c'][0] = 5;
    transtab['t'][5] = -5;

    /* State 6: f... */
    transtab['f'][0] = 6;
    transtab['i'][6] = -6;
    transtab['l'][6] = -7;

    /* State 7: ff... */
    transtab['f'][6] = 7;
    for (i = 0; i < 256; i++) { transtab[i][7] = -8; }
    transtab['i'][7] = -9;
    transtab['l'][7] = -10;

    /* State 8: s... */
    transtab['s'][0] = 8;
    for (i = 0; i < 26; i++) {
        transtab['a' + i][8] = transtab['A' + i][8] = -11;
    }
    transtab['f'][8] = transtab['b'][8] = transtab['k'][8] = 0;
    transtab['i'][8] = -12;
    transtab['h'][8] = -13;
    transtab['l'][8] = -14;
    transtab['t'][8] = -15;
    transtab['s'][8] = 9;

    /* State 9: ss... */
    for (i = 0; i < 256; i++) { transtab[i][9] = -18; }
    for (i = 0; i < 26; i++) {
        transtab['a' + i][9] = transtab['A' + i][9] = -16;
    }
    transtab['f'][9] = transtab['b'][9] = transtab['k'][9] = -18;
    transtab['i'][9] = -17;
    transtab['s'][9] = -18;
}

void process(const char *s)
{
    const char *curr, *start;
    int state = 0;
    for (curr = start = s; *curr != '\0'; curr++) {
        int old_state = state;
        state = transtab[*curr][state];
        if (state == 0) {   /* no ligature found */
            if (old_state == 0) {
                putchar(*curr); /* print single char */
            } else {
                /* print multi chars & reprocess current char */
                printf("%.*s", curr - start, start);
                --curr;
            }
        } if (state < 0) {
            /* accept */
            printf("%s", accept[-state].outstr);
            curr -= accept[-state].backup;
            state = 0;
        } else if (old_state == 0) {
            start = curr;
        }
    }
}

int main()
{
    int i, p, n;
    char buf[BUFSIZE];
    init_transtab();
    scanf("%d\n", &p);
    for (i = 0; i < p; i++) {
        scanf("%d ", &n);
        assert(n == i + 1);
        printf("%d ", n);
        fgets(buf, BUFSIZE, stdin);
        process(buf);
    }
    return EXIT_SUCCESS;
}                                 