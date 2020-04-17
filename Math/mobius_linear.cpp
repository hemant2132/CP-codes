/*
  https://codeforces.com/blog/entry/53925
*/

/*
  -> mu(n) = 1, if n=1
           = (-1)^r , if n = p1*p2*p3...*pr
           = 0, otherwise
  -> e(n) = sum(d|n) mu(d)
  -> phi(d) = sum(d|n) d*mu(n/d)
  -> sum(i, 1..n) sum(j, 1..n) gcd(i,j) = sum(k, 1..n) mu(k) * (floor(n/k))^2
  -> sum(i, 1..n) sum(j, 1..n) gcd(i,j) = sum(k, 1..n) phi(k) * (floor(n/k))^2
*/

vector<int> pr;
bool comp[N];
int mu[N];

void mobius_linear()
{
	mem(comp,0);
	pr.clear();

	mu[1]=1;

	for(int i=2;i<N;++i)
    {
		if(!comp[i])
		{
			pr.pb(i);
			mu[i]=-1;
		}

		for(int j=0,siz=sz(pr);j<siz && i*pr[j]<N;++j)
        {
			comp[i*pr[j]]=1;
			if(i%pr[j]==0)
			{
				mu[i*pr[j]]=0;
				break;
			}
            else
            {
				mu[i*pr[j]]=mu[i]*mu[pr[j]];
			}
		}
	}
}
