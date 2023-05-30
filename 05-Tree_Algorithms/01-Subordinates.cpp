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

int dfs(vector<vector<int>>& adj, int v, int p,vector<int>& ans)
{
    for(auto u : adj[v])
     { if(u != p)
        ans[v] += 1 + dfs(adj, u,v,ans);
     }
  return ans[v];   
}

void solve(){
    int n;
   cin>>n;
   vector<vector<int>> adj(n+1);
   vector<int> ans(n+1,0);
   for(int i=2; i<=n; i++)
   {
     int x;
     cin>>x;
     adj[i].push_back(x);
     adj[x].push_back(i);  
   }
   dfs(adj,1,0,ans);
   for(int i=1; i<=n; i++)
   {
    cout<<ans[i]<<" ";
   }
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