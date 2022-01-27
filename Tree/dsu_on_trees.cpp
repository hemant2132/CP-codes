/*
    -> DSU on trees

    -> Can be used for answering queries related to the values in the subtree of all the nodes in a tree in O(NlogN).

    -> ref:
        1. https://codeforces.com/blog/entry/44351 
        2. https://codeforces.com/blog/entry/67696
*/

vector<int> adj[N];     // adjacency list
vector<int> vec[N];     // vec[i] -> nodes in the subtree of node 'i'
vector<int> subtree(N, 1), val(N);

vector<int> cnt(N);

int dfsSubtree(int x, int par) {
    for (auto &c : adj[x]) {
        if (c != par) {
            dfsSubtree(c, x);
            subtree[x] += subtree[c];
        }
    }
}

void dfs(int x, int par, bool keep) {
    int mx = -1, big_child = -1;
    for (auto &c : adj[x]) {
        if (c != par && subtree[c] > mx) {
            mx = subtree[c];
            big_child = c;
        }
    }

    for (auto &c : adj[x]) {
        if (c != par && c != big_child)
            dfs(c, x, false);
    }

    if (big_child != -1) {
        dfs(big_child, x, true);
        swap(vec[x], vec[big_child]);
    }

    vec[x].pb(x);
    ++cnt[val[x]];

    for (auto &c : adj[x]) {
        if (c == par || c == big_child)
            continue;

        for (auto &u : vec[c]) {
            ++cnt[val[u]];
            vec[x].pb(u);
        }
    }

    // at this moment, cnt[] has the value distribution for subtree of 'x'

    if (!keep) {
        for (auto c : vec[x])
            --cnt[val[c]];
    }
}