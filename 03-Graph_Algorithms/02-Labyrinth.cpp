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
char c[mxN][mxN];
pair<int,int> prv[mxN][mxN];
bool vis[mxN][mxN], flag;
pair<int, int> s,e;
vector<pair<int, int>> path;
queue<pair<int,int>> q;

void bfs(int& n, int&m){
    q.push(s);
    vis[s.first][s.second]= true;
    while(!q.empty()){
        auto p = q.front(); q.pop();
        
        for(int i=0; i<4; i++){
            int nr = p.first + d4i[i];
            int nc = p.second + d4j[i];
            if(nr >=0 && nr<n && nc>=0 && nc<m){
                if( !vis[nr][nc] && (c[nr][nc]=='.' || c[nr][nc]=='B') ){
                    vis[nr][nc]=true;
                    q.push({nr,nc});
                    prv[nr][nc]= p;
                }
                if(c[nr][nc]=='B'){
                   flag = true;
                   e = {nr,nc};
                   return;
                }
            }
        }
    }
}

void displayPath(){
    cout<<"YES"<<'\n';
    for(auto at = e; at != s ; at = prv[at.first][at.second]){
        path.pb(at);
    }
    cout<<path.size()<<'\n';
    pair<int, int> from = s;
    auto rit = path.rbegin();
    while(rit != path.rend()){
        if(rit->second != from.second){
           cout<<(rit->second > from.second ? 'R' : 'L');
        }
        else{
           cout<<(rit->first > from.first ? 'D' : 'U');
        }
        from = *(rit);
        rit++;
    }
}

void solve(){
   memset(vis, false, sizeof(vis));
   flag = false;
   int n,m; read(n,m);
   F_OR(i,0,n,1){
    F_OR(j,0,m,1){
        cin>>c[i][j];

        if(c[i][j]=='A')
         s = {i,j};
    }
   }
   bfs(n,m);
   if(!flag)cout<<"NO";
   else{
    displayPath();
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