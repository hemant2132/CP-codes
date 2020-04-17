/*  Logic used: Every composite no. can be uniquely represented as
    q = i * p; where p is the smallest prime factor and i >= p.
    We just need to ensure that every composite no. gets marked exactly once
    and we do that when we reach i by considering all primes p <= i
    and marking the corresponding nos. (i * p) as composites.
*/

/*
    -> can be used to calculate primes upto N=1e8
       in linear time (segmented sieve has better performance)
    -> additionally, it can be easily modified to calculate spf[]
       (takes 1s for N=3e7)
    -> this approach/implementation can be extended to compute multiplicative functions
       in linear time quite comfortably (https://codeforces.com/blog/entry/54090)
*/

//bool comp[N];
vector<int> pr,spf(N);

void sieve_linear()
{
    //memset(comp,0,sizeof(comp));
    fill(spf.begin(),spf.end(),0);
    pr.clear();

    int siz=0;
    for(int i=2;i<N;i++)
    {
        if(spf[i]==0)
        {
            pr.push_back(i);
            spf[i]=i;
            ++siz;
        }

        for(int j=0;j<siz && pr[j]<spf[i] && i*pr[j]<N;++j)
        {
            spf[i*pr[j]]=spf[i];

            //comp[pr[j]*i]=1;
            //if(i%pr[j]==0)
            //    break;
        }
    }
}
