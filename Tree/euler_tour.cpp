/*
    -> Euler Tour of a tree
    -> basically flattening the tree to perform certain tasks...
    -> Further reading:
        1. https://codeforces.com/blog/entry/18369
        2. https://usaco.guide/gold/tree-euler
*/

vector<int> euler, start_time(N), end_time(N);

void dfs(int x, int p) {
    euler.pb(x);
    start_time[x] = sz(euler);

    for (auto c : v[x]) {
        if (c != p)
            dfs(c, x);
    }

    end_time[x] = sz(euler);
}
