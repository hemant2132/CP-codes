/*
    -> Articulation Points and Bridges

    -> articulation point: a vertex which when removed along with all the edges associated with it, makes the graph disconnected
    -> bridge: an edge which when removed makes the graph disconnected

    -> current implementation is only for undirected graphs

    -> ref: 
        1. https://codeforces.com/blog/entry/68138
        2. https://www.hackerearth.com/practice/algorithms/graphs/articulation-points-and-bridges/tutorial/
*/

vector<int> adj[N];
vector<int> disc(N);    // disc[i] = time at which node 'i' was discovered 
vector<int> low(N);    // low[i] = min. amount of disc[j] for all nodes 'j' connected to node 'i'
bool vis[N];

vector<int> articulation_points;
vector<pair<int, int>> bridges;

int tim = 1;

void dfs(int x, int par) {
    vis[x] = true;
    disc[x] = low[x] = tim++;
    int child = 0;

    for (auto c : adj[x]) {
        if (c == par)
            continue;

        if (!vis[c]) { // forward edge
            ++child;

            dfs(c, x);

            low[x] = min(low[x], low[c]);

            if ((par == -1 && child > 1) || (par != -1 && low[c] >= disc[x]))
                articulation_points.pb(x);

            if (low[c] > disc[x])
                bridges.pb({min(c, x), max(c, x)});
        } else { // back edge
            low[x] = min(low[x], disc[c]);
        }
    }
}