/*
    -> Totient function
    -> phi(n) = sum (gcd(i, n) == 1) for 1 <= i <= n 
    -> ref: https://cp-algorithms.com/algebra/phi-function.html
*/

vector<int> primes;

// calculating phi(n) in O(sqrt(n))
int totient(int n) {
    int res = n;

    for (int i = 0; primes[i] * primes[i] <= n; ++i) {
        if (n % primes[i] == 0) {
            while (n % primes[i] == 0)
                n /= primes[i];

            res -= res / primes[i];
        }
    }

    if (n > 1)
        res -= res / n;

    return res;
}

vector<int> phi(N);

// calculating phi() for 1..N in O(NloglogN)
void totientAll() {
    for (int i = 1; i < N; ++i)
        phi[i] = i;

    for (int i = 2; i < N; ++i) {
        if (phi[i] == i) {
            for (int j = i; j < N; j += i) {
                phi[j] /= i;
                phi[j] *= (i - 1);
            }
        }
    }
}
