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

vector<int> primes;
bool is_composite[N];
int mu[N];

void mobius_linear() {
    memset(is_composite, 0, sizeof(is_composite));
    primes.clear();

    mu[1] = 1;

    for (int i = 2; i < N; ++i) {
        if (!is_composite[i]) {
            primes.push_back(i);
            mu[i] = -1;
        }

        for (int j = 0, siz = (int)primes.size(); j < siz && i * primes[j] < N; ++j) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                mu[i * primes[j]] = 0;
                break;
            }
            else {
                mu[i * primes[j]] = mu[i] * mu[primes[j]];
            }
        }
    }
}
