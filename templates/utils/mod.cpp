using ll = long long;

const int MOD = 1e9 + 7;

#define mul_mod(a, b, m) ((((a) % (m)) * ((b) % (m))) % (m))
#define add_mod(a, b, m) ((((a) % (m)) + ((b) % (m))) % (m))
#define sub_mod(a, b, m) ((((a) % (m)) - ((b) % (m)) + m) % (m))

ll pow_mod(ll b, ll p, int m) {
    ll res = 1;
    b %= m;
    while (p > 0) {
        if (p & 1)
            res = res * b % m;
        b = b * b % m;
        p >>= 1;
    }
    return res;
}
ll inv_mod(ll x) {
    return pow_mod(x, MOD - 2, MOD);
}
ll div_mod(ll x, ll y) {
    return ((x % MOD) * inv_mod(y)) % MOD;
}
