#include <bits/stdc++.h>
#define ios ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define bit(x,j) ((x>>j)&1)
using namespace std;

ll int mod=1e9+7;
int mul(ll int x, ll int y)
{
    return (x * 1ll * y) % mod;
}

int add(int x, int y)
{
    x += y;
    while(x >= mod) x -= mod;
    while(x < 0) x += mod;
    return x;
}

long long power(long long a, long long b,ll m) {
    a %= m;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = mul(res,a);
        a = mul(a,a);
        b >>= 1;
    }
    return res%m;
    }


  ll int binomial(ll int n, ll int k) 
{ 
    ll int C[k+1]; 
    memset(C, 0, sizeof(C)); 
  
    C[0] = 1; 
  
    for (ll int i = 1; i <= n; i++) 
    { 

        for (int j = min(i, k); j > 0; j--) 
            C[j] = C[j]+C[j-1]; 
    } 
    return C[k]; 
} 
  vector<int> pr;
  bool prime[10000000];
void Sieve(ll int n) 
{ 
    memset(prime, true, sizeof(prime)); 
    prime[1]=false;
  
    for (int p=2; p*p<=n; p++) 
    { 
        if (prime[p] == true) 
        { 
            pr.push_back(p);
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        } 
    } 
}
 



pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}
int sum(int n)  
{  
    if (n == 0)  
    return 0;  
    return (n % 10 + sum(n / 10));  
}  
ll int factorial(ll int n,ll int m) 
{ 
    ll int fact = 1; 
    for(int i=2;i<=n;i++) { 
        fact = (fact * i)%m; 
    } 
    return fact%m; 
} 

int reduce(int x, int y) 
{ 
    int d; 
    d = __gcd(x, y); 
  
    x = x / d; 
    y = y / d; 
    return x; 
} 


int main() {
  ios;
  ll int n;
  cin>>n;
  double s;
  cin>>s;
  map<int,int>mp,ma;
  for(int i=0;i<n-1;i++)
  {
      int a,b;
      cin>>a>>b;
      mp[a]++;
      mp[b]++;
  }
  ll int l=0;
   for(int i=1;i<=n;i++)
   {
       if(mp[i]==1)
       l++;
   }

   long long k=2*(s)/(double)l;
   std::cout << std::setprecision(9) << k << '\n';
}