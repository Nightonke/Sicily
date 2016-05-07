// Problem#: 1151
// Submission#: 3958405
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
// Problem#: 1151
// Submission#: 87817
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
/*����ħ��*/
#include<stdio.h>
#include<string.h>
const long max=50000;
char s[max],ss[max];
long a[max],b[max][8],c[max],z[10],x[8],e[max],f[max];
bool d[max];
int main()
{
    long i,j,p,q,n,temp;
    z[0]=1;
    for (i=1;i<10;i++)
        z[i]=z[i-1]*i;
    b[0][0]=1;
    b[0][1]=2;
    b[0][2]=3;
    b[0][3]=4;
    b[0][4]=8;
    b[0][5]=7;
    b[0][6]=6;
    b[0][7]=5;
    temp=0;
    for (i=1;i<8;i++)
        for (j=0;j<i;j++)
            if (b[0][j]>b[0][i])
                temp+=z[i];
    d[temp]=1;
    c[0]=temp;
    f[temp]=-1;
    p=0;
    q=1;
    while (p<q)
    {
        b[q][0]=b[p][3];
        b[q][1]=b[p][0];
        b[q][2]=b[p][1];
        b[q][3]=b[p][2];
        b[q][4]=b[p][7];
        b[q][5]=b[p][4];
        b[q][6]=b[p][5];
        b[q][7]=b[p][6];
        temp=0;
        for (i=1;i<8;i++)
            for (j=0;j<i;j++)
                if (b[q][j]>b[q][i])
                    temp+=z[i];
        if (d[temp]==0)
        {
            d[temp]=1;
            s[temp]='B';
            a[q]=a[p]+1;
            e[temp]=a[q];
            c[q]=temp;
            f[temp]=c[p];
            q++;
        }
        for (i=0;i<8;i++)
            b[q][(i+4)%8]=b[p][i];
        temp=0;
        for (i=1;i<8;i++)
            for (j=0;j<i;j++)
                if (b[q][j]>b[q][i])
                    temp+=z[i];
        if (d[temp]==0)
        {
            d[temp]=1;
            s[temp]='A';
            a[q]=a[p]+1;
            e[temp]=a[q];
            c[q]=temp;
            f[temp]=c[p];
            q++;
        }
        b[q][0]=b[p][0];
        b[q][1]=b[p][5];
        b[q][2]=b[p][1];
        b[q][3]=b[p][3];
        b[q][4]=b[p][4];
        b[q][5]=b[p][6];
        b[q][6]=b[p][2];
        b[q][7]=b[p][7];
        temp=0;
        for (i=1;i<8;i++)
            for (j=0;j<i;j++)
                if (b[q][j]>b[q][i])
                    temp+=z[i];
        if (d[temp]==0)
        {
            d[temp]=1;
            s[temp]='C';
            a[q]=a[p]+1;
            e[temp]=a[q];
            c[q]=temp;
            f[temp]=c[p];
            q++;
        }
        p++;
    }
    while (1)
    {
        scanf("%ld",&n);
        if (n==-1)
            break;
        for (i=0;i<8;i++)
            scanf("%ld",x+i);
        temp=0;
        for (i=1;i<8;i++)
            for (j=0;j<i;j++)
                if (x[j]>x[i])
                    temp+=z[i];
        if (d[temp]==0||e[temp]>n)
            printf("-1\n");
        else
        {
            i=temp;
            j=max-2;
            while (f[i]!=-1)
            {
                ss[j]=s[i];
                i=f[i];
                j--;
            }
            printf("%ld %s\n",e[temp],&ss[j+1]);
        }
    }
    return 0;
}                                 