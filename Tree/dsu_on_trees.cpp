vector<int> v[N],vec[N],sz(N,1),cnt(N,0),val;

int dfs_size(int x,int p)
{
    for(auto c:v[x])
    {
        if(c!=p)
        {
            dfs_size(c,x);
            sz[x]+=sz[c];
        }
    }
}

void dfs(int x,int p,bool keep)
{
    int mx=-1,big=-1;
    for(auto c:v[x])
    {
        if(c==p)
            continue;

        if(sz[c]>mx)
        {
            mx=sz[c];
            big=c;
        }
    }

    for(auto c:v[x])
    {
        if(c!=p && c!=big)
            dfs(c,x,0);
    }

    if(big!=-1)
    {
        dfs(big,x,1);
        swap(vec[x],vec[big]);
    }

    vec[x].pb(x);
    ++cnt[val[x]];

    for(auto c:v[x])
    {
        if(c==p || c==big)
            continue;

        for(auto u:vec[c])
        {
            ++cnt[val[u]];
            vec[x].pb(u);
        }
    }

    // at this moment, cnt[] has the value distribution for subtree of 'v'

    if(!keep)
    {
        for(auto c:vec[x])
            --cnt[val[c]];
    }
}
