vector<int> arr(N),siz(N);

void init(int n)
{
    for(i=1;i<=n;++i)
        arr[i]=i,siz[i]=1;
}

int root(int x)
{
    while(arr[x]!=x)
    {
        arr[x]=arr[arr[x]];
        x=arr[x];
    }

    return x;
}

bool uni(int a,int b)
{
    int x=root(a);
    int y=root(b);

    if(x==y)
        return 0;

    if(siz[x]<siz[y])
        swap(x,y);

    arr[y]=x;
    siz[x]+=siz[y];

    return 1;
}
