// todo, https://jlmartin.ku.edu/~jlmartin/courses/math105-F11/Lectures/chapter5-part2.pdf
// euler path - a path that uses every edge of the graph exactly once

void eulerPath(int start) {
    stack<int> stk;

    stk.push(start);

    int x;
    bool flag;
    while (!stk.empty()) {
        x = stk.top();

        flag = false;
        for (int i = 0; i < N; ++i) {
            if (adj_matrix[x][i]) {
                flag = true;
                stk.push(i);
                adj_matrix[x][i] = 0;
                break;
            }
        }

        if (!flag) {
            // add this node to the path
            // eulerPath.pb(x);

            stk.pop();
        }
    }
}