/*
    -> Bridge Tree

    -> Bridges in a graph divide the graph into different components such that when we traverse a bridge, we move from one such component to another. Let’s call these components as bridge components. 
    -> A "bridge tree" is a tree obtained by shrinking each of the bridge components of the graph into a single node such that an edge between two nodes in the resulting tree correspond to the bridge edge in the original graph connecting two different bridge components represented by the two nodes of the tree.

    -> ref: https://tanujkhattar.wordpress.com/2016/01/10/the-bridge-tree-of-a-graph/
*/

vector<int> adj[N], disc(N), low(N);
bool vis[N];

vector<int> bridge_tree[N];     // adjacency list for bridge tree
vector<int> comp(N);            // comp[i] -> component no. for node 'i'

stack<int> stk;

int tim = 1, comp_cnt = 1;

void dfs(int x, int par) {
    vis[x] = true;
    disc[x] = low[x] = tim++;
    
    for (auto c : adj[x]) {
        if (c == par)
            continue;

        if (!vis[c]) {
            stk.push(x);
            stk.push(c);

            dfs(c, x);

            low[x] = min(low[x], low[c]);

            if (low[c] > disc[x]) { // edge (x, c) is a bridge
                while (true) {
                    comp[stk.top()] = comp_cnt;
                    stk.pop();

                    if (stk.top() == x)
                        break;
                }
                
                ++comp_cnt;
            }
        } else if (disc[c] < low[x]) {
            low[x] = disc[c];
        }
    }

    if (par == -1) {
        while (!stk.empty()) {
            comp[stk.top()] = compCnt;
            stk.pop();
        }
    }
}

void constructBridgeTree(int n) {
    dfs(1, -1);

    repa(i, 1, n) {
        for (auto c : adj[i]) {
            if (comp[i] != comp[c])
                bridge_tree[comp[i]].pb(comp[c]);
        }
    }

    // repa(i, 1, n)
    //     cout << comp[i] << " ";
    // cout << "\n";

    // repa(i, 1, n)
    //     show(i, bridge_tree[i]);
}
