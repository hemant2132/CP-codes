vector<int> v[N],disc(N),low(N);
vector<bool> vis(N,0);

vector<int> ap;                     //articulation points
vector<pair<int,int>> be;           //bridges

int tim=1;

void dfs(int x,int p)
{
    vis[x]=1;
    disc[x]=low[x]=tim++;
    int child=0;

    for(auto c:v[x])
    {
        if(c==p)
            continue;

        if(!vis[c])
        {
            ++child;

            dfs(c,x);

            low[x]=min(low[x],low[c]);

            if((p==-1 && child>1) || (p!=-1 && low[c]>=disc[x]))
                ap.pb(x);

            if(low[c]>disc[x])
                be.pb({min(c,x),max(c,x)});
        }
        else
            low[x]=min(low[x],disc[c]);
    }
}

