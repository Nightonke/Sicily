// Problem#: 1742
// Submission#: 3256111
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main()
{
 long long d[33][33],s;
 int i,j;
 for(i=1;i<31;i++)
 d[i][1]=i;
 
 for(i=2;i<31;i++){
  for(j=2;j<=i;j++){
   d[i][j]=d[i][j-1]+d[i-1][j];
  }
  d[i][i]=d[i][i-1];
 }
 
 while(scanf("%d",&i)!=EOF){
  s=0;
  for(j=1;j<=i;j++)s+=d[i][j];
  printf("%lld\n",s);
 } 
 return 0;
}                                 