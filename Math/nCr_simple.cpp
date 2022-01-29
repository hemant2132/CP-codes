/*
    -> calculating nCr without computing factorials beforehand
    -> current implementation for N <= 100
*/

int pw(int base, int exp) {
    int res = 1;

    //base %= M;
    for (; exp; exp /= 2) {
        if (exp % 2)
            res = (res * base); // % M;

        base = (base * base); // % M;
    }

    return res;
}

// primes[] can be changed according to requirements
vector<int> primes = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

// res[i] -> power of primes[i] in n!
vector<int> factPowers(int n) {
    vector<int> res;
    for (auto &c : primes) {
        int tmp = n;
        int cnt = 0;

        while (tmp) {
            tmp /= c;
            cnt += tmp;
        }

        res.pb(cnt);
    }

    return res;
}

int nCr(int n, int r) {
    vector<int> tot = factPowers(n);
    vector<int> a = factPowers(r), b = factPowers(n - r);

    int sz = (int)tot.size(), ans = 1;
    for (int i = 0; i < sz; ++i) {
        ans *= pw(primes[i], (tot[i] - (a[i] + b[i])));
    }

    return ans;
}
