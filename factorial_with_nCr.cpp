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


int modinv(int x)
{
	return pow(x,M-2,M);
}

void compute_fact()
{
	fact[0]=1;
	for(int i=2;i<N;++i)
        fact[i]=(fact[i-1]*i)%M;

	invfact[N-1]=modinv(fact[N-1]);
	for(int i=N-2;i>=0;--i)
        invfact[i]=(invfact[i+1]*(i+1))%M;
}

int nCr(int n,int r)
{
	if(n<r)
		return 0;

	int res=(fact[n]*fact[r])%M;
	res=(res*fact[n-r])%M;

	return res;
}
