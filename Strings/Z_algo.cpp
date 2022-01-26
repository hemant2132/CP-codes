/*
    z[i] -> longest substring starting from i which is also
            a prefix of str
    eg - for str = "ababa", z = {X, 0, 3, 0, 1}
*/

void zAlgo(string str, int z[]) {
    int n = sz(str);
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i) {
        if (i > r) {
            for (l = r = i; r < n && str[r - l] == str[r]; ++r) {}
            z[i] = r - l;
            --r;
        }
        else {
            int k = i - l;
            if (z[k] < r - i + 1) {
                z[i] = z[k];
            } else {
                for (l = i; r < n && str[r - l] == str[r]; ++r) {}
                z[i] = r - l;
                --r;
            }
        }
    }
}