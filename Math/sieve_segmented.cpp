/*
    -> Segmented Sieve
    -> ref: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html#segmented-sieve
    -> better in terms of memory complexity: O(sqrt(n) + S)
*/

vector<int> primes;

void sieve_segmented() {
    int n = N;
    const int S = 5e4;

    primes.clear();
    vector<int> primes_nsqrt;
    int nsqrt = sqrt(n);
    vector<char> is_prime(nsqrt + 1, true);

    for (int i = 2; i <= nsqrt; ++i) {
        if (is_prime[i]) {
            primes_nqrt.pb(i);
            for (int j = i * i; j <= nsqrt; j += i)
                is_prime[j] = false;
        }
    }

    int result = 0;
    vector<char> block(S);
    for (int k = 0; k * S <= n; ++k) {
        fill(all(block), true);

        int start = k * S;
        for (int &p : primes_nqrt) {
            int start_ind = (start + p - 1) / p;
            int j = max(start_ind, p) * p - start;
            for (; j < S; j += p)
                block[j] = false;
        }

        if (k == 0)
            block[0] = block[1] = false;

        for (int i = 0; i < S && start + i <= n; ++i) {
            if (block[i])
                primes.pb(start + i);
        }
    }
}