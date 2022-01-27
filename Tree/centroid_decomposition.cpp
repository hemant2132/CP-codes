/*
    -> Centroid Decomposition
    -> ref: https://threadsiiithyderabad.quora.com/Centroid-Decomposition-of-a-Tree
*/

set<int> adj[N];
vector<int> subtree(N), par(N);

int nodes;

void dfsSubtree(int x, int p) {
    subtree[x] = 1;
    ++nodes;
    for (auto &c : adj[x]) {
        if (c != p) {
            dfsSubtree(c, x);
            subtree[x] += subtree[c];
        }
    }
}

int dfsCentroid(int x, int p) {
    for (auto &c : adj[x]) {
        if (c != p && subtree[c] > nodes / 2)
            return dfsCentroid(c, x);
    }

    return x;
}

void decompose(int x, int p) {
    nodes = 0;
    dfsSubtree(x, -1);
    int centroid = dfsCentroid(x, -1);

    par[centroid] = p;

    for (auto &c : adj[centroid]) {
        adj[c].erase(centroid);
        decompose(c, centroid);
    }

    adj[centroid].clear();
}