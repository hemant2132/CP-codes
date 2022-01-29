/*
    -> Extended Euclidean Algorithm and Chinese Remainder Theorem
    -> ref: https://codeforces.com/blog/entry/61290
    -> tested on https://open.kattis.com/problems/generalchineseremainder
*/

struct GcdType {
    int x, y, d;
};

GcdType exgcd(int a, int b) {
    if (b == 0)
        return {1, 0, a};

    GcdType tmp = exgcd(b, a % b);
    return {tmp.y, tmp.x - (a / b) * tmp.y, tmp.d};
}

int modinv(int a, int b) {
    auto tmp = exgcd(a, b);
    return (tmp.x + b) % b;
}

inline int takeMod(int x, int mod) {
    x %= mod;
    if (x < 0) x += mod;
    return x;
}

int n = 2;
vector<int> rem(n), num(n);

void crt() {
    int res = rem[0];
    int l = num[0];
    for (int i = 1; i < n; ++i) {
        auto tmp = exgcd(l, num[i]);
        int x1 = tmp.x;
        int d = tmp.d;

        if ((rem[i] - res) % d) {
            cout << "no solution";
            return;
        }

        res = takeMod(res + (x1 * ((rem[i] - res) / d)) % (num[i] / d) * l, l * (num[i] / d));
        l = l * (num[i] / d);
    }

    cout << res << " " << l;
}