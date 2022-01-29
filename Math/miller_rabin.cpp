/*
    -> Miller-Rabin Primality Test
    -> ref: https://cp-algorithms.com/algebra/primality_tests.html
    -> for testing: 999999999999999989 5915587277 1500450271 3267000013 5754853343 4093082899 9576890767
*/

// multiplying two large nos.
int mulmod(int a, int b, int mod) {
    int res = 0;

    a %= mod;
    for (; b; b /= 2) {
        if (b % 2)
            res = add(res, a, mod);

        a = add(a, a, mod);
    }

    return res;
}

int pw(int base, int exp, int mod) {
    int res = 1;

    base %= mod;
    for (; exp; exp /= 2) {
        if (exp % 2)
            res = mulmod(res, base, mod);

        base = mulmod(base, base, mod);
    }

    return res;
}

bool check_composite(int n, int a, int d, int s) {
    int x = pw(a, d, n);
    if (x == 1 || x == n - 1)
        return false;

    for (int r = 1; r < s; ++r) {
        x = mulmod(x, x, n);
        if (x == n - 1)
            return false;
    }

    return true;
}

// for randomized, generate nos. in [2, n-2]
bool millerRabin(int n) {
    if (n < 2) return false;

    int r = 0;
    int d = n - 1;
    while ((d & 1) == 0) {
        d >>= 1;
        r++;
    }

    vi bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}; // {2, 3, 5, 7} for 32-bit
    for (int a : bases) {
        if (n == a) // since, "a" is prime
            return true;
        if (check_composite(n, a, d, r))
            return false;
    }

    return true;
}
