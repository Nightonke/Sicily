// Problem#: 1629
// Submission#: 3593580
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*
 * Polycube Solution
 *
 * by Fred Pickel
 * October 2008
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_PROBS   1000
#define EPS .001
#define ERR .001

char inbuf[512];
int nCubes;
int points[110][3];

int ReadDataSet(int index)
{
    int baseIndex, nLeft;
    if(fgets(&(inbuf[0]), 255, stdin) == NULL)
    {
        fprintf(stderr, "read of cube count failed on problem %d\n", index);
        return -1;
    }
    inbuf[255] = 0;
    nCubes = atoi(&(inbuf[0]));
    if((nCubes <= 0) || (nCubes > 100))
    {
        fprintf(stderr, "cube count %d out of range (1-100) on problem %d\n",
            nCubes, index);
        return -2;
    }
    baseIndex = 0;
    nLeft = nCubes;
    while(nLeft >= 8)
    {
        if(fgets(&(inbuf[0]), 255, stdin) == NULL)
        {
            fprintf(stderr, "read of cubes starting %d failed on problem %d\n",
                baseIndex, index);
            return -3;
        }
        inbuf[255] = 0;
        if(sscanf(&(inbuf[0]),
            "%d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d",
            &points[baseIndex+0][0], &points[baseIndex+0][1], &points[baseIndex+0][2], 
            &points[baseIndex+1][0], &points[baseIndex+1][1], &points[baseIndex+1][2], 
            &points[baseIndex+2][0], &points[baseIndex+2][1], &points[baseIndex+2][2], 
            &points[baseIndex+3][0], &points[baseIndex+3][1], &points[baseIndex+3][2], 
            &points[baseIndex+4][0], &points[baseIndex+4][1], &points[baseIndex+4][2], 
            &points[baseIndex+5][0], &points[baseIndex+5][1], &points[baseIndex+5][2], 
            &points[baseIndex+6][0], &points[baseIndex+6][1], &points[baseIndex+6][2], 
            &points[baseIndex+7][0], &points[baseIndex+7][1], &points[baseIndex+7][2]) != 24)
        {
            fprintf(stderr, "scan of cubes starting %d failed on problem %d\n",
                baseIndex, index);
            return -4;
        }
        baseIndex += 8;
        nLeft -= 8;
    }
    // do any left
    if(nLeft > 0)
    {
        if(fgets(&(inbuf[0]), 255, stdin) == NULL)
        {
            fprintf(stderr, "read of cubes starting %d failed on problem %d\n",
                baseIndex, index);
            return -3;
        }
        inbuf[255] = 0;
        if(sscanf(&(inbuf[0]),
            "%d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d %d,%d,%d",
            &points[baseIndex+0][0], &points[baseIndex+0][1], &points[baseIndex+0][2], 
            &points[baseIndex+1][0], &points[baseIndex+1][1], &points[baseIndex+1][2], 
            &points[baseIndex+2][0], &points[baseIndex+2][1], &points[baseIndex+2][2], 
            &points[baseIndex+3][0], &points[baseIndex+3][1], &points[baseIndex+3][2], 
            &points[baseIndex+4][0], &points[baseIndex+4][1], &points[baseIndex+4][2], 
            &points[baseIndex+5][0], &points[baseIndex+5][1], &points[baseIndex+5][2], 
            &points[baseIndex+6][0], &points[baseIndex+6][1], &points[baseIndex+6][2], 
            &points[baseIndex+7][0], &points[baseIndex+7][1], &points[baseIndex+7][2]) != 3*nLeft)
        {
            fprintf(stderr, "scan of cubes starting %d failed on problem %d\n",
                baseIndex, index);
            return -4;
        }
    }
    return 0;
}

int IsNbr(int pt1[3], int pt2[3])
{
    if((pt1[0] == pt2[0]) && (pt1[1] == pt2[1]))
    {
        if(pt1[2] == pt2[2])
        {   // same
            return -1;
        }
        if(pt1[2] == (pt2[2]+1))
        {
            return 1;
        }
        if(pt1[2] == (pt2[2]-1))
        {
            return 1;
        }
    }
    if((pt1[0] == pt2[0]) && (pt1[2] == pt2[2]))
    {
        if(pt1[1] == (pt2[1]+1))
        {
            return 1;
        }
        if(pt1[1] == (pt2[1]-1))
        {
            return 1;
        }
    }
    if((pt1[2] == pt2[2]) && (pt1[1] == pt2[1]))
    {
        if(pt1[0] == (pt2[0]+1))
        {
            return 1;
        }
        if(pt1[0] == (pt2[0]-1))
        {
            return 1;
        }
    }
    return 0;
}
// find out how many previous cubes have a face in common with cube
// centered at pt return -1 if same as previous else count of faces in common
int CountNbrs(int pt[3], int prevPoint)
{
    int i, ret, cnt;
    for(i = 0, cnt = 0; i <= prevPoint ; i++)
    {
        ret = IsNbr(pt, &(points[i][0]));
        if(ret < 0)
        {
            return -1;
        }
        else
        {
            cnt += ret;
        }
    }
    return cnt;
}

int CountArea()
{
    int area, i, cnt;
    area = 6;   // first cube
    for(i = 1; i < nCubes ; i++)
    {
        cnt = CountNbrs(&(points[i][0]), i-1);
        if(cnt <= 0)
        {
            return -(i+1);
        }
        else
        {
            area += (6 - 2*cnt);
        }
    }
    return area;
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
        if((ret = ReadDataSet(curProb)) != 0)
        {
            fprintf(stderr, "ReadDataSet returned %d on problem %d\n", ret, curProb);
            return -3;
        }
        ret = CountArea();
        if(ret < 0)
        {
            printf("%d NO %d\n", curProb, -ret);
        }
        else
        {
            printf("%d %d\n", curProb, ret);
        }
    }
    return 0;
}                                 