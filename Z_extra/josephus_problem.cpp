/*
    ref: https://cp-algorithms.com/others/josephus_problem.html
*/

int josephus(int n, int k) { // n -> size, k -> jump size
    int res = 0;
    for (int i = 1; i <= n; ++i)
        res = (res + k) % i;

    return res + 1;
}
