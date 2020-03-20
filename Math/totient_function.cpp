vector<int> p;        // p -> primes

int totient(int n)
{
    int res=n;

    for(int i=0;p[i]*p[i]<=n;++i)
    {
        if(n%p[i]==0)
        {
            while(n%p[i]==0)
                n/=p[i];

            res-=res/p[i];
        }
    }

    if(n>1)
        res-=res/n;

    return res;
}

vector<int> phi(n);

int totient_all()
{
    for(int i=0;i<n;++i)
        phi[i]=i;

    for(int i=2;i*i<n;++i)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<n;j+=i)
                phi[j]=(phi[j]/i)*(i-1);
        }
    }
}
