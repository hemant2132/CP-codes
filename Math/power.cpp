/*
    -> Binary Exponentiation
    -> ref: https://cp-algorithms.com/algebra/binary-exp.html
*/

int pw(int base, int exp, int mod = MOD) {
    int res = 1;

    base %= mod;
    for (; exp; exp /= 2) {
        if (exp % 2)
            res = mul(res, base, mod);
            
        base = mul(base, base, mod);
    }

    return res;
}
