/*
    -> Ternary Search
    -> ref: 1. https://cp-algorithms.com/num_methods/ternary_search.html
            2. https://www.hackerearth.com/practice/algorithms/searching/ternary-search/tutorial/
    -> useful for finding local maxima/minima of unimodal functions
    -> for integral end-points: "r - l > 2"
    -> a modified binary search can also be used: https://codeforces.com/blog/entry/11497
*/

double ternarySearch(double beg, double en) {
    double eps = 1e-9;
    while (en - beg > eps) {
        double mid1 = beg + (en - beg) / 3;
        double mid2 = en - (en - beg) / 3;

        double f1 = getVal(mid1);
        double f2 = getVal(mid2);

        if (f1 > f2) { // change (w.r.t maxima/minima)
            beg = mid1;
        } else {
            en = mid2;
        }
    }

    return getVal(beg);
}

// variation...
double ternary_search(double beg, double en) {
    int lim = 200;
    for (int i = 0; i < lim; ++i) {
        double mid1 = beg + (en - beg) / 3;
        double mid2 = en - (en - beg) / 3;

        double f1 = getVal(mid1);
        double f2 = getVal(mid2);

        if (f1 > f2) { // change (w.r.t maxima/minima)
            beg = mid1;
        } else {
            en = mid2;
        }
    }

    return getVal(beg);
}
