#include <bits/stdc++.h> // header file includes every Standard library
using namespace std;
long long getSum(long long seg[],long long lazy[],long long low,long long high,long long l,long long r,long long i){
	if(lazy[i]!=0){
		seg[i]=(seg[i]+((high-low+1)*lazy[i])%1000000007)%1000000007;
		if(low!=high){
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(low>high || low>r || high<l){
		return 0;
	}
	if(low>=l && high<=r){
		return seg[i];
	}
	long long mid=low+(high-low)/2;
	return (getSum(seg,lazy,low,mid,l,r,2*i+1)+getSum(seg,lazy,mid+1,high,l,r,2*i+2))%1000000007;
}
void update(long long seg[],long long lazy[],long long low,long long high,long long l,long long r,long long i,long long value){
	if(lazy[i]!=0){
		seg[i]=(seg[i]+((high-low+1)*lazy[i])%1000000007)%1000000007;
		if(low!=high){
			lazy[2*i+1]+=lazy[i];
			lazy[2*i+2]+=lazy[i];
		}
		lazy[i]=0;
	}
	if(low>high || low>r || high<l){
		return;
	}
	if(low>=l && high<=r){
		seg[i]=(seg[i]+((high-low+1)*value)%1000000007)%1000000007;
		if(low!=high){
			lazy[2*i+1]+=value;
			lazy[2*i+2]+=value;
		}
		return;
	}
	long long mid=low+(high-low)/2;
	update(seg,lazy,low,mid,l,r,2*i+1,value);
	update(seg,lazy,mid+1,high,l,r,2*i+2,value);
	seg[i]=(seg[2*i+1]+seg[2*i+2])%1000000007;
	return;
}
void build(long long seg[],long long arr[],long long low,long long high,long long i){
	if(low==high){
		seg[i]=arr[low];
		return;
	}
	long long mid=low+(high-low)/2;
	build(seg,arr,low,mid,2*i+1);
	build(seg,arr,mid+1,high,2*i+2);
	seg[i]=(seg[2*i+1]+seg[2*i+2])%1000000007;
	return;
}
int main() {
	long long n,q;
	cin>>n>>q;
	long long arr[n];
	for(long long i=0;i<n;i++){
		cin>>arr[i];
	}
	long long seg[4*n];long long lazy[4*n];
	for(long long i=0;i<4*n;i++){
		lazy[i]=0;
		seg[i]=0;
	}
	build(seg,arr,0,n-1,0);
	while(q--){
		int type;
		cin>>type;
		if(type==1){
			long long l,r,x;
			cin>>l>>r>>x;
			update(seg,lazy,0,n-1,l-1,r-1,0,x);
		}
		else{
			long long l,r;
			cin>>l>>r;
			cout<<getSum(seg,lazy,0,n-1,l-1,r-1,0)<<endl;
		}
	}

	// Your code here
	return 0;
}