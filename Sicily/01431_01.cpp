// Problem#: 1431
// Submission#: 3238440
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <queue>
using namespace std;
 
//sort记录s[i]的大小，
//sort[i]>sort[j]=>s[i]>s[j],
//sort[i]-sort[0]=s[i]-s[0]=s[i],
//a[i]=sort[i]-sort[i-1]。
int sort[1000001];
 
int main(){

 int t,n,p,q,m,i,j;
 queue<int> mq;
 scanf("%d",&t);

 while(t--){
  scanf("%d %d %d",&n,&p,&q);
  
  if(p+q<n+2){
   printf("Impossible\n");
   continue;
  }
  
  m=n;
  for(i=n-p+1;i<=q-1;i++)
   mq.push(i);
  
  while(!mq.empty()){ //拓扑排序
   i=mq.front();
   mq.pop();
   sort[i]=m--;
   if(i-p>=0)
    mq.push(i-p);
   
   else if(i+q<=n)
    mq.push(i+q);
   
  }
  
  if(m==-1){
   for(i=1;i<=n-1;i++)
   printf("%d ",sort[i]-sort[i-1]);
   printf("%d\n",sort[n]-sort[n-1]);
  }
  else
   printf("Impossible\n");
  
 }
 
 return 0;
}                                 