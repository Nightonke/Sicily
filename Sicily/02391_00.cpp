// Problem#: 2391
// Submission#: 3536224
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
const int I=1e8;long long d[2][3];int N;inline long long m(long long a,long long b){if(a<b)return a;else return b;}int main(){int c=1;while(scanf("%d",&N)&&N){int G0,G1,G2;scanf("%d%d%d",&G0,&G1,&G2);d[0][0]=I;d[0][1]=G1;d[0][2]=d[0][1]+G2;int l=0,n=1;for(int i=1;i<N;i++){scanf("%d%d%d",&G0,&G1,&G2);d[n][0]=m(d[l][0],d[l][1])+G0;d[n][1]=m(d[n][0],m(d[l][2],m(d[l][0],d[l][1])))+G1;d[n][2]=m(d[n][1],m(d[l][1],d[l][2]))+G2;n^=1;l^=1;}printf("%d. %lld\n",c++,d[l][1]);}return 0;}                                 