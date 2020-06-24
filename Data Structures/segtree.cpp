int tree[4*N];
int lazy[4*N];

void build(int node,int beg,int en)
{
    if(beg==en)
    {
        //tree[node]=base[beg];
        return;
    }

    int mid=(beg+en)/2;
    build(2*node,beg,mid);
    build(2*node+1,mid+1,en);

    tree[node]=tree[2*node]+tree[2*node+1];
}

// for point update and range query:
void point_update(int node,int beg,int en,int idx,int val)
{
    if(beg==en)
    {
        //base[idx]=val;
        tree[node]=val;
        return;
    }

    int mid=(beg+en)/2;
    if(beg<=idx && idx<=mid)
        point_update(2*node,beg,mid,idx,val);
    else
        point_update(2*node+1,mid+1,en,idx,val);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int range_query(int node,int beg,int en,int l,int r)
{
    if(r<beg || en<l)
        return 0;

    if(l<=beg && en<=r)
        return tree[node];

    int mid=(beg+en)/2;
    int q1=range_query(2*node,beg,mid,l,r);
    int q2=range_query(2*node+1,mid+1,en,l,r);

    return (q1+q2);
}

// for range update and point query:
void range_update(int node,int beg,int en,int l,int r,int val)
{
    if(r<beg || en<l)
        return;

    if(l<=beg && en<=r)
    {
        tree[node]+=val;
        return;
    }

    int mid=(beg+en)/2;
    range_update(2*node,beg,mid,l,r,val);
    range_update(2*node+1,mid+1,en,l,r,val);
}

int point_query(int node,int beg,int en,int idx,int val=0)
{
    if(beg==en)
        return val+tree[node];

    int mid=(beg+en)/2;
    if(beg<=idx && idx<=mid)
        return point_query(2*node,beg,mid,idx,val+tree[node]);
    else
        return point_query(2*node+1,mid+1,en,idx,val+tree[node]);

}

// for lazy update and lazy query:
void lazy_update(int node,int beg,int en,int l,int r,int val)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(en-beg+1)*lazy[node];
        if(beg!=en)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(beg>en || r<beg || en<l)
        return;

    if(l<=beg && en<=r)
    {
        tree[node]+=(en-beg+1)*val;
        if(beg!=en)
        {
            lazy[2*node]+=val;
            lazy[2*node+1]+=val;
        }

        return;
    }

    int mid=(beg+en)/2;
    lazy_update(2*node,beg,mid,l,r,val);
    lazy_update(2*node+1,mid+1,en,l,r,val);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int lazy_query(int node,int beg,int en,int l,int r)
{
    if(beg>en || r<beg || en<l)
        return 0;

    if(lazy[node]!=0)
    {
        tree[node]+=(en-beg+1)*lazy[node];
        if(beg!=en)
        {
            lazy[2*node]+=lazy[node];
            lazy[2*node+1]+=lazy[node];
        }
        lazy[node]=0;
    }

    if(l<=beg && en<=r)
        return tree[node];

    int mid=(beg+en)/2;
    int q1=lazy_query(2*node,beg,mid,l,r);
    int q2=lazy_query(2*node+1,mid+1,en,l,r);

    return (q1+q2);
}
