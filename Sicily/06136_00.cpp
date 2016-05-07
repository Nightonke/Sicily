// Problem#: 6136
// Submission#: 2811359
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
char t[5][501];int m[5],h,w,i,c;void j(int l){c=0;for(int i=1;i<=4;i++)if(t[i][l]=='*')c++;m[c]++;}int main(){scanf("%d%d\n",&h,&w);while(h--){for(i=0;i<5;i++)gets(t[i]);for(i=0;i<w;i++)j(i*5+1);}for(i=0;i<5;i++){if(i)printf(" ");printf("%d",m[i]);}printf("\n");return 0;}                                 