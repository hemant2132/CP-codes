// mod operations
void mod(int &x, int p = MOD) { x %= p; x += p; x %= p; }
inline int add(int a, int b, int p = MOD) { a = a + b; if (a >= p) a -= p; return a; }
inline int sub(int a, int b, int p = MOD) { a = a - b; if (a < 0) a += p; return a; }
inline int mul(int a, int b, int p = MOD) { a = (a * 1ll * b) % p; return a; }
