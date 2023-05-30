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

const int mxN = 1e3;
char mp[mxN][mxN];
bool vis[mxN][mxN];

void dfs(int i, int j, int n, int m){
    vis[i][j] =true;

    for(int k=0; k<4; k++){
        int r = i + d4i[k];
        int c = j + d4j[k];
        if(r>=0 && r<n && c>=0 && c<m){
            if(mp[r][c]=='.' && !vis[r][c])
            dfs(r,c,n,m);
        }
    }
}
void solve(){
   int n,m; read(n,m);
   F_OR(i,0,n,1){
    F_OR(j,0,m,1){
        read(mp[i][j]);
        vis[i][j]= false;
    }
   }
   int res=0;
   F_OR(i,0,n,1){
    F_OR(j,0,m,1){
        if(mp[i][j] == '.' && !vis[i][j]){
            dfs(i,j,n,m);
            res++;
        }
    }
   }
  cout<<res;
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