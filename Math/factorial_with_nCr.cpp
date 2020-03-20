vector<int> fact(N),invfact(N);

int pw(int x,int n)
{
    int res=1;

    x%=M;
    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x)%M;

        x=(x*x)%M;
    }

    return res;
}

void compute_fact()
{
	fact[0]=1;
	for(int i=1;i<N;++i)
        fact[i]=(fact[i-1]*i)%M;

	invfact[N-1]=pw(fact[N-1],M-2);
	for(int i=N-2;i>=0;--i)
        invfact[i]=(invfact[i+1]*(i+1))%M;
}

int nCr(int n,int r)
{
	if(n<r)
		return 0;

	int res=(fact[n]*invfact[r])%M;
	res=(res*invfact[n-r])%M;

	return res;
}
