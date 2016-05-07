// Problem#: 1300
// Submission#: 3263835
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <iostream>
#include <math.h>
using namespace std;
long k;
long long b[32],m[32];
 
//满足负数求mod
long long mod(long long a ,long long b)
{return (a%b+b)%b;}
 
//求解ax+by=gcd(a,b),扩展欧几里得
void Mgcd(long long a,long long b,long long &d,long long &x,long long &y)
{
    if(b==0){d=a;x=1;y=0;return;}
    Mgcd(b,a%b,d,y,x);y-=x*(a/b);
}
//求解ux mod m = 1
long long Inv(long long u ,long long m )
{long long d,x,y;Mgcd(u,m,d,x,y);return mod(x,m);}
 
 
bool same()
{
    long i;for( i=2 ; i<=k ; i++ )
    {if( b[i]!=b[i-1] ) return false;}
    return true;
}
 
//中国剩余定理
long long China()
{
    long i;long long M=1,x=0;
    for(i=1;i<=k;i++)M*=m[i];
    if(same()){return mod(b[1],M);}/////这是判断余数是否全相等，全相等则直接可得出答案
 
    for(i=1;i<=k;i++)b[i]=mod(b[i],m[i]);////将b[]变为正整数
 
    for( i=1 ; i<=k ; i++ )
    {x+=b[i]*(M/m[i])*Inv(M/m[i],m[i]);}
   
    return x%=M;
}
int main()
{
    long i;
   
    while(scanf("%ld",&k),k>0)
    {
        for(i=1;i<=k;i++)cin >> b[i];
        for(i=1;i<=k;i++)cin >> m[i];
        printf("%lld\n",China());
    }
    return 0;
}                                 