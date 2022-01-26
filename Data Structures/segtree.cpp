/*
    -> Segment Tree
    
    -> ref: 
        1. https://www.hackerearth.com/practice/data-structures/advanced-data-structures/segment-trees/tutorial/
        2. https://cp-algorithms.com/data_structures/segment_tree.html
        3. https://www.hackerearth.com/practice/notes/segment-tree-and-lazy-propagation/

    -> Implementation for:
        1. point update and range query
        2. range update and point query
        3. range update and range query (lazy propagation)
*/

int segtree[4 * N];
int lazy[4 * N];

void build(int node, int beg, int en) {
    if (beg == en) {
        // segtree[node] = base[beg];
        return;
    }

    int mid = (beg + en) / 2;
    build(2 * node, beg, mid);
    build(2 * node + 1, mid + 1, en);

    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

// for point update and range query:
void pointUpdate(int node, int beg, int en, int idx, int val) {
    if (beg == en) {
        // base[idx] = val;
        segtree[node] = val;
        return;
    }

    int mid = (beg + en) / 2;
    if (beg <= idx && idx <= mid) {
        pointUpdate(2 * node, beg, mid, idx, val);
    } else {
        pointUpdate(2 * node + 1, mid + 1, en, idx, val);
    }

    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

int rangeQuery(int node, int beg, int en, int l, int r) {
    if (r < beg || en < l) return 0;
    if (l <= beg && en <= r) return segtree[node];

    int mid = (beg + en) / 2;
    int q1 = rangeQuery(2 * node, beg, mid, l, r);
    int q2 = rangeQuery(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
}

// for range update and point query:
void rangeUpdate(int node, int beg, int en, int l, int r, int val) {
    if (r < beg || en < l) return;

    if (l <= beg && en <= r) {
        segtree[node] += val;
        return;
    }

    int mid = (beg + en) / 2;
    rangeUpdate(2 * node, beg, mid, l, r, val);
    rangeUpdate(2 * node + 1, mid + 1, en, l, r, val);
}

int pointQuery(int node, int beg, int en, int idx, int val = 0) {
    if (beg == en) return val + segtree[node];

    int mid = (beg + en) / 2;
    if (beg <= idx && idx <= mid) {
        return pointQuery(2 * node, beg, mid, idx, val + segtree[node]);
    }
    
    return pointQuery(2 * node + 1, mid + 1, en, idx, val + segtree[node]);
}

// for lazy update and lazy query:
void lazyUpdate(int node, int beg, int en, int l, int r, int val) {
    if (lazy[node] != 0) {
        segtree[node] += (en - beg + 1) * lazy[node];
        if (beg != en) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (beg > en || r < beg || en < l) return;

    if (l <= beg && en <= r) {
        segtree[node] += (en - beg + 1) * val;
        if (beg != en) {
            lazy[2 * node] += val;
            lazy[2 * node + 1] += val;
        }

        return;
    }

    int mid = (beg + en) / 2;
    lazyUpdate(2 * node, beg, mid, l, r, val);
    lazyUpdate(2 * node + 1, mid + 1, en, l, r, val);

    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

int lazyQuery(int node, int beg, int en, int l, int r) {
    if (beg > en || r < beg || en < l) return 0;

    if (lazy[node] != 0) {
        segtree[node] += (en - beg + 1) * lazy[node];
        if (beg != en) {
            lazy[2 * node] += lazy[node];
            lazy[2 * node + 1] += lazy[node];
        }
        lazy[node] = 0;
    }

    if (l <= beg && en <= r) return segtree[node];

    int mid = (beg + en) / 2;
    int q1 = lazyQuery(2 * node, beg, mid, l, r);
    int q2 = lazyQuery(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
}