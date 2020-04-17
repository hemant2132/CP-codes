// https://codeforces.com/problemset/problem/383/E

const int N=1,LN=24;

vector<int> F(1<<LN,0);
vector<int> val(LN+1);

void compute()
{
    val[0]=1;
    for(int i=1;i<=LN;++i)
        val[i]=val[i-1]*2ll;
}

void solve()
{
    int n;
    cin>>n;

    vector<int> v(n,0);
    string s;
    for(int i=0;i<n;++i)
    {
        cin>>s;

        for(int j=0;j<3;++j)
            v[i]|=val[s[j]-'a'];
    }

    for(int i=0;i<n;++i)
        ++F[v[i]];

    for(int j=0;j<LN;++j)
    {
        for(int i=0;i<val[LN];++i)
        {
            if(i&val[j])
                F[i]+=F[i^val[j]];
        }
    }

    int ans=0,tmp;
    for(int i=1;i<val[LN];++i)
    {
        tmp=n-F[(val[LN]-1)^i];
        ans^=(tmp*tmp);
    }

    cout<<ans;
}
