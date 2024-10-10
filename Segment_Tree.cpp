// O(log(n)) for each query

const int MAXN=1e5+5;
int st[4*MAXN];
int A[MAXN];
int n;

void build (int id, int l, int r ){
    if (l>r) return;
    if (l==r) st[id]=A[l];
    int mid=(l+r)>>1;
    build(id<<1,l,mid);
    build(id<<1|1,mid+1,r);
    st[id]=min(st[id<<1],st[id<<1|1]);
}
//change value of A[pos] to val
void update(int id,int l,int r,int pos, int val) {
    if (l>r || pos<l || pos>r) return;
    if (l==r) {
        A[pos]=val;
        st[id]=val;
        return;
    }
    int mid=(l+r)>>1;
    update(id<<1,l,mid,pos,val);
    update(id<<1|1,mid+1,r,pos,val);
    st[id]=min(st[id<<1],st[id<<1|1]);
}
//get min value from u to v
int get(int id,int l,int r,int u,int v){
    if (u>r || v<l) return INT_MAX; 
    if (u<=l  && r<=v) return st[id];
    int mid=(l+r)>>1;
    return min(get(id<<1,l,mid,u,v),get(id<<1|1,mid+1,r,u,v));
}
