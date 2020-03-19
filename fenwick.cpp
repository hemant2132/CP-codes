int bit[N];

void update(int idx, int val)
{
	while(idx<=n)
	{
		bit[idx]+=val;
		idx+=idx&-idx;
	}
}

int pref(int idx)
{
	int ans=0;
	while(idx>0)
	{
		ans+=bit[idx];
		idx-=idx&-idx;
	}
	return ans;
}

int rsum(int l, int r)
{
    if(l>r)
        return 0;

	return pref(r) - pref(l-1);
}
