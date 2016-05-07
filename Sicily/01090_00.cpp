// Problem#: 1090
// Submission#: 2778954
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<iostream> 
#define N 99999
#define M 500
using namespace std;int n,r[M][M],a;void P(){bool u[n];fill(u,u+n,0);int c[n],i;fill(c,c+n,N);a=c[0]=0;int p;while(1){p=-1;for(i=0;i<n;i++)if(!u[i]&&(p==-1||c[p]>c[i]))p=i;if(p==-1)break;u[p]=1;a=a>c[p]?a:c[p];for(i=0;i<n;i++)c[i]=c[i]<r[p][i]?c[i]:r[p][i];}}int main(){std::ios::sync_with_stdio(0);int s,i,j;bool b=0;cin>>s;while(s--){if(b)cout<<endl;b=true;cin>>n;for(i=0;i<n;i++)for(j=0;j<n;j++)cin>>r[i][j];P();cout<<a<<endl;}return 0;}                                 