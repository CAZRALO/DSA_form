class matrix {
  int n,m;
  vector<vector<int>>arr;
public:
  matrix(int n_, int m_) ;
  matrix(vector<vector<int>> &a) {}
  friend matrix &operator = (const matrix &);
  friend matrix &operator +=(matrix&,  const matrix &);
  friend matrix operator + (const matrix &,const matrix &);
  friend maxtrix &operator -=(matrix &, const matrix &);
  friend matrix operator -(const matrix &, const maxtrix b);
  friend matrix &operator *=(matrix &, const matrix &);
  friend matrix operator  * (const matrix &, const matrix &); 
  //read and write matrix
  friend &ostream operator<<(ostream &, const matrix &);
  friend &istream operator>>(isteam &, matrix &);
};

matrix :: matrix(int n_,int m) {
    n=n_; m=m_;
}
matrix :: matrix(vector<vector<int>> &a {
    arr=a;
    n=a.size();
    m=a[0].size();
}

matrix &operator = (const matrix &a) {
    n=a.n; m=a.m; 
    arr=a.arr;
    return *this;
}
matrix &operator +=(matrix &a, const matrix &b) {
    
}
matrix operator + (const matrix &a,const matrix &b) {
    matrix temp=a;
    temp+=b;
    return temp;
}
maxtrix &operator -=(matrix &a, const matrix &b) {
  
}
matrix operator -(const matrix &a, const maxtrix &b) {
    matrix temp=a;
    temp-=b;
    return temp;
}
matrix &operator *=(matrix &a, const matrix &b) {
  
    matrix res(n,x.m);
    for (int u = 0; u < a.n; u++)
        for (int v = 0; v < b.m; v++)
            for (int i = 0; i < a.m; i++)
                res.val[u][v] = ((ll)val[u][i] * x.val[i][v] + res.val[u][v] ) % MOD;
  return res;
}
matrix operator  * (const matrix &a, const matrix &b) {
    matrix temp;
    temp=a;
    temp*=b;
    return temp;
}
istream &operator>>(istream &in, matrix &a) {
    in>>a.n>>a.m;
    for (int i=0;i<a.n;++i) {
    }

    return i;
}
ostream &operator<<(ostream & , const matrix &a) {
    for (int i=0;i<a.n;++i) {
    }
    return o;
}
