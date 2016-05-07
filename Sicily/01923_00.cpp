// Problem#: 1923
// Submission#: 3279535
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <string.h>
int main()
{
    int n,m,t,i,j,s[34];
    scanf("%d",&n);
    while(n--){
        memset(s,0,sizeof(s));
        scanf("%d",&m);
  for(i=0;i<m;i++){
   scanf("%d",&t);
   j=0;
         while(t!=0){    //化为二进制并将各位加到适当位置去
             s[j]+=t%2;
             t/=2;
             j++;
         } 
  }
   t=m;
  for(i=2;i<=m+1;i++)    //判断不同的i（即k）是否会导致Bob必胜
  for(j=0;j<34;j++){
   if(s[j]%i!=0){
    t--;
    break;
   }
  }
        printf("%d\n",t);
    }
    return 0;
}                                 