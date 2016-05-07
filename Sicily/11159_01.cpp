// Problem#: 11159
// Submission#: 3054328
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<ctime>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<stack>
#include<string>
#define rep(i,a,b) for(int i=a;i<b;++i)
using namespace std;

inline int getint()
{
    char c;
    int ret=0;
    bool f=false;
    do c=getchar();
    while((c<'0' || c>'9') && c!='-');
    if(c=='-') f=true,c=getchar();
    do ret=ret*10+c-'0',c=getchar();
    while(c>='0' && c<='9');
    return f?-ret:ret;
}

#define N 1111
#define J 0.000000000001
int n,a[N],b[N];
double maxg,minl;
long long sum;

int main()
{
    n=getint();
    rep(i,0,n){
    a[i]=getint();
    b[i]=getint();
    sum+=b[i];
    }
    maxg=0;
    minl=1e7;
    rep(i,0,n-1){
    double t=double(sum*(long long)(a[i+1]-a[i]))/(double)(b[i]-b[i+1]);
    if(b[i]>b[i+1])
        maxg=max(maxg,t);
    else if(b[i]<b[i+1])
        minl=min(minl,t);
    else if(a[i]<a[i+1]){
        printf("-1\n");
        return 0;
    }
    }
    if(maxg<=minl)
    printf("%lf\n",(maxg+minl)/2);
    else
    printf("-1\n");
    return 0;
}                                 