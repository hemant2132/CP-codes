// snippet from -> https://www.hackerearth.com/challenges/college/knuth-cup-2018-qualifiers/algorithm/amusement-parks/submission/36239111/

const int N = 2e3 + 10;

int tree[4 * N][4 * N];

int val;

void updateY(int nodex, int begx, int enx, int node, int beg, int en, int y) {
    if (beg == en) {
        if (begx == enx) {
            tree[nodex][node] = val;
        } else {
            tree[nodex][node] = tree[2 * nodex][node] + tree[2 * nodex + 1][node];
        }

        return;
    }

    int mid = (beg + en) / 2;

    if (beg <= y && y <= mid) {
        updateY(nodex, begx, enx, 2 * node, beg, mid, y);
    } else {
        updateY(nodex, begx, enx, 2 * node + 1, mid + 1, en, y);
    }

    tree[nodex][node] = tree[nodex][2 * node] + tree[nodex][2 * node + 1];
}

void updateX(int node, int beg, int en, int x, int y) {
    if (beg != en) {
        int mid = (beg + en) / 2;

        if (beg <= x && x <= mid) {
            updateX(2 * node, beg, mid, x, y);
        } else {
            updateX(2 * node + 1, mid + 1, en, x, y);
        }
    }

    updateY(node, beg, en, 1, 0, N, y);
}

int queryY(int nodex, int node, int beg, int en, int l, int r) {
    if (r < beg || en < l) return 0;
    if (l <= beg && en <= r) return tree[nodex][node];

    int mid = (beg + en) / 2;
    int a = queryY(nodex, 2 * node, beg, mid, l, r);
    int b = queryY(nodex, 2 * node + 1, mid + 1, en, l, r);

    return a + b;
}

int queryX(int node, int beg, int en, int lx, int rx, int ly, int ry) {
    if (rx < beg || en < lx) return 0;
    if (lx <= beg && en <= rx) return quy(node, 1, 0, N, ly, ry);

    int mid = (beg + en) / 2;
    int a = queryX(2 * node, beg, mid, lx, rx, ly, ry);
    int b = queryX(2 * node + 1, mid + 1, en, lx, rx, ly, ry);

    return a + b;
}