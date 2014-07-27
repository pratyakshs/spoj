#include<bits/stdc++.h>
using namespace std;

typedef unsigned long long bignum;

int main(){
    int t;
    scanf("%i", &t);
    while(t--){
        bignum n, m;
        scanf("%llu %llu", &n, &m);
        map<bignum, bignum> n_pf, m_pf;
        // prime factorizations of n and m

        bignum np2=0, mp2=0;
        while(n%2==0){
            n>>=1;
            np2++;
        }
        while(m%2==0){
            m>>=1;
            mp2++;
        }
        n_pf[2]=np2;
        m_pf[2]=mp2;


        for(int i=3; i*i<=n; i+=2) {
            while(n%i==0){
                n/=i;
                n_pf[i]++;
            }
        }
        if(n>1)
            n_pf[n]++;

        for(int i=3; i*i<=m; i+=2) {
            while(m%i==0){
                m/=i;
                m_pf[i]++;
            }
        }
        if(m>1)
            m_pf[m]++;

        map<bignum, bignum> ans_pf;

        for(map<bignum, bignum>::iterator it=n_pf.begin(); it!=n_pf.end(); it++)
            if(it->second>m_pf[it->first])
                ans_pf[it->first]=it->second;
        for(map<bignum, bignum>::iterator it=m_pf.begin(); it!=m_pf.end(); it++)
            if(it->second>n_pf[it->first])
                ans_pf[it->first]=it->second;

        bignum ans=1;
        for(map<bignum, bignum>::iterator it=ans_pf.begin(); it!=ans_pf.end(); it++)
            ans*=pow(it->first, it->second);
       printf("%llu\n", ans);
    }
    return 0;
}
