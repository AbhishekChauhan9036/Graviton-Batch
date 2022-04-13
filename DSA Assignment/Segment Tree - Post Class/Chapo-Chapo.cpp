#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define B           200
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,a[100005],b[100005],presa[100005],presb[100005];
vii extra;
void calc_pre(){
    rep(i,1,n+1) presa[i]=a[i]+presa[i-1];
    rep(i,1,n+1) presb[i]=b[i]+presb[i-1];
}
void solve(){
    cin>>n>>q;
    rep(i,1,n+1){
        cin>>a[i];
        b[i]=a[i]*i;
    }
    calc_pre();
    while(q--){
        int ty;
        cin>>ty;
        if(ty==1){
            int pos,x;
            cin>>pos>>x;
            extra.insert(lower_bound(all(extra),make_pair(pos,x)),{pos,x});
            if(sz(extra)>B){
                for(auto i:extra){
                    a[i.x]+=i.y;
                    b[i.x]+=i.y*i.x;
                }
                calc_pre();
                extra.clear();
            }
        }
        else{
            int y;
            cin>>y;
            int d=sqrt(y);
            vi v(2*d+(d!=y/d));
            for(int j=1;j*j<=y;j++){
                v[j-1]=y/j;
                v[sz(v)-j-1]=y/(y/j);
            }
            v.back()=0;
            int res=0,pos=0;
            for(auto i:v){
                int l=min(n+1,y/(i+1)+1),r=min(n,(i?y/i:n));
                if(l>n) break;
                pii w={presa[r]-presa[l-1],presb[r]-presb[l-1]};
                while(pos<sz(extra) and extra[pos].x<=r){
                    w.x+=extra[pos].y; 
                    w.y+=extra[pos].x*extra[pos].y;
                    pos++;
                }
                res+=w.x*y-w.y*i;
            }
            cout<<res<<endl;
        }
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}