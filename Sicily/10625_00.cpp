// Problem#: 10625
// Submission#: 2808636
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){int l[26],n,i,s=0;char t[35];scanf("%d\n",&n);for(i=0;i<26;l[i++]=0);while(n--)gets(t),l[t[0]-97]++;for(i=0;i<26;i++)if(l[i]>4)s=1,printf("%c",i+97);if (!s)printf("PREDAJA");printf("\n");return 0;}                                 