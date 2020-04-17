int pw(int x,int n)
{
    int res=1;

    //x%=M;
    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x);//%M;

        x=(x*x);//%M;
    }

    return res;
}

vector<int> primes={2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

vector<int> get(int n)
{
    vector<int> res;
    for(auto& c:primes)
    {
        int tmp=n;
        int cnt=0;

        while(tmp)
        {
            tmp/=c;
            cnt+=tmp;
        }

        res.pb(cnt);
    }

    return res;
}


int ncr(int n,int r)
{
    vector<int> tot=get(n);
    vector<int> a=get(r),b=get(n-r);

    int sz=tot.size(),ans=1;
    for(int i=0;i<sz;++i)
    {
        ans*=pw(primes[i],(tot[i]-(a[i]+b[i])));
    }

    return ans;
}
