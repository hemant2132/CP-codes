/*
    -> Divide and Conquer DP optimisation trick
    -> can be applied to recurrences of the form:
        dp(i,j) = min/max (k<j) dp(i-1,k) + cost(k+1,j)

    -> Let's denote by A{i][j] the optimal "k" then the property
       required to apply this trick is that for any i and j,
        A[i][j] <= A[i][j+1]
        i.e., the optimal k is monotone on j for a fixed i

    ->to check for monotonicity, one can use this condition (which is sufficient but not necessary):
        cost[a][d] + cost[b][c] <= cost[a][c] + cost[b][d]
        where a < b < c < d
*/

/*
    below implementation based on submission for https://codeforces.com/contest/321/problem/E
*/


// 0-based indexing

// dp[i][j] -> min. value for a(0..j) with (i+1) "partitions"
// here, I have used "2" instead of "K" as max. size to save up on memory/time

vector<vi> dp;
int pre[N][N],cost[N][N];

int n,k;

// O(nlogn)
// Computes the values for elements of dp[i] in the range [l, r] knowing that
// the point of optimality for them lies within the range [optl, optr].
void dnc(int l,int r,int optl,int optr)
{
    if(l>r)
        return;

    int mid=(l+r)>>1;

    pii best={inf,-1};
    for(int i=optl;i<=min(mid,optr);++i)
        best=min(best,{dp[0][i]+cost[i+1][mid],i});             // recurrence

    dp[1][mid]=best.F;
    int optmid=best.S;

    if(l!=r)
    {
        dnc(l,mid-1,optl,optmid);
        dnc(mid+1,r,optmid,optr);
    }
}

void solve()
{
    cin>>n>>k;

    char ch;
    for(int i=0;i<n;++i)
    {
        for(int j=0;j<n;++j)
        {
            cin>>ch;

            if(j>=i)
                pre[i][j+1]=pre[i][j]+(ch-'0');
        }
    }

    int sum;
    for(int i=n-1;i>=0;--i)
    {
        sum=0;
        for(int j=n-1;j>=0;--j)
        {
            sum+=pre[j][i+1]-pre[j][j];
            cost[j][i]=sum;
        }
    }

    dp=vector<vi>(2,vi(n));
    for(int i=0;i<n;++i)
        dp[0][i]=cost[0][i];

    // O(k * nlogn)
    for(int i=1;i<k;++i)
    {
        dnc(0,n-1,0,n-1);
        dp[0]=dp[1];
    }

    cout<<dp[0][n-1];
}


