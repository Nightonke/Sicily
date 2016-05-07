// Problem#: 1133
// Submission#: 2777848
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

char text1[500];
char text2[100];
char text3[100];
int len;

bool isValpos(char c)
{
    if ('a' <= c && c <= 'z')
    {
        return true;
    }

    if ('A' <= c && c <= 'Z')
    {
        return true;
    }
    
    if ('0' <= c && c <= '9')
    {
        return true;
    }

    if (c == '-' || c == '_')
    {
        return true;
    }
    
    return false;
}

int text2Len(int pos)
{
    int dis;

    dis = 0;
    for (int i = pos; i >= 0; i --)
    {
        if (isValpos(text1[i]))
        {
            dis ++;
        }
        else if (text1[i] == '.')
        {
            if (i <= 0)
            {
                break;
            }
            else
            {
                if (isValpos(text1[i - 1]))
                {
                    dis ++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    return dis;
}

int text3Len(int pos)
{
    int dis;

    dis = 0;
    for (int i = pos; i < len; i ++)
    {
        if (isValpos(text1[i]))
        {
            dis ++;
        }
        else if (text1[i] == '.')
        {
            if (i >= len - 1)
            {
                break;
            }
            else
            {
                if (isValpos(text1[i + 1]))
                {
                    dis ++;
                }
                else
                {
                    break;
                }
            }
        }
        else
        {
            break;
        }
    }

    return dis;
}

int main()
{
    int pos;
    int length1, length2;
    char c;
    
    len = 0;
    while (scanf("%c", &c) != EOF)
    {
        text1[len ++] = c;
    }
    text1[len] = '\0';

    for (int i = 0; i < len; i ++)
    {
        if (text1[i] == '@')
        {
            length1 = text2Len(i - 1);
            length2 = text3Len(i + 1);
            
            if (length1 && length2)
            {
                for (int j = i - length1; j <= i + length2; j ++)
                {
                    printf("%c", text1[j]);
                }
            
                printf("\n");
            }
        }
    }

    return 0;
}                                 