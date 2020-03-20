set<int> v[N];
vector<int> sub(N);

int nodes;

void dfs_size(int x,int p)
{
    sub[x]=1;
    ++nodes;
    for(auto c:v[x])
    {
        if(c!=p)
        {
            dfs_size(c,x);
            sub[x]+=sub[c];
        }
    }
}

int dfs_centroid(int x,int p)
{
    for(auto c:v[x])
    {
        if(c!=p && sub[c]>nodes/2)
            return dfs_centroid(c,x);
    }

    return x;
}

void decompose(int x,int p)
{
    nodes=0;
    dfs_size(x,-1);
    int centroid=dfs_centroid(x,-1);

//    cout<<"centroid "<<centroid<<"\n";

    par[centroid]=p;

    for(auto c:v[centroid])
    {
        v[c].erase(centroid);
        decompose(c,centroid);
    }

    v[centroid].clear();
}
