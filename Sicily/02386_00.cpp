// Problem#: 2386
// Submission#: 2811546
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<algorithm>
using namespace std;int c[5],k;int o(){int i,u,x[3]={c[3],c[4],k},y[3]={c[0],c[1],c[2]},p[3]={0,1,2};for(i=0;i<5;)if(k==c[i++])return 0;while(1){for(i=u=0;i<3;i++)if(y[p[i]]>x[i])u++;if(u>=2)return 0;if(!next_permutation(p,p+3))return 1;}}int main(){while(scanf("%d",&c[0])&&c[0]){int i;for(i=1;i<5;i++)scanf("%d",&c[i]);for(k=1;k<53;k++)if(o())break;printf("%d\n",(k+1)%54-1);}return 0;}                                 