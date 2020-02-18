int pw(int x,int n)
{
    int res=1;

    x%=M;
    for(;n;n/=2)
    {
        if(n%2)
            res=(res*x)%M;

        x=(x*x)%M;
    }

    return res;
}
