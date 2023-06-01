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

const int mxN = 1e5+1;
vt<int> adj[mxN];
bool vis[mxN];
vt<int> tobuild;

void dfs(int v){
    vis[v] = true;

    for(auto u : adj[v]){
        if(!vis[u])
        dfs(u);
    }
}
void solve(){
    int n,m; read(n,m);
    memset(vis,false,sizeof(vis));
    F_OR(i,0,m,1){
        int a,b; read(a,b);
        adj[a].pb(b);
        adj[b].pb(a);
    }
    for(int i=1; i<=n; i++){
        if(!vis[i]){
          dfs(i);
          tobuild.pb(i);
        }
    }
    int k = tobuild.size()-1;
    if(k==0)
    cout<<0;
    else{
        cout<<k<<'\n';
        for(int i=1; i<=k; i++)
         cout<<tobuild[i-1]<<" "<<tobuild[i]<<'\n';

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