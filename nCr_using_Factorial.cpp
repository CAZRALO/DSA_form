int fact[1000005];
int inv[1000005];
unsigned long long binpow(unsigned long long a,unsigned long long b,unsigned long long  mod) {
    a%=mod;
    unsigned long long  res=1;
    while (b) {
        if (b&1) {
            res=(res*a)%mod;
        }
        a=(a*a)%mod;
        b>>=1;
    }
    return res;
}

void preprocess(int n) {
    fact[0] = inv[0] = 1;
    for (int i = 1; i <= n; ++i) {
        fact[i] = (fact[i - 1] * i) % MOD;
        inv[i] = binpow(fact[i], MOD - 2, MOD);
    }
}

int nCr(int n,int r) {
    if (n<r) return 0;
    return (fact[n]*inv[r]%MOD)*inv[n-r]%MOD;
}
