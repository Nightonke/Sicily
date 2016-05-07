// Problem#: 13291
// Submission#: 3523793
// The source code is licensed under Creative Commons Attribution-NonCommercial-ShareAlike 3.0 Unported License
// URI: http://creativecommons.org/licenses/by-nc-sa/3.0/
// All Copyright reserved by Informatic Lab of Sun Yat-sen University
#include <stdio.h>
#include <math.h>

int prime[10000];
bool isPrime[100005];

void getPrime( int x ){
    for ( int i=1; i<x; i+=2 )
        isPrime[i] = 1, isPrime[i-1] = 0;
    prime[prime[0]=1 ] = 2;
    for ( int i=3; ; i+=2 ) if(isPrime[i]) {
        int j = i*i, k = i+i;
        if(j >= x) break;
        while(j < x ) {
            isPrime[j] = 0;  j += k;
        }
    }
    for ( int i=3; i<x; i += 2 )
        if(isPrime[i]) prime[++prime[0] ] = i;
}

int p[10000], cnt[10000];

inline void getPrimeDivisor(int x) {
    p[0] = cnt[0] = 0; int t;
    for ( int i=1; prime[i] * prime[i] <= x && i<=prime[0]; ++i ) {
        t = 0;
        while( x%prime[i] == 0 ) {
            ++t; x /= prime[i];
        }
        if( t ) p[++p[0] ] = prime[i], cnt[++cnt[0] ] = t;
    }
    if(x > 1) p[++p[0] ] = x, cnt[++cnt[0] ] = 1;
}

int divisor[100005];

inline void getDivisor( int x ) {
    getPrimeDivisor(x);
    divisor[0] = 1;
    divisor[1] = 1;
    for ( int i=1; i<=p[0]; ++i ) {
        int nowNum = divisor[0];
        int base = 1;
        for ( int j=1; j<=cnt[i]; ++j )
        {
            base *= p[i];
            for ( int k=1; k<=divisor[0]; ++k )
            divisor[++nowNum ] = divisor[k]*base;
        }
        divisor[0] = nowNum;
    }
}

int num[100005];
int multiple[100005];
long long partOfSum[100005];

inline void update(int m) {
    if (isPrime[m]) {
        multiple[1] = m;
        multiple[m] = m;
        return;
    }
    getDivisor(m);
    for (int i = 1; i <= divisor[0]; i++) multiple[divisor[i]] = m;
}

void input() {  // quickly input
    char text[800000];
    gets(text);
    int i = 1;
    int sum = 0;
    for (int j = 0; text[j] != '\0'; j++) {
        if (text[j] == ' ') {
            num[i++] = sum;
            sum = 0;
        } else {
            sum = sum * 10 + text[j] - '0';
        }
    }
    num[i] = sum;
}

int main() {
    
    getPrime(100005);
    
    int N;
    scanf("%d\n", &N);
    input();
    
    for (int i = 1; i <= N; i++) multiple[num[i]] = num[i];
    for (int i = 1; i <= N; i++) {
        partOfSum[i] = multiple[num[i]];
        update(num[i]);
    }
    
    unsigned long long ans = 0;
    
    for (int i = 1; i <= N; i++) multiple[num[i]] = num[i];
    for (int i = N; i > 0; i--) {
        ans += partOfSum[i] * multiple[num[i]];
        update(num[i]);
    }
    
    printf("%llu\n", ans);

    return 0;
}                                 