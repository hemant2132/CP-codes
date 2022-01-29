/*
    -> Totient function (linear sieve)
    -> other multiplicative functions can also be implemented in this way
    -> ref: https://codeforces.com/blog/entry/54090
*/

vector<int> primes;
bool is_composite[N];
int phi[N];

void totient_linear() {
    memset(is_composite, 0, sizeof(is_composite));
    primes.clear();

    phi[1] = 1;

    for (int i = 2; i < N; ++i) {
        if (!is_composite[i]) {
            primes.pb(i);
            phi[i] = i - 1;
        }

        for (int j = 0, siz = (int)primes.size; j < siz && i * primes[j] < N; ++j) {
            is_composite[i * primes[j]] = true;
            if (i % primes[j] == 0) {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            else {
                phi[i * primes[j]] = phi[i] * phi[primes[j]];
            }
        }
    }
}
