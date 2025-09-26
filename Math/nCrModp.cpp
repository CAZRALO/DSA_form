// caculate nCr % p using Fermat little theorem 
const unsigned MOD=1e9+7;
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


unsigned long long nCr(unsigned long long  n,unsigned long long  k) {
    if (k>n) return 0;
    if (k==0) return 1;
    if (n-k<k) {
        return nCr(n,n-k);
    }
    unsigned long long res=1;
    for (int i=k;i>=1;--i) {
        res=res*(n-i+1)%MOD;
        res=res*(1ull*binpow(i,MOD-2,MOD))%MOD;
    }
    return res;
}
