#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
#define ll long long
const long long md=1000000007;

#define F_OR(i, a, b, s) for (int i=(a); (s)>0?i<(b):i>(b); i+=(s))
#define EACH(x, a) for (auto& x:a)

template<class T> void read(T& x){
      cin>>x;
}
template<class A> void read(vt<A>& x){
      EACH(a, x)
         read(a);
}

void solve()
{
    ll n; read(n);
    vt<ll> p(n); read(p);    
    sort(p.begin(), p.end());
    ll len;
    if(n&1)
    len = p[(n-1)/2];
    else{
        len = ( p[n/2] + p[(n/2)-1] )/2;
    }
    ll res=0;
    F_OR(i,0,n,1){
       res += abs(len-p[i]);
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

    solve();

    return 0;
}
