const int SZ=4;

void disp(int mat[SZ][SZ])
{
    for(int i=0;i<SZ;++i)
    {
        for(int j=0;j<SZ;++j)
            cout<<mat[i][j]<<" ";
        cout<<"\n";
    }
}

void mul(int a[SZ][SZ], int b[SZ][SZ])
{
    int res[SZ][SZ];
    for(int i=0;i<SZ;++i)
    {
        for(int j=0;j<SZ;++j)
        {
            res[i][j]=0;
            for(int k=0;k<SZ;++k)
                res[i][j]=( res[i][j]%M + (a[i][k]%M*b[k][j]%M)%M )%M;
        }
    }

    for(int i=0;i<SZ;++i)
    {
        for(int j=0;j<SZ;++j)
            a[i][j]=res[i][j];
    }
}

void power(int x[SZ][SZ], int n)
{
    int res[SZ][SZ];
    mem(res,0);

    for(int i=0;i<SZ;++i)
        res[i][i]=1;

    for(;n;n/=2)
    {
        if(n%2)
            mul(res,x);

        mul(x,x);
    }

    for(int i=0;i<SZ;++i)
    {
        for(int j=0;j<SZ;++j)
            x[i][j]=res[i][j];
    }
}

int NthTerm(int n)
{
    if(n==0)
        return 1;
    if(n==1)
        return 2;

    //transformation matrix
    int trans[SZ][SZ] = {};

    //initial case
    int base[SZ][1]={};

    power(trans,n-1);

    int res=0;
    for(int i=0;i<SZ;++i)
        res=( res + (trans[0][i]*base[i][0])%M )%M;

    return res;
}
