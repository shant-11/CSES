#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define EACH(x, a) for (auto& x:a)

template<class T> void read(T& x){
    cin>>x;
}
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x){
    EACH(a, x)
      read(a);
}
template<class A, size_t S> void read(ar<A, S>& x) {
	EACH(a, x)
		read(a);
}

const ll md=1000000007;
const int d4i[4]={-1, 0, 1, 0}, d4j[4] = {0, 1, 0, -1};

const int mxN=1e3+1;
int h[mxN], s[mxN];
int dp[mxN][100001];

void solve(){
   int n,x; read(n,x);
   F_OR(i,1,n+1,1){
    cin>>h[i];
   }
   F_OR(i,1,n+1,1){
    cin>>s[i];
   }
   F_OR(i,0,n+1,1){
    F_OR(j,0,x+1,1){
        if(i==0 || j==0)
          dp[i][j]=0;
        else{
            int ans1 = dp[i-1][j];
            int ans2 = (j < h[i] ? 0 : s[i] + dp[i-1][j - h[i]]);
            dp[i][j]= max(ans1 , ans2);
        }
    }
   }
   cout<<dp[n][x];
}


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    int t=1;
    //read(t);
    while(t--){
        solve();
    }
    
}