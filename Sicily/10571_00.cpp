// Problem#: 10571
// Submission#: 2809775
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
bool t[51][51];int d[8][2]={-1,0,-1,1,0,1,1,1,1,0,1,-1,0,-1,-1,-1},r,s;bool v(int a,int b){if(a<0||b<0||a>=r||b>=s||!t[a][b])return 0;return 1;}int m(int a,int b){int c=0,i;for(i=0;i<8;i++)if(v(a+d[i][0],b+d[i][1]))c++;return c;}int main(){int i,j,k,q,p,x=-1,c=0;scanf("%d%d\n",&r,&s);char e[51];for(i=0;i<r;i++){gets(e);for(j=0;j<s;j++)if(e[j]=='.')t[i][j]=0;else t[i][j]=1;}for(i=0;i<r;i++)for(j=0;j<s;j++)if(t[i][j]==0&&x<8&&m(i,j)>x){x=m(i,j);q=i;p=j;}if(x+1)t[q][p]=1;for(i=0;i<r;i++)for(j=0;j<s;j++)if(t[i][j]){for(k=0;k<8;k++)if(v(i+d[k][0],j+d[k][1]))c++;t[i][j]=0;}printf("%d\n",c);return 0;}                                 