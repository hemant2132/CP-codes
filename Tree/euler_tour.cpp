vector<int> eul,st(N),en(N);

void dfs(int x,int p)
{
    eul.pb(x);
    st[x]=eul.size();

    for(auto c:v[x])
    {
        if(c!=p)
            dfs(c,x);
    }

    en[x]=eul.size();
}
