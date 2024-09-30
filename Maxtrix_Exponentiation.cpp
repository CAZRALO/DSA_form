class matrix {
  int n,m;
  vector<vector<int>>val;
public:
  matrix(int n_, int m_) {
      n=n_; m=m_;
  }
  maxtrix(vector<vector<int>>a) {
      val=a;
      n=val.size();
      m=val[0].size();
  }
  matrix operator * ( const matrix & x) {
      matrix res(n,x.m);
      for (int u = 0; u < a.n; u++)
          for (int v = 0; v < b.m; v++)
              for (int i = 0; i < a.m; i++)
                  res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % MOD;
    return res;
  }
};
