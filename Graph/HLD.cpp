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
    void update(int p,int val){ 
        for (st[p+=n]=val; p > 1; p>>=1) st[p>>1]=st[p]+st[p^1];
    }
    long long query(int l,int r) {
        int res = 0;
        for (l+=n,r+=n+1; l < r; l>>=1,r>>=1){
            if (l&1) res+=st[l++];
            if (r&1) res+=st[--r];
        }
        return res;
    }
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
