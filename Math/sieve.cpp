vector<int> v(N,1),primes;

void sieve()
{
    v[0]=v[1]=0;
    for(int i=2;i*i<N;++i)
    {
        if(v[i])
        {
            for(int j=i*i;j<N;j+=i)
                v[j]=0;
        }
    }

    for(int i=2;i<N;++i)
    {
        if(v[i])
            primes.pb(i);
    }
}
