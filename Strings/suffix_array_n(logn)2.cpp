string txt;
int n;

vector<int> sa, tmp, pos;
vector<int> lcp;
int gap, prv;

bool cmp(const int &x, const int &y) {
    if (gap == 1) return txt[x] < txt[y];

    int a;
    if (x + prv >= n) {
        a = -1;
    } else {
        a = pos[x + prv];
    }
    
    int b;
    if (y + prv >= n) {
        b = -1;
    } else {
        b = pos[y + prv];
    }

    return makep(pos[x], a) < makep(pos[y], b);
}

void buildSA() {
    sa.rz(n);
    pos.rz(n);
    tmp.rz(n);

    for (int i = 0; i < n; ++i)
        sa[i] = i;

    for (gap = 1; ; gap *= 2) {
        sort(all(sa), cmp);

        tmp[0] = 0;
        for (int i = 1; i < n; ++i)
            tmp[i] = tmp[i - 1] + cmp(sa[i - 1], sa[i]);

        for (int i = 0; i < n; ++i)
            pos[sa[i]] = tmp[i];

        if (*max_element(all(tmp)) == n - 1)
            break;

        prv = gap;
    }
}

void buildLCP() {
    int k = 0;
    lcp.rz(n - 1);
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
    show(sa);
    cout << "pos: ";
    show(pos);
    cout << "lcp: ";
    show(lcp);

    for (int i = 0; i < n; ++i)
        cout << txt.substr(sa[i]) << "\n";
}
