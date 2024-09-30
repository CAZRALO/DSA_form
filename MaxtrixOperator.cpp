#define int long long
const int MOD=1e9+7;

class matrix {
  int row,col;
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
    row=n_; col=m_;
}
matrix :: matrix(vector<vector<int>> &a {
    arr=a;
    row=a.size();
    col=a[0].size();
}

matrix &operator = (const matrix &a) {
    row=a.n; col=a.m; 
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
    matrix res(a.row,b.col);
    for (int u = 0; u < a.n; u++)
        for (int v = 0; v < b.m; v++)
            for (int i = 0; i < a.m; i++)
                res.arr[u][v] = ((int)arr[u][i] * b.arr[i][v] + res.arr[u][v] ) % MOD;
    a=res;
    return a;
}
matrix operator  * (const matrix &a, const matrix &b) {
    matrix temp;
    temp=a;
    temp*=b;
    return temp;
}
istream &operator>>(istream &in, matrix &a) {
    in>>a.row>>a.col;
    for (int i=0;i<a.row;++i) {
        for (int i=0;i<a.col;++i {
            cin>>a.arr[i][j];
        }
    }
    return i;
}
ostream &operator<<(ostream & , const matrix &a) {
    for (int i=0;i<a.row;++i) {
        for (int i=0;i<a.col;++i) {
            cout<<a.arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    return o;
}
