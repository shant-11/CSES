#include<bits/stdc++.h>
using namespace std;

#define ll long long

#define ar array
#define vt vector
#define pb push_back
#define all(x) x.begin(), x.end()
#define F first
#define S second

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

long long dfs(vt<vt<char>> &grid, vt<vt<ll>> &dp, int i, int j){
    if(i >= (int) grid.size() || j >= (int) grid[0].size())
     return 0;
    if(grid[i][j]=='*') return dp[i][j] =0;
    if(dp[i][j] != -1) return dp[i][j];
    if( (i == (int)grid.size()-1) && (j == (int)grid[0].size()-1) ) return dp[i][j] = 1;
    
    ll right=0, down=0;
    right = dfs(grid, dp, i+1, j)%md;
    down = dfs(grid, dp, i, j+1)%md;

    dp[i][j] = (right + down)%md;

    return dp[i][j];
}
void solve(){
   int n; cin>>n;
   vt<vt<char>> grid(n,vt<char>(n));
   for(int i=0; i<n; i++)read(grid[i]);

   vt<vt<ll>> dp(n, vt<ll>(n, -1));
   dfs(grid, dp, 0, 0);

   cout<<dp[0][0];
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