/*
    -> Persistent Segment Tree

    -> We can access any "version" of the data structure efficiently (both in time and memory consumption).

    -> ref: 1. Anudeep's Blog: https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/
            2. https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915
            3. Gaurav Sen video: https://www.youtube.com/watch?v=TH9n_HVkjQM
            4. https://github.com/Ashishgup1/Competitive-Coding/blob/master/Persistent%20Segment%20Tree.cpp
*/

int v[N];

int cnt=0;
int root[N],st[21*N],lc[21*N],rc[21*N];

int build(int l, int r)
{
    int node=++cnt;

	if(l==r)
		return node;

	int mid=(l+r)/2;
	lc[node]=build(l,mid);
	rc[node]=build(mid+1,r);

	return node;
}

int update(int onode,int l,int r,int pos)
{
	int node=++cnt;

	if(l==r)
	{
		st[node]=st[onode]+1;
		return node;
	}

	int mid=(l+r)/2;
	lc[node]=lc[onode];
	rc[node]=rc[onode];

	if(pos<=mid)
		lc[node]=update(lc[onode],l,mid,pos);
	else
		rc[node]=update(rc[onode],mid+1,r,pos);

	st[node]=st[lc[node]]+st[rc[node]];

	return node;
}

// returns no. of entries <= "pos"

int query(int node,int l,int r,int pos)
{
    if(pos<l || r<1)
        return 0;

    if(1<=l && r<=pos)
        return st[node];

    int mid=(l+r)/2;

    int res;
    if(pos<=mid)
        res=query(lc[node],l,mid,pos);
    else
        res=st[lc[node]]+query(rc[node],mid+1,r,pos);

    return res;
}

void solve()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;++i)
        cin>>v[i];

    root[0]=build(1,n);
    for(int i=1;i<=n;++i)
        root[i]=update(root[i-1],1,n,v[i]);

}
