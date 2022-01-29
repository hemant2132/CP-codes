/*
    -> Recursive implementation of Fast Fourier Transform
    -> usage: multiplication of n-degree polynomials in O(nlogn)
    -> ref: https://cp-algorithms.com/algebra/fft.html

    -> steps:
        1. converting a(x) and b(x) into point-value form, using n complex roots of unity
        2. c(x) is obtained in point-value form simply by loop(0..n-1) c(x_i) = a(x_i) * b(x_i)
        3. c(x) is converted to coefficient form using inverse FFT which is similar to direct FFT

    -> basically, the properties of nth roots of unity are exploited and a divide and conquer approach is used
*/

using cd = complex<double>;

void fft(vector<cd> &a, bool invert)
{
    int n = sz(a);
    if (n == 1)
        return;

    vector<cd> a0(n / 2), a1(n / 2); // a0 -> even coefficients, a1 -> odd coefficients
    for (int i = 0; 2 * i < n; ++i)
    {
        a0[i] = a[2 * i];
        a1[i] = a[2 * i + 1];
    }

    fft(a0, invert); // divide
    fft(a1, invert);

    double ang = 2 * pi / n * (invert ? -1 : 1);
    cd w(1), wn(cos(ang), sin(ang));

    for (int i = 0; 2 * i < n; ++i)
    {
        a[i] = a0[i] + w * a1[i]; // conquer
        a[i + n / 2] = a0[i] - w * a1[i];

        if (invert)
        {
            a[i] /= 2; // here "/2" at each level gives us the "final value/n"
            a[i + n / 2] /= 2;
        }

        w *= wn;
    }
}

vector<int> multiply(vector<int> const &a, vector<int> const &b)
{
    vector<cd> fa(all(a)), fb(all(b));

    int n = 1;
    int siz = sz(a) + sz(b);
    while (n < siz)
        n <<= 1;
    fa.rz(n);
    fb.rz(n);

    fft(fa, 0);
    fft(fb, 0);
    for (int i = 0; i < n; ++i)
        fa[i] *= fb[i];
    fft(fa, 1);

    vector<int> result(n);
    for (int i = 0; i < n; ++i)
        result[i] = round(fa[i].real());
    return result;
}
