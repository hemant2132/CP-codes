/*
    -> snippet from solution of https://www.spoj.com/problems/XMAX/
    -> ref: 1. https://codeforces.com/blog/entry/68953
            2. https://math.stackexchange.com/questions/48682/maximization-with-xor-operator
*/

const int N = 63;

int basis[N];
int cnt = 0;

void insrt(int n) {
    for (int i = N - 1; i >= 0; --i) {
        if (!(n & (1ll << i)))
            continue;

        if (!basis[i]) {
            basis[i] = n;
            break;
        }

        n ^= basis[i];
    }
}

void solve() {
    mem(basis, 0);

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        int x;
        cin >> x;
        insrt(x);
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (!basis[i])
            continue;

        if (ans & (1ll << i))
            continue;

        ans ^= basis[i];
    }

    cout << ans;
}
