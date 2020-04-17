/*
    other multiplicative functions can also be implemented in this way
*/

vector<int> pr;
bool comp[N];
int phi[N];

void totient_linear()
{
	mem(comp,0);
	pr.clear();

	phi[1]=1;

	for(int i=2;i<N;++i)
    {
		if(!comp[i])
		{
			pr.pb(i);
			phi[i]=i-1;
		}

		for(int j=0,siz=sz(pr);j<siz && i*pr[j]<N;++j)
        {
			comp[i*pr[j]]=1;
			if(i%pr[j]==0)
			{
				phi[i*pr[j]]=phi[i]*pr[j];
				break;
			}
            else
            {
				phi[i*pr[j]]=phi[i]*phi[pr[j]];
			}
		}
	}
}
