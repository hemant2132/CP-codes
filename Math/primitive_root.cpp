/*
    -> "g" is a primitive root modulo n if and only if for any integer a such that gcd(a,n)=1,
       there exists an integer k such that: g^k = a (mod n).
    -> ref: https://cp-algorithms.com/algebra/primitive-root.html
*/


#include<bits/stdc++.h>
using namespace std;

int pw(int x,int n,int mod=M)
{
    int res=1;

    x%=mod;
    if(x<0)
        x+=mod;

    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x)%mod;

        x=(x*x)%mod;
    }

    return res;
}

int generator(int p)
{
    vi fact;

    int phi=p-1,n=phi;                          // factorizing phi(n) (for a prime "n", phi(n)=n-1)
    for(int i=2;i*i<=n;++i)
    {
        if(n%i==0)
        {
            fact.pb(i);
            while(n%i==0)
                n/=i;
        }
    }
    if(n>1)
        fact.pb(n);

    int len=sz(fact);
    for(int res=2;res<=p;++res)                 // checking for primitive root
    {
        bool ok=1;
        for(int i=0;i<len && ok;++i)
            ok&=(pw(res, phi/fact[i], p)!=1);

        if(ok)
            return res;
    }

    return -1;
}

int main()
{
    int x=generator(11);
    cout<<x;

    return 0;
}
