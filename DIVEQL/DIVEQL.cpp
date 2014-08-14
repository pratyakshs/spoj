#include<bits/stdc++.h>
#define __mod__ 1000000007
using namespace std;
typedef unsigned long long bignum;

struct pair{
    bignum x,y;
    pair(bignum a, bignum b){
        x=a, y=b;
    }
};

bignum mulmod(bignum a,bignum b,bignum c){
    bignum x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b >>= 1;
        //prbignumf("%llu))\n", b);
    }
    return x%c;
}

::pair bezout(bignum a, bignum m){
    //returns the solution (x,y) of ax+my=1
    if(m==0)
        return ::pair(1, 0);
    ::pair p=bezout(m, a%m);
    return ::pair(p.y, (p.x-(p.y*(a/m))));
}

bignum modInv(bignum a, bignum m){
    //modular mulltiplicative inverse of a (mod m)
    ::pair p=bezout(a,m);
    if(p.x<0)
        return p.x+m;
    return p.x;
}




bignum pow(bignum base, bignum exponent, bignum modulo)
{//implement for the case when base is an nxn matrix. Targeted running time: O(n^3 log(exponent)).
    bignum ans=1;
    while(exponent>0)
    {
        //printf("%llu)\n", exponent);
        if(exponent%2==1)
            ans=mulmod(ans, base, modulo);
        exponent>>=1;
        base=mulmod(base, base, modulo);
    }
    return ans;
}

bignum modInverse(bignum a, bignum m) {
    return pow(a,m-2,m);
}

bignum binomial(bignum n, bignum k, bignum m){
    if(k> n/2)
        return binomial(n, n-k, m);
    bignum num=1, nterm=n;
    for(bignum i=0; i<k; i++){
        num=mulmod(num, nterm, m);
        nterm--;
    }
    bignum den=1;
    for(bignum i=2; i<=k; i++){
        den=mulmod(den, i, m);
    }
    return mulmod(num, modInverse(den, m), m);
}


bignum modexp(bignum base, bignum exponent, bignum modulo)
{
    bignum ans=1;
    while(exponent>0)
    {
        //printf("%llu)\n", exponent);
        if(exponent%2==1)
            ans=((ans*base)%modulo);
        exponent>>=1;
        base=((base*base)%modulo);
    }
    return ans;
}


int main(){
    int t;
    scanf("%i", &t);
    while(t--){
        bignum n, p;
        scanf("%llu %llu", &n, &p);
        bignum den = (modexp(p, n-1, __mod__)*(p-1)) % __mod__;
        bignum num = (modexp(p, n, __mod__) + (__mod__ - 1)) % __mod__;
        bignum factor = (num*modInverse(den, __mod__)) % __mod__;
        bignum g = __gcd(num, den);
        bignum x = den/g, z = num/g;
        printf("%llu %llu\n", z, x);
    }
    return 0;
}
