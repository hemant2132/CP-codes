/*
* Need to add lazy segtree,
* then range update utility function can also be added
*/

vector<pii> v[N],edges;
vector<int> par(N),lev(N),sz(N);
vector<int> base(N),head(N),id(N),pos(N);
int anc[N][15];
int tree[4*N];

int n;
int chain,tim;

//initialisation

void dfs(int x,int p)
{
    if(p!=-1)
        lev[x]=lev[p]+1;

    par[x]=p;
    sz[x]=1;

    for(auto c:v[x])
    {
        if(c.F!=p)
        {
            dfs(c.F,x);
            sz[x]+=sz[c.F];
        }
    }
}

//lca

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

//segment tree

void build(int node,int start,int en)
{
    if(start==en)
        tree[node]=base[start];
    else
    {
        int mid=(start+en)/2;
        build(2*node,start,mid);
        build(2*node+1,mid+1,en);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}

void update(int node,int start,int en,int idx,int val)
{
    if(start==en)
    {
        base[idx]=val;
        tree[node]=val;
    }
    else
    {
        int mid=(start+en)/2;
        if(start<=idx and idx<=mid)
            update(2*node,start,mid,idx,val);
        else
            update(2*node+1,mid+1,en,idx,val);

        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
}

int query(int node,int start,int en,int l,int r)
{
    if(r<start or en<l)
        return 0;

    if(l<=start and en<=r)
        return tree[node];

    int mid=(start+en)/2;
    int p1=query(2*node,start,mid,l,r);
    int p2=query(2*node+1,mid+1,en,l,r);

    return max(p1,p2);
}

//utility function

int query_up(int a,int b)
{
    int res=0;
    int x;

    while(1)
    {
        if(id[a]==id[b])
        {
            if(a==b)
                break;

            res=max(res,query(1,0,n-1,pos[b]+1,pos[a]));

            break;
        }

        res=max(res,query(1,0,n-1,pos[head[id[a]]],pos[a]));
        a=par[head[id[a]]];
    }

    return res;
}

//hld (decomposition function)

void hld(int x,int p,int w)
{
    if(head[chain]==-1)
        head[chain]=x;

    id[x]=chain;
    pos[x]=tim;
    base[tim++]=w;

    int mx=-1;
    pii big={-1,-1};
    for(auto c:v[x])
    {
        if(c.F==p)
            continue;

        if(mx<sz[c.F])
        {
            mx=sz[c.F];
            big=c;
        }
    }

    if(big.F!=-1)
        hld(big.F,x,big.S);

    for(auto c:v[x])
    {
        if(c.F==p || c==big)
            continue;

        ++chain;
        hld(c.F,x,c.S);
    }
}
