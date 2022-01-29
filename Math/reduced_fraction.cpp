// gives reduced form of "a / b"
pii reduced(int a, int b)  {
    if (a == 0 && b == 0) return {0, 0};
    if (b == 0) return {1, 0};
    if (a == 0) return {0, 1};

    int g = abs(__gcd(a, b));
    a /= g;
    b /= g;

    if (b < 0) a *= -1, b *= -1;

    return {a, b};
}
