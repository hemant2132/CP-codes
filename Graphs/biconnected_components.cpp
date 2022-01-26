/*
    -> Biconnected Component

    -> A biconnected component of a given graph is the maximal connected subgraph which does not contain any articulation vertices.

    -> The idea is to push nodes to a stack (as we visit them in the DFS tree) and when we reach back to an articulation point (or the root), we pop all the nodes visited after it to get a biconnected component.

    -> ref: https://www.hackerearth.com/practice/algorithms/graphs/biconnected-components/tutorial/  
*/

vector<int> adj[N];
vector<int> disc(N), low(N);
bool vis[N];

stack<int> stk;

int tim = 1;

void dfs(int x, int par) {
    vis[x] = true;
    disc[x] = low[x] = tim++;

    stk.push(x);

    for (auto c : adj[x]) {
        if (c == par)
            continue;

        if (!vis[c]) {
            dfs(c, x);

            low[x] = min(low[x], low[c]);

            if (low[c] >= disc[x]) {
                vector<int> component;
                component.pb(x);

                while (stk.top() != x) {
                    component.pb(stk.top());
                    stk.pop();
                }

                // component[] -> vertices of the biconnected component
            }
        } else if (disc[c] < low[x]) {
            low[x] = disc[c];
        }
    }
}