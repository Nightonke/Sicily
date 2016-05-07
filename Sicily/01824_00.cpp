// Problem#: 1824
// Submission#: 3273773
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
short dat[1001][1001];
short cost[1001];
int dp[1001][1001]={0};
int max[2]={0},n,m,p;
int main()
{
 int i,j,k;
 scanf("%d %d %d",&n,&m,&p);
 for(i=0;i<n;i++)for(j=1;j<=m;j++)
 scanf("%d",&dat[i][j]);
 
 for(i=0;i<n;i++)scanf("%d",&cost[i]); 
 
 for(i=1;i<=m;i++){
  max[1]=0;
  
  if(p<i)k=p;else k=i;
  for(;k>=2;k--)
  for(j=0;j<n;j++){
   dp[j][k]=dp[(j+n-1)%n][k-1]+dat[(j+n-1)%n][i];
   if(max[1]<dp[j][k])
   max[1]=dp[j][k];
  }
  
  for(j=0;j<n;j++){
   dp[j][1]=max[0]-cost[(j+n-1)%n]+dat[(j+n-1)%n][i];
   if(max[1]<dp[j][1])
   max[1]=dp[j][1];
  }
  
  max[0]=max[1];
 }
 
 printf("%d\n",max[1]);
 return 0;
}                                 