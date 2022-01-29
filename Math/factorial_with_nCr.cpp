/*
    -> Binomial Coefficients
    -> Further reading: https://cp-algorithms.com/combinatorics/binomial-coefficients.html
*/

vector<int> fact(N), invfact(N);

int pw(int base, int exp) {
    int res = 1;

    base %= MOD;
    for (; exp; exp /= 2) {
        if (exp % 2)
            res = mul(res, base);

        base = mul(base, base);
    }

    return res;
}

void computeFactorials() {
    fact[0] = 1;
    for (int i = 1; i < N; ++i)
        fact[i] = mul(fact[i - 1], i);

    invfact[N - 1] = pw(fact[N - 1], MOD - 2);
    for (int i = N - 2; i >= 0; --i)
        invfact[i] = mul(invfact[i + 1], (i + 1));
}

int nCr(int n, int r)
{
    if (n < r) return 0;

    int res = mul(fact[n], invfact[r]);
    res = mul(res, invfact[n - r]);

    return res;
}
