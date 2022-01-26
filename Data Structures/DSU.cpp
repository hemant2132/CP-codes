/*
    -> Disjoint Set Union

    ->  operations (both achieved in nearly constant time):
        1. merge two sets
        2. find set of an element

    -> ref:
        1. https://www.hackerearth.com/practice/data-structures/disjoint-data-strutures/basics-of-disjoint-data-structures/tutorial/
        2. https://cp-algorithms.com/data_structures/disjoint_set_union.html
*/

vector<int> parent(N), siz(N);

void init(int n) {
    for (int i = 1; i <= n; ++i) {
        parent[i] = i;
        siz[i] = 1;
    }
}

// path compression
int root(int x) {
    while (parent[x] != x) {
        parent[x] = parent[parent[x]];
        x = parent[x];
    }

    return x;
}

// weighted union
bool uni(int a, int b) {
    int x = root(a);
    int y = root(b);

    if (x == y) return false;

    if (siz[x] < siz[y]) swap(x, y);

    parent[y] = x;
    siz[x] += siz[y];

    return true;
}
