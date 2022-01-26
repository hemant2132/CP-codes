/*
    lps[i] -> longest proper prefix of pat[0..i] which is also a suffix of pat[0..i]
    eg - for pat = "abab", lps[] = {0, 0, 1, 2}
*/

void getLPS(string pat, int lps[]) {
    int m = sz(pat);

    lps[0] = 0;
    for (int i = 1, j; i < m; ++i) {
        for (j = lps[i - 1]; j > 0 && pat[i] != pat[j]; j = lps[j - 1]) {}

        if (pat[i] == pat[j])
            ++j;

        lps[i] = j;
    }
}

int getOccurrences(string str, string pat, int lps[]) {
    int n = sz(str);
    int m = sz(pat);

    int ans = 0;
    for (int i = 0, j = 0; i < n;) {
        if (pat[j] == str[i]) {
            ++i;
            ++j;
        }

        if (j == m) {
            ++ans;
            j = lps[j - 1];
        } else if (i < n && pat[j] != str[i]) {
            if (j) {
                j = lps[j - 1];
            } else {
                ++i;
            }
        }
    }

    return ans;
}