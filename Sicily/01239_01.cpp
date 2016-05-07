// Problem#: 1239
// Submission#: 2797373
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main(){
    int x,n,d,h,a[10][2],u,c,i,j,k,o,m[11],t,e;
    char p;
    scanf("%d\n",&c);
    while(c--){
        u=o=0,d=h=99999999;
        while((p=getchar())&&p!='\n')
            if(p!=' ')
                m[o++]=p-'0';
        if(o%2){
            for(i=2,j=o-2,x=m[0]?m[0]*10+m[1]:m[1]*10,n=m[o-1];i<j;i++,j--)
                x=x*10+m[i],n=n*10+m[j];
            printf("%d\n",x-n);
        }else{
            for(i=0;i<o-1;i++)
                if(h>m[i+1]-m[i]&&m[i])
                    h=m[i+1]-m[i];
            for(i=0;i<o-1;i++)
                if(m[i+1]-m[i]==h&&m[i])
                    a[u][0]=m[i],a[u++][1]=m[i+1];
            for(i=0;i<u;i++){
                n=a[i][0],x=a[i][1],t=e=o/2-1;
                for(j=0,k=o-1;t||e;j++,k--){
                    if(m[k]!=a[i][0]&&m[k]!=a[i][1]&&t)
                        n=n*10+m[k],t--;
                    if(m[j]!=a[i][1]&&m[j]!=a[i][0]&&e)
                        x=x*10+m[j],e--;
                }
                if(x-n<d)
                    d=x-n;
            }
            printf("%d\n",o==2?m[1]-m[0]:d);
        }
    }
    return 0;}                                 