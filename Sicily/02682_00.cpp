// Problem#: 2682
// Submission#: 3556152
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<cstdio>
int main(){while(1){int N,a,b,t;scanf("%d",&N);if(!N--)break;scanf("%d",&a);while(N--){scanf("%d",&b);while(b){t=a%b;a=b;b=t;}}scanf("%d",&b);printf("%s\n",b%a?"NO":"YES");}return 0;}                                 