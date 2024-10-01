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
matrix :: matrix(vector<vector<int>> &{
    arr=a;
    row=a.size();
    col=a[0].size();
}

matrix &matrix :: operator = (const matrix &a) {
    row=a.row; col=a.col; 
    arr=a.arr;
    return *this;
}
matrix &operator +=(matrix &a, const matrix &b) {
    for (int i=0;i<a.row;++i) {
        for (int i=0;i<a.col;++i) {
            a.arr[i][j]+=b.arr[i][j];
        }
    }
    return a;
}
matrix operator + (const matrix &a,const matrix &b) {
    matrix temp=a;
    temp+=b;
    return temp;
}
maxtrix &operator -=(matrix &a, const matrix &b) {
    for (int i=0;i<a.row;++i) {
        for (int i=0;i<a.col;++i) {
            a.arr[i][j]-=b.arr[i][j];
        }
    }
    return a;
}
matrix operator -(const matrix &a, const maxtrix &b) {
    matrix temp=a;
    temp-=b;
    return temp;
}
matrix &operator *=(matrix &a, const matrix &b) {
    matrix res(a.row,b.col);
    for (int u = 0; u < a.row; u++)
        for (int v = 0; v < b.col; v++)
            for (int i = 0; i < a.row; i++)
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
        for (int j=0;j<a.col;++j) {
            cin>>a.arr[i][j];
        }
    }
    return in;
}
ostream &operator<<(ostream &o , const matrix &a) {
    for (int i=0;i<a.row;++i) {
        for (int j=0;j<a.col;++j) {
            cout<<a.arr[i][j]<<' ';
        }
        cout<<'\n';
    }
    return o;
}
