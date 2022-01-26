string txt;
int n;

vector<int> pos, sa;
vector<int> cnt, nxt;
vector<bool> bh, b2h;

vector<int> lcp;

void init() {
    sa.rz(n);
    pos.rz(n);
    cnt.rz(n);
    nxt.rz(n);
    bh.rz(n);
    b2h.rz(n);
    lcp.rz(n - 1);
}

bool smaller_first_char(int a, int b) {
    return txt[a] < txt[b];
}

void buildSA() {
    for (int i = 0; i < n; ++i)
        sa[i] = i;

    sort(sa.begin(), sa.begin() + n, smaller_first_char);

    for (int i = 0; i < n; ++i) {
        bh[i] = i == 0 || txt[sa[i]] != txt[sa[i - 1]];
        b2h[i] = false;
    }

    for (int h = 1; h < n; h <<= 1) {
        int buckets = 0;
        for (int i = 0, j; i < n; i = j) {
            j = i + 1;
            while (j < n && !bh[j])
                ++j;
            nxt[i] = j;
            ++buckets;
        }

        if (buckets == n)
            break;

        for (int i = 0; i < n; i = nxt[i]) {
            cnt[i] = 0;
            for (int j = i; j < nxt[i]; ++j)
                pos[sa[j]] = i;
        }

        cnt[pos[n - h]]++;
        b2h[pos[n - h]] = true;
        for (int i = 0; i < n; i = nxt[i]) {
            for (int j = i; j < nxt[i]; ++j) {
                int s = sa[j] - h;
                if (s >= 0) {
                    int head = pos[s];
                    pos[s] = head + cnt[head]++;
                    b2h[pos[s]] = true;
                }
            }

            for (int j = i; j < nxt[i]; ++j) {
                int s = sa[j] - h;
                if (s >= 0 && b2h[pos[s]]) {
                    for (int k = pos[s] + 1; !bh[k] && b2h[k]; ++k)
                        b2h[k] = false;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            sa[pos[i]] = i;
            bh[i] = bh[i] | b2h[i];
        }
    }

    for (int i = 0; i < n; ++i)
        pos[sa[i]] = i;
}

void buildLCP() {
    int k = 0;
    for (int i = 0; i < n; ++i) {
        if (pos[i] == n - 1) {
            k = 0;
            continue;
        }

        int j = sa[pos[i] + 1];
        while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
            k++;
        lcp[pos[i]] = k;

        if (k)
            --k;
    }
}

void dispSA() {
    cout << "sa: ";
    nshow(sa, n);
    cout << "pos: ";
    nshow(pos, n);
    cout << "lcp: ";
    nshow(lcp, n - 1);

    for (int i = 0; i < n; ++i)
        cout << txt.substr(sa[i]) << "\n";
}
