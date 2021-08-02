/*
    -> Linear Seve

    -> Logic used: 
        - Every composite no. can be uniquely represented as q = i * p; where p is the smallest prime factor and i >= p.
        - We just need to ensure that every composite no. gets marked exactly once. 
        - We do that by reaching i by considering all primes p_j <= i and marking the corresponding nos. (i * p_j) (such that p_j <= smallest_prime_factor(i)) as composites.

    -> can be used to calculate primes upto N = 1e8 in linear time (segmented sieve has better performance)
    -> additionally, it can be easily modified to calculate spf[] (takes 1s for N = 3e7)
    -> this approach/implementation can be extended to compute multiplicative functions in linear time quite comfortably (https://codeforces.com/blog/entry/54090)
    
    -> ref: https://cp-algorithms.com/algebra/prime-sieve-linear.html
*/

// for just finding primes

bool isComposite[N];
vector<int> primes;

void sieve_linear()
{
    memset(isComposite, 0, sizeof(isComposite));
    primes.clear();

    for (int i = 2; i < N; ++i)
    {
        if (!isComposite[i])
            primes.push_back(i);

        for (int j = 0, siz = primes.size(); j < siz && i * primes[j] < N; ++j)
        {
            isComposite[primes[j] * i] = true;
            if(i % primes[j] == 0)
               break;
        }
    }
}

// for smallest prime factor

vector<int> primes, spf(N);

void sieve_linear()
{
    fill(spf.begin(), spf.end(), 0);
    primes.clear();

    for (int i = 2; i < N; ++i)
    {
        if (spf[i] == 0)
        {
            primes.push_back(i);
            spf[i] = i;
        }

        for (int j = 0, siz = primes.size(); j < siz && primes[j] <= spf[i] && i * primes[j] < N; ++j)
            spf[i * primes[j]] = primes[j];
    }
}
