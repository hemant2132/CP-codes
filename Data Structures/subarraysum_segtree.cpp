/*
    supports:
    1. finding max. subarray sum for a given range [l,r]
    2. updating a particular index
*/

struct seg
{
    int pre,suf,tot,sub;
    seg()
    {
        pre=suf=tot=sub=-inf;
    }
};

seg null;
vector<seg> tree;

seg mrg(seg x,seg y)
{
    if(x.tot==-inf)
        return y;
    if(y.tot==-inf)
        return x;

    seg z;
    z.pre=max(x.pre,x.tot+y.pre);
    z.suf=max(y.suf,y.tot+x.suf);
    z.tot=x.tot+y.tot;
    z.sub=max({x.sub,y.sub,x.suf+y.pre});

    return z;
}

void build(int node,int beg,int en)
{
    if(beg==en)
    {
        //tree[node].pre=tree[node].suf=tree[node].tot=tree[node].sub=v[beg];
        return;
    }

    int mid=(beg+en)/2;
    build(2*node,beg,mid);
    build(2*node+1,mid+1,en);
    tree[node]=mrg(tree[2*node],tree[2*node+1]);
}

void update(int node,int beg,int en,int id,int val)
{
    if(beg==en)
    {
        tree[node].pre=tree[node].suf=tree[node].tot=tree[node].sub=val;
        return;
    }

    int mid=(beg+en)/2;
    if(beg<=id && id<=mid)
        update(2*node,beg,mid,id,val);
    else
        update(2*node+1,mid+1,en,id,val);

    tree[node]=mrg(tree[2*node],tree[2*node+1]);
}

seg query(int node,int beg,int en,int l,int r)
{
    if(r<beg || en<l)
        return null;

    if(l<=beg && en<=r)
        return tree[node];

    int mid=(beg+en)/2;
    seg q1=query(2*node,beg,mid,l,r);
    seg q2=query(2*node+1,mid+1,en,l,r);
    seg res=mrg(q1,q2);

    return res;
}
