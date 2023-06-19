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

void solve(){
    int n,m; cin>>n>>m;
    vt<int> val(n+1), pos(n+1);
    for(int i=1; i<=n; i++){
       cin>>val[i];
       pos[val[i]]=i;
    }
    int res=1;
    for(int i=1; i<n; i++){
        if(pos[i] > pos[i+1])res++;
    }

    while(m--){
        int a,b;
        cin>>a>>b;
        if(a > b) swap(a,b);
        set<pair<int, int>> affected;
        if(val[a]-1 >= 1)affected.insert({val[a]-1, val[a]});
        if(val[a]+1 <= n)affected.insert({val[a], val[a]+1});
        if(val[b]-1 >= 1)affected.insert({val[b]-1, val[b]});
        if(val[b]+1 <= n)affected.insert({val[b], val[b]+1});

        for(auto p : affected){
            res -= pos[p.F] > pos[p.S];
        }
        pos[val[a]] = b;
        pos[val[b]] = a;
        swap(val[a], val[b]);
        for(auto p : affected){
            res += pos[p.F] > pos[p.S];
        }
        cout<<res<<'\n';
        affected.clear();
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
   // read(t);
    while(t--){
        solve();
    }
    
}