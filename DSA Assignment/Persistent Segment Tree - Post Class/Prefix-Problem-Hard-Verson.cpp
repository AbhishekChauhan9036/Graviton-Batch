#include <bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#ifndef rd
#define trace(...)
#define endl '\n'
#endif
#define pb push_back
#define fi first
#define se second
#define int long long
#define Abhishek main
typedef long long ll;
typedef long double f80;
#define double long double
#define pii pair<int,int>
#define pll pair<ll,ll>
#define sz(x) ((long long)x.size())
#define fr(a,b,c) for(int a=b; a<=c; a++)
#define rep(a,b,c) for(int a=b; a<c; a++)
#define trav(a,x) for(auto &a:x)
#define all(con) con.begin(),con.end()
const ll infl=0x3f3f3f3f3f3f3f3fLL;
const int infi=0x3f3f3f3f;
const int mod=1000000007;
typedef vector<int> vi;
typedef vector<ll> vl;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;
auto clk=clock();
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int lim) {
	uniform_int_distribution<int> uid(0,lim-1);
	return uid(rang);
}
int powm(int a, int b) {
	int res=1;
	while(b) {
		if(b&1)
			res=(res*a)%mod;
		a=(a*a)%mod;
		b>>=1;
	}
	return res;
}
int n;
const int N=2e5+5;
int star[4*N][2];
int en[4*N][2];
int val[4*N][2];
int troll[4*N][2],troll2[4*N][2];
bool lazy[4*N];
void apply(int seg) {
	lazy[seg]^=1;
	swap(val[seg][0],val[seg][1]);
	swap(star[seg][0],star[seg][1]);
	swap(en[seg][0],en[seg][1]);
	swap(troll[seg][0],troll[seg][1]);
	swap(troll2[seg][0],troll2[seg][1]);
}
void flip(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return;
	if(l<=ll&&rr<=r) {
		apply(seg);
		return;
	}
	if(lazy[seg]) {
		apply(seg<<1);
		apply(seg<<1|1);
		lazy[seg]=0;
	}
	flip(seg<<1,ll,(ll+rr)/2,l,r);
	flip(seg<<1|1,1+(ll+rr)/2,rr,l,r);
	int left=seg<<1,right=seg<<1|1;
	int lelen=(ll+rr)/2-ll+1,rilen=rr-(ll+rr)/2;
	rep(i,0,2) {
		val[seg][i]=val[left][i]+val[right][i]+en[left][i]*star[right][i];
		if(star[left][i]==lelen)
			star[seg][i]=star[left][i]+star[right][i];
		else
			star[seg][i]=star[left][i];
		if(en[right][i]==rilen)
			en[seg][i]=en[left][i]+en[right][i];
		else
			en[seg][i]=en[right][i];
		troll[seg][i]=max(troll[left][i],troll[right][i]);
		troll2[seg][i]=min(troll2[left][i],troll2[right][i]);
	}
}
pair<int,pii> sum(int seg, int ll, int rr, int l, int r) {
	if(ll>r||l>rr)
		return {0,{0,0}};
	if(l<=ll&&rr<=r)
		return {val[seg][1],{star[seg][1],en[seg][1]}};
	if(lazy[seg]) {
		apply(seg<<1);
		apply(seg<<1|1);
		lazy[seg]=0;
	}
	auto left=sum(seg<<1,ll,(ll+rr)/2,l,r);
	auto right=sum(seg<<1|1,1+(ll+rr)/2,rr,l,r);
	pair<int,pii> comb;
	comb.fi=left.fi+right.fi+left.se.se*right.se.fi;
	int lelen=(ll+rr)/2-ll+1,rilen=rr-(ll+rr)/2;
	if(left.se.fi==lelen)
		comb.se.fi=left.se.fi+right.se.fi;
	else
		comb.se.fi=left.se.fi;
	if(right.se.se==rilen)
		comb.se.se=left.se.se+right.se.se;
	else
		comb.se.se=right.se.se;
	return comb;
}

void build(int seg, int ll, int rr) {
	if(ll==rr) {
		val[seg][0]=1;
		star[seg][0]=1;
		en[seg][0]=1;
		troll[seg][0]=ll;
		troll[seg][1]=0;
		troll2[seg][0]=ll;
		troll2[seg][1]=n+1;
	} else {
		build(seg<<1,ll,(ll+rr)/2);
		build(seg<<1|1,1+(ll+rr)/2,rr);
		int left=seg<<1,right=seg<<1|1;
		int lelen=(ll+rr)/2-ll+1,rilen=rr-(ll+rr)/2;
		rep(i,0,2) {
			val[seg][i]=val[left][i]+val[right][i]+en[left][i]*star[right][i];
			if(star[left][i]==lelen)
				star[seg][i]=star[left][i]+star[right][i];
			else
				star[seg][i]=star[left][i];
			if(en[right][i]==rilen)
				en[seg][i]=en[left][i]+en[right][i];
			else
				en[seg][i]=en[right][i];
			troll[seg][i]=max(troll[left][i],troll[right][i]);
			troll2[seg][i]=min(troll2[left][i],troll2[right][i]);
		}
	}
}
int valafter(int seg, int ll, int rr, int l, int r) {
	if(l>rr||ll>r)
		return 0;
	if(l<=ll&&rr<=r)
		return troll[seg][0];
	if(lazy[seg]) {
		apply(seg<<1);
		apply(seg<<1|1);
		lazy[seg]=0;
	}
	return max(valafter(seg<<1,ll,(ll+rr)/2,l,r),valafter(seg<<1|1,1+(ll+rr)/2,rr,l,r));
}
int valbefore(int seg, int ll, int rr, int l, int r) {
	if(l>rr||ll>r)
		return n+1;
	if(l<=ll&&rr<=r) {
		return troll2[seg][0];
	}
	if(lazy[seg]) {
		apply(seg<<1);
		apply(seg<<1|1);
		lazy[seg]=0;
	}
	return min(valbefore(seg<<1,ll,(ll+rr)/2,l,r),valbefore(seg<<1|1,1+(ll+rr)/2,rr,l,r));
}

void solve() {
	int q;
	cin>>n>>q;
	build(1,1,n);
	fr(i,1,n) {
		int te;
		cin>>te;
		if(te)
			flip(1,1,n,i,i);
	}
	while(q--) {
		int t,l,r;
		cin>>t>>l>>r;
		if(t==1) {
			flip(1,1,n,l,r);
		} else {
			int ans=sum(1,1,n,l,r).fi%mod;
			int bef=l-1-valafter(1,1,n,1,l-1),herebef=min(r+1,valbefore(1,1,n,l,r))-l;
			trace(bef,valbefore(1,1,n,l,r),herebef,aft,hellbef);
			ans=(ans+bef*herebef)%mod;
			cout<<ans<<endl;
		}
	}

}

signed Abhishek() {
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	cout<<fixed<<setprecision(8);
	int t=1;
	fr(i,1,t) {
		solve();
	}
#ifdef rd
	cout<<endl<<endl<<endl<<endl<<"Time elapsed: "<<(double)(clock()-clk)/CLOCKS_PER_SEC<<endl;
#endif
	return 0;
}