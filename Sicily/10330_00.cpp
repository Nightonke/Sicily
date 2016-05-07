// Problem#: 10330
// Submission#: 2763748
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
int g(int a,int b){if(b==0)return a;else return g(b,a%b);}int main(){int n,m;scanf("%d%d",&n,&m);printf("%d\n",m-g(n,m));return 0;}                                 