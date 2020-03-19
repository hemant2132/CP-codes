vector<int> v[N],disc(N),low(N),vis(N);
vector<int> adj[N],comp(N);                 // adj -> bridge tree

stack<pii> stk;

int n,m;
int tim=1,ind=1;
pii pr;

void dfs(int x,int p)
{
    vis[x]=1;
    disc[x]=low[x]=tim++;

    stk.push({x,x});

    for(auto c:v[x])
    {
        if(c==p)
            continue;

        if(!vis[c])
        {
            stk.push({x,c});

            dfs(c,x);

            low[x]=min(low[x],low[c]);

            if(low[c]>disc[x])
            {
                while(stk.top().F!=x)
                {
                    pr=stk.top();
                    comp[pr.F]=comp[pr.S]=ind;
                    stk.pop();
                }

                stk.pop();

                ++ind;
            }
        }
        else
        {
            if(disc[x]>disc[c])
            {
                stk.push({c,x});
                low[x]=min(low[x],disc[c]);
            }
        }
    }
}

void solve()
{
    cin>>n>>m;

    int a,b;
    for(int i=0;i<m;++i)
    {
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }

    dfs(1,-1);

    while(!stk.empty())
    {
        pr=stk.top();
        comp[pr.F]=comp[pr.S]=ind;
        stk.pop();
    }

//    for(int i=1;i<=n;++i)
//        cout<<comp[i]<<" ";
//    cout<<"\n";

    for(int i=1;i<=n;++i)
    {
        for(auto c:v[i])
        {
            if(comp[i]!=comp[c])
                adj[comp[i]].pb(comp[c]);
        }
    }

//    for(int i=1;i<=n;++i)
//    {
//        cout<<i<<": ";
//        for(auto c:adj[i])
//            cout<<c<<" ";
//        cout<<"\n";
//    }
}



