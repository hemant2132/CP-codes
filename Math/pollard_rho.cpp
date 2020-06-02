/*
    -> Pollard's Rho Algorithm for fast integer factorization
    -> works in O(n^(1/4))
    -> ref: 1. https://cp-algorithms.com/algebra/factorization.html
            2. http://morris821028.github.io/2015/07/11/uva-11476/ (for implementation)
    -> tested on SPOJ/FACT0 (15 digits)
*/

int pollard_rho(int n, int c)
{
    int x=2,y=2,i=1,k=2,d;
    while(1)
    {
        x=(mulmod(x,x,n)+c);
        if(x>=n)
            x-=n;

        d=__gcd(x-y,n);
        if(d>1)
            return d;

        if(++i==k)
            y=x,k<<=1;
    }

    return n;
}

void trial_division(int n,vi &factors)
{
    for(int i=2;i*i<=n;++i)
    {
        while(n%i==0)
        {
            factors.pb(i);
            n/=i;
        }
    }

    if(n>1)
        factors.pb(n);
}

void factorize(int n,vi &factors)
{
    if(n==1)
        return;

    if(n<inf)
    {
        trial_division(n,factors);
        return;
    }

    if(MillerRabin(n))
    {
        factors.pb(n);
        return;
    }

    int d=n;
    for(int i=2;d==n;++i)
        d=pollard_rho(n, i);

    factorize(d,factors);
    factorize(n/d,factors);
}
