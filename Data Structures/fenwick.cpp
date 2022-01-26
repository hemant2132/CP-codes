/*
    -> Fenwick Tree

    -> range queries and point update in O(logN)
    -> works for reversible functions
    -> current implementation follows 1-based indexing
    -> fenwick[i] = sumOfRange(i - LSB(i) + 1, i)
    -> (x & -x) gives LSB of x
*/

int fenwick[N];

void update(int ind, int val) {
    while (ind <= n) {
        fenwick[ind] += val;
        ind += ind & -ind;
    }
}

int pref(int ind) {
    int res = 0;
    while (ind > 0) {
        res += fenwick[ind];
        ind -= ind & -ind;
    }

    return res;
}

int query(int l, int r) {
  if (l > r) return 0;
  return pref(r) - pref(l - 1);
}
