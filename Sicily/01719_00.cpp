// Problem#: 1719
// Submission#: 3585226
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include<stdio.h>
#include<math.h>
double p=acos(-1),q,w,e,r,s,x,y,i,j,n;double v(){if(q<=e)return p*q*w;if(w>=r)return p*e*r;x=sqrt((w*w-r*r)*q*q*e*e/(w*w*e*e-r*r*q*q));y=sqrt((q*q-e*e)*w*w*r*r/(q*q*r*r-w*w*e*e));i=asin(y/w);j=asin(y/r);s=q*w*((p-2*i)+sin(2*i))+e*r*(2*j+sin(2*j))-4*x*y;return s;}int main(){scanf("%lf",&n);while(n--){scanf("%lf%lf%lf%lf",&q,&w,&e,&r);printf("%.3lf\n",v());}return 0;}                                 