// Problem#: 1022
// Submission#: 3187203
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<queue>
#include<vector>
#include<map>
using namespace std;char m[100001][11];int main(){int c;scanf("%d",&c);bool f=1;char t[30];while(c--){priority_queue<int,vector<int>,greater<int> >b;priority_queue<int,vector<int>,less<int> >s;if(!f)printf("\n");f=0;while(1){gets(t);if(t[0]==65){char e[15];int u=0,i;for(i=4;t[i]!=' ';i++){e[i-4]=t[i];}e[i-4]='\0';for(i++;t[i]!='\0';i++){u=u*10+t[i]-'0';}for(i=0;e[i]!='\0';i++){m[u][i]=e[i];}m[u][i]='\0';if((b.size()+s.size())%2){if(u>s.top()){b.push(u);}else{b.push(s.top());s.pop();s.push(u);}}else{if(b.size()&&u>b.top()){s.push(b.top());b.pop();b.push(u);}else{s.push(u);}}}else if(t[0]==81){if((b.size()+s.size())%2){printf("%s\n",m[s.top()]);}else{printf("No one!\n");}}else if(t[0]==69){if((b.size()+s.size())%2)printf("%s is so poor.\n",m[s.top()]);else printf("Happy BG meeting!!\n");break;}}}return 0;}                                 