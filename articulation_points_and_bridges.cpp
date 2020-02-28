int tim=0;

vector<int> v[N],disc(N),low(N,inf),par(N,-1),ap;
vector<bool> vis(N,0);
vector<pair<int,int>> be;

void dfs(int x)
{
    vis[x]=1;
    disc[x]=low[x]=++tim;
    int child=0;

    for(auto u:v[x])
    {
        if(!vis[u])
        {
            ++child;
            par[u]=x;

            dfs(u);

            low[x]=min(low[x],low[u]);

            if(par[x]==-1 && child>1)
                ap.pb(x);
            if(par[x]!=-1 && low[u]>=disc[x])
                ap.pb(x);

            if(low[u]>disc[x])
                be.pb({min(u,x),max(u,x)});

        }
        else if(par[x]!=u)
            low[x]=min(low[x],disc[u]);
    }
}

