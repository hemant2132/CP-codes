/*
    -> Kosaraju's algorithm to find SCCs

    -> A directed graph is strongly connected if there is a directed path from any vertex to every other vertex.
    -> Similar to connected components, a directed graph can be broken down into Strongly Connected Components.

    -> ref: 
        1. https://www.hackerearth.com/practice/algorithms/graphs/strongly-connected-components/tutorial/
        2. https://cp-algorithms.com/graph/strongly-connected-components.html
*/

vector<int> adj[N], rev_adj[N];
bool vis[N];

stack<int> stk;
vector<int> component;

void dfs1(int x) {
    vis[x] = true;

    for (auto c : adj[x]) {
        if (!vis[c])
            dfs1(c);
    } 

    stk.push(x);
}

void dfs2(int x) {
    vis[x] = true;
    component.pb(x);

    for (auto c : rev_adj[x]) {
        if (!vis[c])
            dfs2(c);
    }
}

void transpose(int n) {
    for (int x = 1; x <= n; ++x) {
        for (auto u : adj[x])
            rev_adj[u].pb(x);
    }
}

void findSCC(int n) {
    for (int i = 1; i <= n; ++i) {
        if (!vis[i])
            dfs1(i);
    }

    transpose(n);

    for (int i = 1; i <= n; ++i)
        vis[i] = false;

    while (!stk.empty()) {
        int x = stk.top();
        stk.pop();

        if (vis[x])
            continue;

        component.clear();
        dfs2(x);

        // vertices in current SCC stored in component[]
    }
}