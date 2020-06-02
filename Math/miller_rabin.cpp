/*
    -> Miller-Rabin Primality Test
    -> ref: https://cp-algorithms.com/algebra/primality_tests.html
    -> for testing: 999999999999999989 5915587277 1500450271 3267000013 5754853343 4093082899 9576890767
*/

// multiplying two large nos.
int mulmod(int a,int b,int mod)
{
    int res=0;

    a%=mod;
    for(;b;b/=2)
    {
        if(b%2)
            res=(res+a)%mod;

        a=(a+a)%mod;
    }

    return res;
}

int pw(int x,int n,int mod)
{
    int res=1;

    x%=mod;
    for(;n;n/=2)
    {
        if(n%2)
            res=mulmod(res,x,mod);

        x=mulmod(x,x,mod);
    }

    return res;
}

bool check_composite(int n,int a,int d,int s)
{
    int x=pw(a,d,n);
    if(x==1 || x==n-1)
        return 0;

    for(int r=1;r<s;++r)
    {
        x=mulmod(x,x,n);
        if(x==n-1)
            return 0;
    }

    return 1;
}

// for randomized, generate nos. in [2,n-2]
bool MillerRabin(int n)
{
    if(n<2)
        return 0;

    int r=0;
    int d=n-1;
    while((d&1)==0)
    {
        d>>=1;
        r++;
    }

    vi bases={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};      // {2, 3, 5, 7} for 32-bit
    for(int a:bases)
    {
        if(n==a)            // since, "a" is prime
            return 1;
        if(check_composite(n,a,d,r))
            return 0;
    }

    return 1;
}
