/*
    -> ref: 1. https://codeforces.com/blog/entry/63823
            2. https://github.com/kth-competitive-programming/kactl/blob/master/content/data-structures/LineContainer.h

    -> utility for applying the Convex Hull Trick
    -> 'add' line (y = mx + c), 'query' for max. value
    -> for min., add line as (-m,-c) and get ans as -query()
    -> O(logn)
*/

struct Line {
    mutable ll m, c, p;
    bool operator<(const Line &o) const { return m < o.m; }
    bool operator<(ll x) const { return p < x; }
};

struct LineContainer : multiset<Line, less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const ll inf = LLONG_MAX;

    ll div(ll a, ll b) {
        // floored division
        return a / b - ((a ^ b) < 0 && a % b);
    }

    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if (x->m == y->m) {
            x->p = x->c > y->c ? inf : -inf;
        } else {
            x->p = div(y->c - x->c, x->m - y->m);
        }
        return x->p >= y->p;
    }

    void add(ll m, ll c) {
        auto z = insert({m, c, 0}), y = z++, x = y;
        while (isect(y, z))
            z = erase(z);
        if (x != begin() && isect(--x, y))
            isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p)
            isect(x, erase(y));
    }

    ll query(ll x) {
        assert(!empty());
        auto l = *lower_bound(x);
        return l.m * x + l.c;
    }
};