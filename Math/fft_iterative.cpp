/*
    -> Iterative implementation of FFT
    -> ref: https://cp-algorithms.com/algebra/fft.html

    -> the funda is to process the DnC tree in iteratively in a feasible manner
    -> the "bit-reversal permutation" proves to be the key here
    -> y_i from a_i is obtained as we jump from one level of the tree to the next upwards
*/

using cd=complex<double>;

void fft(vector<cd> &a,bool invert)
{
    int n=sz(a);

    for(int i=1,j=0;i<n;++i)                // obtaining the bit-reversal permutation
    {
        int bit=n>>1;                       // equivalent to adding "1" to the previously obtained "j" (index) in reversed manner
        for(;j&bit;bit>>=1)
            j^=bit;

        j^=bit;

        if(i<j)
            swap(a[i],a[j]);
    }

    for(int len=2;len<=n;len<<=1)
    {
        double ang=2*pi/len*(invert ? -1 : 1);
        cd wlen(cos(ang),sin(ang));

        for(int i=0;i<n;i+=len)
        {
            cd w(1);
            int tmp=len/2;
            for(int j=0;j<tmp;++j)
            {
                cd u=a[i+j],v=a[i+j+tmp]*w;            // applying butterfly transform
                a[i+j]=u+v;
                a[i+j+tmp]=u-v;

                w*=wlen;
            }
        }
    }

    if(invert)
    {
        for(cd& x:a)
            x/=n;
    }
}

vector<int> multiply(vector<int> const& a,vector<int> const& b)
{
    vector<cd> fa(all(a)), fb(all(b));

    int n=1;
    int siz=sz(a)+sz(b);
    while(n<siz)
        n<<=1;
    fa.rz(n);
    fb.rz(n);

    fft(fa,0);
    fft(fb,0);
    for(int i=0;i<n;++i)
        fa[i]*=fb[i];
    fft(fa,1);

    vector<int> result(n);
    for(int i=0;i<n;++i)
        result[i]=round(fa[i].real());
    return result;
}
