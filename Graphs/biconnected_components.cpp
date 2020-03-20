vector<int> v[N],disc(N),low(N),par(N,-1);
vector<bool> vis(N,0);
stack<pii> stk;
set<int> st;

int tim=1;

void dfs(int x)
{
    vis[x]=1;
    disc[x]=low[x]=tim++;
    int child=0;
    pii p;

    for(auto u:v[x])
    {
        if(!vis[u])
        {
            ++child;
            par[u]=x;
            p={min(x,u),max(x,u)};
            stk.push(p);

            dfs(u);

            low[x]=min(low[x],low[u]);

            if((par[x]==-1 && child>1)  || (par[x]!=-1 && low[u]>=disc[x]))
            {
                while(stk.top()!=p)
                {
                    st.ins(stk.top().F);
                    st.ins(stk.top().S);
                    stk.pop();
                }

                st.ins(stk.top().F);
                st.ins(stk.top().S);
                stk.pop();

                // st -> vertices of the biconnected component

                st.clear();
            }
        }
        else if(par[x]!=u && disc[u]<low[x])
        {
            low[x]=disc[u];
            p={min(x,u),max(x,u)};
            stk.push(p);
        }
    }
}
