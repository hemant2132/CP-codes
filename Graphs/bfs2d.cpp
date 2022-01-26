int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

bool valid(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m && mat[x][y] != '#' && dist[x][y] == inf;
}

void bfs2d(int start_x, int start_y) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j)
            dist[i][j] = inf;

    queue<pair<int, int>> qu;
    qu.push({start_x, start_y});
    dist[start_x][start_y] = 0;

    while (!qu.empty()) {
        auto [x, y] = qu.front();
        qu.pop();

        for (int i = 0; i < 4; ++i) {
            int a = x + dx[i];
            int b = y + dy[i];

            if (valid(a, b)) {
                dist[a][b] = dist[x][y] + 1;
                qu.push(pair(a, b));
            }
        }
    }
}