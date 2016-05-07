// Problem#: 1691
// Submission#: 2308226
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
int main() {
    int n, n1, n2, i, sum=0, max=-1;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &n1, &n2);
        for(;n2>=n1; n2--) {
            for(i=1;i<=n2;i++){
                if(n2%i==0)
                    sum=sum+i;}
            if((sum>2*n2)&&((sum-2*n2)>max))
                max=sum-2*n2;
            sum=0;}
        printf("%d\n", max);
        max=-1;}
    return 0;
}                                 