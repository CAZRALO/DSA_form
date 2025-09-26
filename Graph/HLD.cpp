const int MAXN = 200005;
int n, q;
vector<int> adj[MAXN];
int parent[MAXN], depth[MAXN], heavy[MAXN], head[MAXN], pos[MAXN];
int subtree[MAXN];
int cur_pos = 0;
int a[MAXN]; // giá trị ban đầu trên đỉnh

// --- Segment Tree ---
struct SegTree {
    int n;
    vector<long long> st;
    SegTree(int n=0) {init(n);}
    void init(int n_) {
        n=n_;
        st.assign(4*n,0);
    }
    void update(int id,int l,int r,int p,int val){
        if(l==r){ st[id]=val; return; }
        int mid=(l+r)/2;
        if(p<=mid) update(id*2,l,mid,p,val);
        else update(id*2+1,mid+1,r,p,val);
        st[id]=st[id*2]+st[id*2+1];
    }
    void update(int p,int val){ update(1,1,n,p,val); }
    long long query(int id,int l,int r,int u,int v){
        if(u>r||v<l) return 0;
        if(u<=l&&r<=v) return st[id];
        int mid=(l+r)/2;
        return query(id*2,l,mid,u,v)+query(id*2+1,mid+1,r,u,v);
    }
    long long query(int l,int r){ return query(1,1,n,l,r); }
} seg;

// --- DFS1: tính size + heavy child ---
int dfs(int u,int p){
    parent[u]=p;
    subtree[u]=1;
    int maxsz=0;
    for(int v:adj[u]) if(v!=p){
        depth[v]=depth[u]+1;
        int sz=dfs(v,u);
        subtree[u]+=sz;
        if(sz>maxsz){ maxsz=sz; heavy[u]=v; }
    }
    return subtree[u];
}

// --- DFS2: gán head, pos ---
void decompose(int u,int h){
    head[u]=h;
    pos[u]=++cur_pos;
    if(heavy[u]!=-1) decompose(heavy[u],h);
    for(int v:adj[u]) if(v!=parent[u] && v!=heavy[u]){
        decompose(v,v);
    }
}

// --- query trên đường u-v ---
long long queryPath(int u,int v){
    long long res=0;
    while(head[u]!=head[v]){
        if(depth[head[u]]<depth[head[v]]) swap(u,v);
        res+=seg.query(pos[head[u]],pos[u]);
        u=parent[head[u]];
    }
    if(depth[u]>depth[v]) swap(u,v);
    res+=seg.query(pos[u],pos[v]);
    return res;
}

// --- update giá trị tại node u ---
void updateNode(int u,int val){
    seg.update(pos[u],val);
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> q;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<n;i++){
        int u,v; cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    memset(heavy,-1,sizeof(heavy));
    depth[1]=0;
    dfs(1,0);
    decompose(1,1);

    seg.init(n);
    for(int i=1;i<=n;i++) seg.update(pos[i],a[i]);

    while(q--){
        int type; cin>>type;
        if(type==1){ // update
            int u,val; cin>>u>>val;
            updateNode(u,val);
        }else{ // query path
            int u,v; cin>>u>>v;
            cout<<queryPath(u,v)<<"\n";
        }
    }
}
