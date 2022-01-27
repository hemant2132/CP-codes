/*
    -> Heavy Light Decomposition
    -> ref: https://blog.anudeep2011.com/heavy-light-decomposition/

    -> supports range updates and range queries on paths in a tree, by dividing the tree into chains
    -> for a query/update, we go upwards visiting at most "logn" chains

*/

vector<int> adj[N];
vector<int> par(N, -1), lev(N), subtree(N);
vector<int> base(N), head(N, -1), id(N, -1), pos(N, -1);
// base array, head of chain, chain no. of a node, position of a node in base[]

int segtree[4 * N];
int lazy[4 * N];

int n;
int chain = 0, tim = 0;

// Initialisation

void dfs(int x, int p) {
    if (p != -1)
        lev[x] = lev[p] + 1;

    par[x] = p;
    subtree[x] = 1;

    for (auto &c : adj[x]) {
        if (c != p) {
            dfs(c, x);
            subtree[x] += subtree[c];
        }
    }
}

// Lazy Segment Tree

void build(int node, int start, int en) {
    if (start == en) {
        segtree[node] = base[start];
    } else {
        int mid = (start + en) / 2;
        build(2 * node, start, mid);
        build(2 * node + 1, mid + 1, en);
        segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
    }
}

void updateRange(int node, int beg, int en, int l, int r, int val) {
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
    updateRange(2 * node, beg, mid, l, r, val);
    updateRange(2 * node + 1, mid + 1, en, l, r, val);

    segtree[node] = segtree[2 * node] + segtree[2 * node + 1];
}

int queryRange(int node, int beg, int en, int l, int r) {
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
    int q1 = queryRange(2 * node, beg, mid, l, r);
    int q2 = queryRange(2 * node + 1, mid + 1, en, l, r);

    return q1 + q2;
}

// Utility Functions
// "b" is assumed to be ancestor of "a"

int queryUp(int a, int b) {
    int res = 0;
    int x;

    while (true) {
        if (id[a] == id[b]) {
            res += queryRange(1, 0, n - 1, pos[b], pos[a]);
            break;
        }

        res += queryRange(1, 0, n - 1, pos[head[id[a]]], pos[a]);
        a = par[head[id[a]]];
    }

    return res;
}

void updateUp(int a, int b, int val) {
    while (true) {
        if (id[a] == id[b]) {
            updateRange(1, 0, n - 1, pos[b], pos[a], val);
            break;
        }

        updateRange(1, 0, n - 1, pos[head[id[a]]], pos[a], val);
        a = par[head[id[a]]];
    }
}

// HLD (Decomposition Function)

void hld(int x, int p) {
    if (head[chain] == -1)
        head[chain] = x;

    id[x] = chain;
    pos[x] = tim;
    base[tim++] = 0; // assign value to base[] here

    int mx = -1;
    int big_child = -1;
    for (auto &c : adj[x]) {
        if (c == p)
            continue;

        if (mx < subtree[c]) {
            mx = subtree[c];
            big_child = c;
        }
    }

    if (big_child != -1)
        hld(big_child, x);

    for (auto &c : adj[x]) {
        if (c == p || c == big_child)
            continue;

        ++chain;
        hld(c, x);
    }
}