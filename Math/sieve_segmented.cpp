bool comp[N];
vector<int> primes;

void sieve_segmented()
{
	int n=N;
    const int S=5e4;

	primes.clear();
    vector<int> Ps;
    int nsqrt=sqrt(n);
    vector<bool> is_prime(nsqrt+1,1);

    for(int i=2;i<=nsqrt;++i)
    {
        if(is_prime[i])
        {
            Ps.pb(i);
            for(int j=i*i;j<=nsqrt;j+=i)
                is_prime[j]=0;
        }
    }

    int result=0;
    vector<bool> block(S);
    for(int k=0;k*S<=n;++k)
    {
        fill(all(block),1);

        int start=k*S;
        for(int p:Ps)
        {
            int start_idx=(start+p-1)/p;
            int j=max(start_idx,p)*p-start;
            for(;j<S;j+=p)
                block[j]=0;
        }

        if(k==0)
            block[0]=block[1]=0;
        for(int i=0;i<S && start+i<=n;++i)
        {
            if(block[i])
                primes.pb(start+i);
        }
    }
}
