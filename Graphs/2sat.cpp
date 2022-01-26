/*
    -> 2 Satisfiability Problem
    -> gives the solution for a boolean exp. given in CNF with every clause having exactly two literals
    -> ref: https://cp-algorithms.com/graph/2SAT.html
    -> implementation for: https://judge.yosupo.jp/problem/two_sat
    -> some formulae:
        1. a v b = (~a -> b) ^ (~b -> a)
        2. a xor b = (a v b) ^ (~a v ~b)
        3. ~(a xor b) = (~a v b) ^ (a v ~b)
*/

bool fl;

vi v[N], w[N];
bool vis[N];
stack<int> stk;

vi component;     // nodes in current SCC
vi comp(N);       // SCC no. of each node
vector<int> ans; // holds the solution; ans[i] -> value of variable "i"

int n, m;

void dfs(int x) {
    if (vis[x]) return;

    vis[x] = 1;

    if (!fl) {
        for (auto u : v[x])
            dfs(u);

        stk.push(x);
    } else {
        component.pb(x);

        for (auto u : w[x])
            dfs(u);
    }
}

void trans() {
    for (int x = 1; x <= 2 * n; ++x) {
        for (auto u : v[x])
            w[u].pb(x);
    }
}

bool _2sat() {
    fl = 0;
    for (int i = 1; i <= 2 * n; ++i) {
        if (!vis[i])
            dfs(i);
    }

    trans();

    fill(all(vis), 0);

    int x;
    fl = 1;
    int cnt = 1;
    while (!stk.empty()) { // we get the SCCs in topological-sort order
        x = stk.top();
        stk.pop();

        if (vis[x])
            continue;

        component.clear();
        dfs(x);

        // vertices in current SCC stored in component[]

        for (auto c : component)
            comp[c] = cnt;

        ++cnt;
    }

    // checking for satisfiability
    for (int i = 1; i < 2 * n; i += 2)
    {
        if (comp[i] == comp[i + 1])
            return false;

        if (comp[i] < comp[i + 1]) {
            ans.pb(0);
        } else {
            ans.pb(1);
        }
    }

    return true;
}

// variable "x" -> nodes(2x - 1, 2x) denote (x, ~x)
pii get(int x) {
    if (x < 0) return pair(2 * -x, 2 * -x - 1);
    return pair(2 * x - 1, 2 * x);
}

void solve() {
    string s;
    cin >> s >> s;

    cin >> n >> m;

    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;

        // a v b = (~a -> b) ^ (~b -> a)
        auto [x, _x] = get(a);
        auto [y, _y] = get(b);
        v[_x].pb(y);
        v[_y].pb(x);

        cin >> a;
    }

    // for (int i = 1; i <= 2 * n; ++i) {
    //     show(i, v[i]);
    // }

    if (!_2sat()) {
        cout << "s UNSATISFIABLE";
        return;
    }

    cout << "s SATISFIABLE\n";
    cout << "v ";
    for (int i = 0; i < n; ++i) {
        if (!ans[i])
            cout << "-";
        cout << i + 1 << " ";
    }
    cout << 0;
}