/*
    -> Persistent Segment Tree

    -> We can access any "version" of the data structure efficiently (both in time and memory consumption).

    -> ref: 1. Anudeep's Blog: https://blog.anudeep2011.com/persistent-segment-trees-explained-with-spoj-problems/
            2. https://discuss.codechef.com/t/persistence-made-simple-tutorial/14915
            3. Gaurav Sen video: https://www.youtube.com/watch?v=TH9n_HVkjQM
            4. https://github.com/Ashishgup1/Competitive-Coding/blob/master/Persistent%20Segment%20Tree.cpp
*/

int v[N];

int cnt = 0;
int root[N], segtree[21 * N], left_child[21 * N], right_child[21 * N];

int build(int l, int r) {
    int node = ++cnt;

    if (l == r) return node;

    int mid = (l + r) / 2;
    left_child[node] = build(l, mid);
    right_child[node] = build(mid + 1, r);

    return node;
}

int update(int old_node, int l, int r, int pos) {
    int node = ++cnt;

    if (l == r) {
        segtree[node] = segtree[old_node] + 1;
        return node;
    }

    int mid = (l + r) / 2;
    left_child[node] = left_child[old_node];
    right_child[node] = right_child[old_node];

    if (pos <= mid) {
        left_child[node] = update(left_child[old_node], l, mid, pos);
    } else {
        right_child[node] = update(right_child[old_node], mid + 1, r, pos);
    }

    segtree[node] = segtree[left_child[node]] + segtree[right_child[node]];

    return node;
}

// returns no. of entries <= "pos"
int query(int node, int l, int r, int pos) {
    if (pos < l || r < 1) return 0;
    if (1 <= l && r <= pos) return segtree[node];

    int mid = (l + r) / 2;

    int res;
    if (pos <= mid) {
        res = query(left_child[node], l, mid, pos);
    } else {
        res = segtree[left_child[node]] + query(right_child[node], mid + 1, r, pos);
    }

    return res;
}

void solve() {
    int n;
    cin >> n;

    for (int i = 1; i <= n; ++i) 
        cin >> v[i];

    root[0] = build(1, n);
    for (int i = 1; i <= n; ++i) {
        root[i] = update(root[i - 1], 1, n, v[i]);
    }
}
