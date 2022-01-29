/*
    -> Sieve of Eratosthenes
    -> ref: https://cp-algorithms.com/algebra/sieve-of-eratosthenes.html
*/

vector<int> is_prime(N, 1), primes;

void sieve() {
    is_prime[0] = is_prime[1] = 0;
    for (int i = 2; i * i < N; ++i) {
        if (is_prime[i]) {
            for (int j = i * i; j < N; j += i)
                is_prime[j] = 0;
        }
    }

    for (int i = 2; i < N; ++i) {
        if (is_prime[i])
            primes.pb(i);
    }
}