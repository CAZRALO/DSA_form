{
  string a,b;
  int n = a.size(), m = b.size();
  for (int i = 0; i < n ; ++i) power1[i] = (power1[i-1] * base) % MOD1;
  for (int i = 0; i < m ; ++i) power2[i] = (power2[i-1] * base) % MOD2;
  for (int i = 0; i < n ; ++i) hash1[i] = (hash1[i-1] * base + a[i] - 'a' + 1) % MOD1;
  for (int i = 0; i < m ; ++i) hash2[i] = (hash2[i-1] * base + b[i] - 'a' + 1) % MOD2;
}
