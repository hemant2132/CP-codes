vector<int> lev(N,0),par(N,0);
int anc[N][20];

void dfs_init(int x,int p)
{
    if(p!=-1)
        lev[x]=lev[p]+1;

    par[x]=p;

    for(auto c:v[x])
    {
        if(c!=p)
        {
            dfs_init(c,x);
        }
    }
}

void compute(int n)
{
    for(int i=1;i<=n;++i)
        anc[i][0]=par[i];

    for(int j=1;(1<<j)<=n;++j)
    {
        for(int i=1;i<=n;++i)
        {
            if(anc[i][j-1]!=-1)
                anc[i][j]=anc[anc[i][j-1]][j-1];
        }
    }
}

int lca(int a,int b)
{
    if(lev[a]<lev[b])
        swap(a,b);

    int lg;
    for(lg=1;(1<<lg)<=lev[a];++lg);
    --lg;

    for(int i=lg;i>=0;--i)
    {
        if(lev[a]-(1<<i)>=lev[b])
            a=anc[a][i];
    }

    if(a==b)
        return a;

    for(int i=lg;i>=0;--i)
    {
        if(anc[a][i]!=-1 && anc[a][i]!=anc[b][i])
            a=anc[a][i],b=anc[b][i];
    }

    return anc[a][0];
}

int getanc(int x,int k)     // returns kth ancestor of 'x'
{
    for(int i=0;k;++i,k/=2)
    {
        if(k%2)
            x=anc[x][i];
    }

    return x;
}

int func(int a,int b)       // returns value on the path "a to b" where b is an ancestor of a
{
    int lg;
    for(lg=1;(1<<lg)<=lev[a];++lg);
    --lg;

    int res=0;
    for(int i=lg;i>=0;--i)
    {
        if(lev[a]-(1<<i)>=lev[b])
        {
            //res=max(res,mx[a][i]);
            a=anc[a][i];
        }
    }

    return res;
}
