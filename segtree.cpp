/*need to add lazy propagation*/

int tree[4*N];

void build(int node,int start,int en)
{
    if(start==en)
    {
        tree[node]=base[start];
        return;
    }

    int mid=(start+en)/2;
    build(2*node,start,mid);
    build(2*node+1,mid+1,en);
    tree[node]=tree[2*node]+tree[2*node+1];
}

void update(int node,int start,int en,int idx,int val)
{
    if(start==en)
    {
        base[idx]=val;
        tree[node]=val;
        return;
    }

    int mid=(start+en)/2;
    if(start<=idx and idx<=mid)
        update(2*node,start,mid,idx,val);
    else
        update(2*node+1,mid+1,en,idx,val);

    tree[node]=tree[2*node]+tree[2*node+1];
}

int query(int node,int start,int en,int l,int r)
{
    if(r<start || en<l)
        return 0;

    if(l<=start && en<=r)
        return tree[node];

    int mid=(start+en)/2;
    int q1=query(2*node,start,mid,l,r);
    int q2=query(2*node+1,mid+1,en,l,r);

    return (q1+q2);
}
