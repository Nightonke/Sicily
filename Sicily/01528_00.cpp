// Problem#: 1528
// Submission#: 3593482
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>

/*
 * flat layout                  answer layout
 * image elements in order      image elements in order
 * corner numbers labeled
 *      3---2
 *      | 1 |       
 *  3---0---1---2---3               \ 1 /
 *  | 2 | 3 | 4 | 5 |                 Y
 *  7---4---5---6---7               3 | 2
 *      | 6 |
 *      7---6
 */
char inbuf[512];

int flatImage[6], flatOrient[6];
int ansImage[5][3], ansOrient[5][3];
int cornerImage[8][3], cornerOrient[8][3]; // images clockwise around each corner from flat
int nSolns;
char solnIndex[5];

int GetCornerVals(int probNum)
{
    // corner 0 = 1, 3, 2
    cornerImage[0][0] = flatImage[0];
    cornerOrient[0][0] = (flatOrient[0] + 1) % 4;   // up corresp to 2
    cornerImage[0][1] = flatImage[2];
    cornerOrient[0][1] = flatOrient[2]; // up corresp to 1
    cornerImage[0][2] = flatImage[1];
    cornerOrient[0][2] = (flatOrient[1] + 3) % 4;   // up corresp to 4
    // corner 1 = 1, 4, 3
    cornerImage[1][0] = flatImage[0];
    cornerOrient[1][0] = (flatOrient[0] + 2) % 4;   // up corresp to 3
    cornerImage[1][1] = flatImage[3];
    cornerOrient[1][1] = flatOrient[3]; // up corresp to 1
    cornerImage[1][2] = flatImage[2];
    cornerOrient[1][2] = (flatOrient[2] + 3) % 4;   // up corresp to 4
    // corner 2 = 1, 5, 4
    cornerImage[2][0] = flatImage[0];
    cornerOrient[2][0] = (flatOrient[0] + 3) % 4;   // up corresp to 3
    cornerImage[2][1] = flatImage[4];
    cornerOrient[2][1] = flatOrient[4]; // up corresp to 1
    cornerImage[2][2] = flatImage[3];
    cornerOrient[2][2] = (flatOrient[3] + 3) % 4;   // up corresp to 4
    // corner 3 = 1, 2, 5
    cornerImage[3][0] = flatImage[0];
    cornerOrient[3][0] = flatOrient[0]; // up corresp to 1
    cornerImage[3][1] = flatImage[1];
    cornerOrient[3][1] = flatOrient[1]; // up corresp to 1
    cornerImage[3][2] = flatImage[4];
    cornerOrient[3][2] = (flatOrient[4] + 3) % 4;   // up corresp to 4
    // corner 4 = 6, 2, 3
    cornerImage[4][0] = flatImage[5];
    cornerOrient[4][0] = flatOrient[5]; // up corresp to 1
    cornerImage[4][1] = flatImage[1];
    cornerOrient[4][1] = (flatOrient[1] + 2) % 4;   // up corresp to 3
    cornerImage[4][2] = flatImage[2];
    cornerOrient[4][2] = (flatOrient[2] + 1) % 4;   // up corresp to 2
    // corner 5 = 6, 3, 4
    cornerImage[5][0] = flatImage[5];
    cornerOrient[5][0] = (flatOrient[5] + 3) % 4;   // up corresp to 4
    cornerImage[5][1] = flatImage[2];
    cornerOrient[5][1] = (flatOrient[2] + 2) % 4;   // up corresp to 3
    cornerImage[5][2] = flatImage[3];
    cornerOrient[5][2] = (flatOrient[3] + 1) % 4;   // up corresp to 2
    // corner 6 = 6, 4, 5
    cornerImage[6][0] = flatImage[5];
    cornerOrient[6][0] = (flatOrient[5] + 2) % 4;   // up corresp to 3
    cornerImage[6][1] = flatImage[3];
    cornerOrient[6][1] = (flatOrient[3] + 2) % 4;   // up corresp to 3
    cornerImage[6][2] = flatImage[4];
    cornerOrient[6][2] = (flatOrient[4] + 1) % 4;   // up corresp to 2
    // corner 7 = 6, 5, 2
    cornerImage[7][0] = flatImage[5];
    cornerOrient[7][0] = (flatOrient[5] + 1) % 4;   // up corresp to 2
    cornerImage[7][1] = flatImage[4];
    cornerOrient[7][1] = (flatOrient[4] + 2) % 4;   // up corresp to 3
    cornerImage[7][2] = flatImage[1];
    cornerOrient[7][2] = (flatOrient[1] + 1) % 4;   // up corresp to 2

    return 0;
}

int TestAns(int *pImg, int *pOrient)
{
    int corner, ort;
    for(corner = 0; corner < 8 ; corner++)
    {
        for(ort = 0; ort < 3; ort++)
        {
            if((cornerImage[corner][ort] == pImg[0]) &&
                (cornerOrient[corner][ort] == pOrient[0]))
            {   // first ans face matches, check the others
                if((cornerImage[corner][(ort + 1) %3] == pImg[1]) &&
                    (cornerOrient[corner][(ort + 1) %3] == pOrient[1]) &&
                    (cornerImage[corner][(ort + 2) %3] == pImg[2]) &&
                    (cornerOrient[corner][(ort + 2) %3] == pOrient[2]))
                {   // complete match
                    return (3 * corner + ort);
                }
            }
        }
    }
    return -1;
}

void CountPrintMatch(int probNum)
{
    int i;
    // count solns
    nSolns = 0;
    for(i = 0; i < 5; i++)
    {
        if(TestAns(&(ansImage[i][0]), &(ansOrient[i][0])) >= 0)
        {   // its a soln
            solnIndex[i] = 'Y';
            nSolns++;
        }
        else
        {
            solnIndex[i] = 'N';
        }
    }
    // print result
    printf("%d %d", probNum, nSolns);
    for(i = 0; i < 5 ; i++)
    {
        printf(" %c", solnIndex[i]);
    }
    printf("\n");
}

int ParseFlatLayout(int probNum)
{
    int i, j;
    char c;

    if(fgets(&(inbuf[0]), 511, stdin) == NULL)
    {
        fprintf(stderr, "Read failed on flat layout problem %d\n", probNum);
        return -4;
    }
    
    for(i = 0, j = 0; i < 6; i++)
    {
        c = inbuf[j];
        if((c < 'A') || (c > 'F'))
        {
            fprintf(stderr, "bad face name[%d] %c (0x%02x) flat layout problem %d\n",
                i+1, c, c, probNum);
            return -5;
        }
        flatImage[i] = c - 'A';
        j++;
        c = inbuf[j];
        if((c < '1') || (c > '4'))
        {
            fprintf(stderr, "bad face orientation[%d] %c (0x%02x) flat layout problem %d\n",
                i+1, c, c, probNum);
            return -6;
        }
        flatOrient[i] = c - '1';
        j++;
    }
    return 0;
}

int ParseAnswer(int probNum, int ansNum)
{
    int i, j;
    char c;

    if(fgets(&(inbuf[0]), 511, stdin) == NULL)
    {
        fprintf(stderr, "Read failed on flat layout problem %d\n", probNum);
        return -7;
    }
    
    for(i = 0, j = 0; i < 3; i++)
    {
        c = inbuf[j];
        if((c < 'A') || (c > 'F'))
        {
            fprintf(stderr, "bad face name[%d] %c (0x%02x) answer %d problem %d\n",
                i+1, c, c, ansNum + 1, probNum);
            return -8;
        }
        ansImage[ansNum][i] = c - 'A';
        j++;
        c = inbuf[j];
        if((c < '1') || (c > '4'))
        {
            fprintf(stderr, "bad face orientation[%d] %c (0x%02x) answer %d problem %d\n",
                i+1, c, c, ansNum + 1, probNum);
            return -9;
        }
        ansOrient[ansNum][i] = c - '1';
        j++;
    }
    return 0;
}

int main()
{
    int nProbs, probNum, ret, ansInd;

    if(fgets(&(inbuf[0]), 511, stdin) == NULL)
    {
        fprintf(stderr, "Read failed on problem count\n");
        return -1;
    }
    if(sscanf(&(inbuf[0]), "%d", &nProbs) != 1)
    {
        fprintf(stderr, "Scan failed on problem count\n");
        return -2;
    }
    if((nProbs < 1) || (nProbs > 1000))
    {
        fprintf(stderr, "problem count %d not in range 1 to 1000\n", nProbs);
        return -3;
    }
    for(probNum = 1; probNum <= nProbs ; probNum++)
    {
        ret = ParseFlatLayout(probNum);
        if(ret != 0)
        {
            return ret;
        }
        GetCornerVals(probNum);
        for(ansInd = 0; ansInd < 5 ; ansInd++)
        {
            ret = ParseAnswer(probNum, ansInd);
            if(ret != 0)
            {
                return ret;
            }
        }
        CountPrintMatch(probNum);
    }
    return 0;
}                                 