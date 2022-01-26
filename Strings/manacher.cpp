/*
    p[0][i] -> no. of "even" length pals. centered at i (precisely, the one to the right of the exact center)
    p[1][i] -> no. of "odd" length pals. centered at i (except for pals. of length = 1)

    no. of pals. for i => radius for that i

    eg - for str = "abbbba"
    p[0][i] = {0, 0, 1, 3, 1, 0}
    p[1][i] = {0, 0, 1, 1, 0, 0}
*/

void manacher(string str) {
    int n = sz(str);

    vector<vector<int>> p(2, vector<int>(n, 0));

    for (int z = 0; z < 2; ++z) {
        for (int i = 0, l = 0, r = 0; i < n; ++i) {
            int t = r - i + !z;

            if (i < r)
                p[z][i] = min(t, p[z][l + t]);

            int L = i - p[z][i], R = i + p[z][i] - !z;
            while (L - 1 >= 0 && R + 1 < n && str[L - 1] == str[R + 1])
                p[z][i]++, L--, R++;

            if (R > r)
                l = L, r = R;
        }
    }
}