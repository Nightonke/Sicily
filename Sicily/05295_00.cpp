// Problem#: 5295
// Submission#: 2815719
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
char t[1005];int i,j,k,p;int main(){gets(t);for(;t[i];i++)if(t[i]=='?'){for(k=i-1;k>2;k--)if(t[k-3]=='W'&&t[k-2]=='h'&&t[k-1]=='a'&&t[k]=='t'){p=k+1;break;}printf("Forty-two");for(j=p;j<i;j++)printf("%c",t[j]);printf(".\n");}return 0;}                                 