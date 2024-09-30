const int maxn=1e3+5;

struct matrix {
  int val[maxn][maxn];
  matrix() {
    memset(val, 0, sizeof(val));  
  }
  matrix operator * ( const matrix & x) {
    matrix res;
    for (int u = 0; u < 2; u++)
      for (int v = 0; v < 2; v++)
        for (int i = 0; i < 2; i++)
          res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % MOD;
    return res;
  }
};
