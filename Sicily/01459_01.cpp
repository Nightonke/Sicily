// Problem#: 1459
// Submission#: 2773676
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<algorithm>
int main(){int n,m,h[20000],k[20000],p,i,j,c,s;while(scanf("%d%d",&n,&m)&&n){i=n;while(i--)scanf("%d",&h[i]);j=m;while(j--)scanf("%d",&k[j]);std::sort(h,h+n);std::sort(k,k+m);for(c=s=p=i=0;i<n;i++)for(j=p;j<m;j++)if(h[i]<=k[j]){c++;s+=k[j];p=j+1;break;}if(c==n)printf("%d\n",s);else printf("Loowater is doomed!\n");}return 0;}                                 