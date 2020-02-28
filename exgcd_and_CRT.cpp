struct gcd_type
{
    int x,y,d;
};

gcd_type exgcd(int a,int b)
{
    if(b==0)
        return {1, 0, a};

    gcd_type tmp=exgcd(b,a%b);
    return {tmp.y, tmp.x-(a/b)*tmp.y, tmp.d};
}

inline int take_mod(int x, int mod) { x%=mod; if(x<0) x+=mod; return x;}

int n=2;
vector<int> rem(n),num(n);

void CRT()
{
    int res=rem[0];
    int l=num[0];
    for(int i=1;i<n;++i)
    {
        auto tmp=exgcd(l,num[i]);
        int x1=tmp.x;
        int d=tmp.d;

        if((rem[i]-res)%d)
        {
            cout<<"no solution";
            return;
        }

        res=take_mod( res + (x1*((rem[i]-res)/d))%(num[i]/d) * l , l*(num[i]/d) );
        l=l*(num[i]/d);
    }

    cout<<res<<" "<<l;
}
