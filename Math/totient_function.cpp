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

vector<int> phi(N);

void totient_all()
{
    for(int i=1;i<N;++i)
        phi[i]=i;

    for(int i=2;i<N;++i)
    {
        if(phi[i]==i)
        {
            for(int j=i;j<N;j+=i)
            {
                phi[j]/=i;
                phi[j]*=(i-1);
            }
        }
    }
}
