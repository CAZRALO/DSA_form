struct RollingHash{
    string a;
    int MOD1 = 1e9+7;
    int MOD2 = 1e9+9;
    int base = 131;
    vector<int> hash1,power1,hash2,power2;
    RollingHash(string &s, int _n) : hash1(_n+1,0), power1(_n+1,1), hash2(_n+1,0), power2(_n+1,1), a(s) {
        int n = s.size();
        power1[0] = power2[0] = 1;
        for (int i = 1; i <= n ; ++i) {
            power1[i] = (power1[i-1] * base) % MOD1;
            power2[i] = (power2[i-1] * base) % MOD2;
            hash1[i] = (hash1[i-1] * base + a[i-1]-'a'+1) % MOD1;
            hash2[i] = (hash2[i-1] * base + a[i-1]-'a'+1) % MOD2;
        }
    }
    int getHash1(int l, int r) {
        return (hash1[r+1]-hash1[l]*power1[r-l+1]%MOD1+MOD1)%MOD1;
    }
    int getHash2(int l, int r) {
        return (hash2[r+1]-hash2[l]*power2[r-l+1]%MOD2+MOD2)%MOD2;
    }
};
