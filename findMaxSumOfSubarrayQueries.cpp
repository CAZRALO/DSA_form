// find  max sum of subarray from u to v (Q query for u,v) 

#include <bits/stdc++.h>

using namespace std;

template<typename... T> void see(T&... args) { ((cin >> args), ...);}
template<typename... T> void put(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void putl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
#define int long long
#define st first
#define nd second
#define eb(x) emplace_back(x)
#define pb(x) push_back(x)
#define all(a) bg(a),end(a)
#define rall(a) a.rbegin(),a.rend()
#define sz(a) (int) a.size()
#define rsz resize
#define ins insert
#define fu(i,a,b) for(int i=a;i<=b;++i)

struct Node {
	int val,idx;
};

struct TNode {
	int startIdxTotal,startIdxPrefix,startIdxSuffix,startIdxMaxSum;
	int endIdxTotal,endIdxPrefixendIdxSuffix,endIdxMaxSum;
	int totalSum,prefixSum,suffixSum,maxSum;
};

const int inf=1e18;
Node A[200005],n,Q;
TNode Seg[4*200000+5];

TNode combine(TNode &a,TNode &b) {
	TNode ans;
  //ternary operator 
	//combine sum
	ans.totalSum=a.totalSum+b.totalSum;
	ans.prefixSum=max(a.prefixSum,a.totalSum+b.prefixSum);
	ans.suffixSum=max(b.suffixSum,a.suffixSum+b.totalSum);
	ans.maxSum=max({a.maxSum,b.maxSum,a.suffixSum+b.prefixSum});
	//init index start; 
	ans.startIdxTotal=a.startIdxTotal;
	ans.startIdxPrefix=a.startIdxPrefix;
	ans.startIdxSuffix=(b.suffixSum>a.suffixSum+b.totalSum)?b.startIdxSuffix:a.startIdxSuffix;
	ans.startIdxMaxSum=(a.maxSum>b.maxSum)?((a.maxSum>a.suffixSum+b.prefixSum)?a.startIdxMaxSum:a.startIdxSuffix)
	:((b.maxSum>a.suffixSum+b.prefixSum)?b.startIdxMaxSum:a.startIdxSuffix);
  //init index end 
	ans.endIdxTotal=a.endIdxTotal;
	ans.endIdxPrefix=(a.prefixSum>a.totalSum+b.prefixSum)?a.endIdxPrefix:b.endIdxPrefix;
	ans.endIdxSuffix=endIdxSuffix;
	ans.endIdxMaxSum=(a.maxSum>b.maxSum)?((a.maxSum>a.suffixSum+b.prefixSum)?a.endIdxMaxSum:b.endIdxPrefix)
	:((b.maxSum>a.suffixSum+b.prefixSum)?b.endIdxMaxSum:b.endIdxPrefix);
  /*// if else 
  ans.startIdxPrefix=a.startIdxPrefix;
  if (a.prefixSum>a.totalSum+b.prefixSum) { 
    ans.prefixSum=a.prefixSum;
    ans.endIdxPrefix=a.endIdxPrefix;
  } else {
    ans.prefixSum=a.totalSum+b.prefixSum;
    ans.endIdxPrefix=b.endIdxPrefix;
  }
  ans.endIdxSuffix=b.endIdxSuffix;
  if (b.suffixSum>a.suffixSum+b.totalSum) {
    ans.startIdxSuffix=b.startIdxSuffix;
    ans.suffixSum=b.suffixSum;
  }
  else {
    ans.startIdxSuffix=a.startIdxSuffix;
    ans.suffixSum=a.suffixSum+b.totalSum;
  }
  if (a.maxSum >= b.maxSum && a.maxSum>=a.suffixSum+b.prefixSum) {
    res.maxSum=a.maxSum;
    res.startIdxMaxSum=a.startIdxMaxSum;
    res.endIdxMaxSum=a.endIdxMaxSum;
  } else if (b.maxSum >= a.maxSum && b.maxSum >= a.suffixSum+b.prefixSum) {
    res.maxSum=b.maxSum;
    res.startIdxMaxSum=b.startIdxMaxSum;
    res.endIdxMaxSum=b.endIdxMaxSum;
  } else {
    res.maxSum=a.suffixSum+b.prefixSum;
    res.startIdxMaxSum=a.startIdxSuffix;
    res.endIdxMaxSum=b.endIdxPrefix;
  }*/
	return ans;
}

TNode makeTNode(Node a){
	TNode ans;
	ans.totalSum=ans.prefixSum=ans.suffixSum=ans.maxSum=a.val;
  ans.startIdxTotal=ans.startIdxPrefix=ans.startIdxSuffix=ans.startIdxMaxSum
  =ans.endIdxTotal=ans.endIdxPrefix=ans.endIdxSuffix=ans.endIdxMaxSum =a.idx;
	return ans;
}

void build(int id,int l,int r) {
	if (l>r) return;
	if (l==r) {
		Seg[id]=makeTNode(A[l]);
		return;
	}
	int mid=(l+r)>>1;
	build(id<<1,l,mid);
	build(id<<1|1,mid+1,r);
	Seg[id]=combine(Seg[id<<1],Seg[id<<1|1]);
}

void update(int id,int l,int r,int pos,int val) {
	if (l>pos || r<pos) return;
	if (l==r) {
		A[pos]=val;
		Seg[id]=makeTNode(A[l]);
		return;
	}
	int mid=(l+r)>>1;
	update(id<<1,l,mid,pos,val);
	update(id<<1|1,mid+1,r,pos,val);
	Seg[id]=combine(Seg[id<<1],Seg[id<<1|1]);
}

TNode getMax(int id,int l,int r,int u,int v) {
	if (u>r||v<l) return makeTNode({-inf,-1});
	if (u<=l && r<=v) return Seg[id];
	int mid=(l+r)>>1;
	TNode temp1=getMax(id<<1,l,mid,u,v);
	TNode temp2=getMax(id<<1|1,mid+1,r,u,v);
	return combine(temp1,temp2);
}

int getMax(int u,int v) {
	TNode ans=getMax(1,1,n,u,v);
  return ans.maxSum;
}

void solve() {
	see(n);
	fu(i,1,n) { see(A[i].val); A[i].idx=i; }
	build(1,1,n);
	see(Q);
	while (Q--) {
		int type;
		see(type);
		if (type==1) {
			int pos,val;
			see(pos,val);
			update(1,1,n,pos,val);
		} else {
			int u,v;
			see(u,v);
			int res=getMax(u,v);
			cout<<res<<'\n';
		}
	}
}
signed main(signed argc, char *argv[]) {
    cin.tie(0)->sync_with_stdio(0);
	  solve();
    return 0;
}
