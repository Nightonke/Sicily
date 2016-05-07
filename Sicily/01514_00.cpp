// Problem#: 1514
// Submission#: 3593479
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAX_PROBS   1000
#define MAX_PANCAKES    30

char inbuf[256];
int nPancakes;
int pancakes[MAX_PANCAKES];
int moves[3*MAX_PANCAKES];
int curLoc[MAX_PANCAKES+1];

int parseInput(char *pIn)
{
    char *p;
    int i, ret, val, ind;
    /* get number of pancakes */
    p = pIn;
    while((*p != 0) && (isspace(*p))) p++;
    if(*p == 0)
    {
        return -2;
    }
    ret = atoi(p);
    if((ret < 1) || (ret > MAX_PANCAKES))
    {
        return -1;
    }
    for(i = 1; i <= ret; i++) curLoc[i] = 0;
    /* read ret pancakes */
    for(i = 0; i < ret ; i++)
    {
        /* skip past prev item */
        while((*p != 0) && (!isspace(*p))) p++;
        while((*p != 0) && (isspace(*p))) p++;
        if(*p == 0)
        {
            return -2;
        }
        if((*p != '+') && (*p != '-'))
        {
            return -3;
        }
        val = atoi(p);
        if((val == 0) || (val < -ret) || (val > ret))
        {
            return -4;
        }
        ind = abs(val);
        if(curLoc[ind] != 0)
        {
            return -5;
        }
        pancakes[i] = val;
        curLoc[ind] = i+1;
    }
    /* check all seen */
    for(i = 1; i <= ret; i++)
    {
        if(curLoc[i] == 0)
        {
            return -6;
        }
    }
    nPancakes = ret;
    return ret;
}

/* flip top k pancakes */
void flip(int k)
{
    int i, j, tmp;
    i = 0; j = k-1;
    while(i < j)
    {   /* swap values and change signs */
        tmp = -pancakes[i];
        pancakes[i] = -pancakes[j];
        pancakes[j] = tmp;
        i++;
        j--;
    }
    if(i == j)
    {
        pancakes[i] = -pancakes[i];
    }
    /* fix locations */
    for(i = 1; i <= nPancakes; i++)
    {
        if(curLoc[i] <= k)
        {
            curLoc[i] = k + 1 - curLoc[i];
        }
    }
}

/* for each size from largest to smallest, if not correct, flip to top
 * make burned side up, flip to correct position
 */
int FindSoln()
{
    int curPk, curStep;

    curStep = 0;
    for(curPk = nPancakes ; curPk > 0 ; curPk--)
    {
        if((curLoc[curPk] != curPk) || (pancakes[curLoc[curPk]-1] < 0))
        {   /* not in correct place or correct orientation */
            if(curPk > 1)
            {
                /* flip from cur loc to top */
                if(curLoc[curPk] != 1)
                {
                    moves[curStep++] = curLoc[curPk];
                    flip(curLoc[curPk]);
                }
                if(pancakes[0] > 0)
                {
                    moves[curStep++] = 1;
                    flip(1);
                }
                moves[curStep++] = curPk;
                flip(curPk);
            }
            else
            {
                moves[curStep++] = 1;
                flip(1);
            }
        }
    }
    return curStep;
}

/* print nStep followed by nStep moves */
void PrintSoln(int probNum, int nStep)
{
    int i;
    printf("%d %d", probNum, nStep);
    for(i = 0; i < nStep ; i++)
    {
        printf(" %d", moves[i]);
    }
    printf("\n");
}

int main()
{
    int probCnt, curProb, ret;

    if(fgets(&(inbuf[0]), 255, stdin) == NULL)
    {
        fprintf(stderr, "read failed on problem count\n");
        return -1;
    }
    inbuf[255] = 0;
    probCnt = atoi(&(inbuf[0]));
    if((probCnt < 1) || (probCnt > MAX_PROBS))
    {
        fprintf(stderr, "Problem count %d not in range 1...%d\n", probCnt, MAX_PROBS);
        return -2;
    }
    for(curProb = 1; curProb <= probCnt ; curProb++)
    {
        if(fgets(&(inbuf[0]), 255, stdin) == NULL)
        {
            fprintf(stderr, "read failed on problem %d\n", curProb);
            return -3;
        }
        if((ret = parseInput(&(inbuf[0]))) < 0)
        {
            fprintf(stderr, "parseInput returned %d on problem %d\n", ret, curProb);
            return -4;
        }
        ret = FindSoln();
        PrintSoln(curProb, ret);
    }
    return 0;
}                                 