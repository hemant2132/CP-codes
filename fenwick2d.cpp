int bit[N][N];

void update(int x,int y,int val)
{
	for(int i=x;i<=n;i+=i&-i)
		for(int j=y;j<=n;j+=j&-j)
			bit[i][j]+=val;
}

int pref(int x,int y)
{
	int ans=0;
	for(int i=x;i>0;i-=i&-i)
    {
        for(int j=y;j>0;j-=j&-j)
			ans+=bit[i][j];
	}

	return ans;
}

int query(int x1,int y1,int x2,int y2)
{
	int ans=pref(x2,y2);
	ans-=pref(x1-1,y2);
	ans-=pref(x2,y1-1);
	ans+=pref(x1-1,y1-1);

	return ans;
}
