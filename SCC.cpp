
int cnt,fl;

vector<int> v[N],w[N],vis(N,0);
stack<int> stk;

vector<int> component;

void dfs(int x)
{
    if(vis[x])
        return;

    vis[x]=1;

    if(!fl)
    {
        for(auto u:v[x])
            dfs(u);

        stk.push(x);
    }
    else
    {
        component.pb(x);

        for(auto u:w[x])
            dfs(u);
    }
}

void trans()
{
    for(int x=1;x<N;++x)
    {
        for(auto u:v[x])
            w[u].pb(x);
    }
}

void findSCC()
{
    fl=0;
    for(int i=1;i<=n;++i)
    {
        if(!vis[i])
            dfs(i);
    }

    trans();

    fill(all(vis),0);

    int x;
    fl=1;
    while(!stk.empty())
    {
        x=stk.top();
        stk.pop();

        if(vis[x])
            continue;

        component.clear();
        dfs(x);

        // vertices in current SCC stored in component[]
    }
}
