// Problem#: 4839
// Submission#: 2813889
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
int a[10001][4];int main(){int n,p,q,i,j,x,y;char t[40];scanf("%d\n",&n);for(i=0;i<n;i++){j=q=p=0;gets(t);while(t[j]-' ')a[i][0]=a[i][0]*10+t[j++]-'0';j++;while(t[j]-' ')a[i][1]=a[i][1]*10+t[j++]-'0';j++;while(t[j]-' ')p=p*10+t[j++]-'0';j++;while(t[j]-'\0')q=q*10+t[j++]-'0';a[i][2]=a[i][0]+p;a[i][3]=a[i][1]+q;}scanf("%d%d",&x,&y);for(i=n-1;i>=0;i--)if(a[i][0]<=x&&x<=a[i][2]&&a[i][1]<=y&&y<=a[i][3]){printf("%d\n",i+1);return 0;}printf("-1\n");return 0;}                                 