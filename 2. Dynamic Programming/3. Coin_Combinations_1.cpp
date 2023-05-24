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
template<class H, class... T> void read(H& h, T&... t) {
	read(h);
	read(t...);
}
template<class A> void read(vt<A>& x){
      EACH(a, x)
         read(a);
}

int dp[1000001];
void solve()
{
    int n,x;
    read(n,x);
    vt<int> coins(n);
    read(coins);
    dp[0]=1;
    F_OR(i,1,x+1,1){
        dp[i]=0;
        EACH(c,coins){
            if(i - c >= 0)
               dp[i] = ( dp[i] + dp[i-c] ) % md;
        }
    }
    cout<<dp[x];   
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
   #endif

    solve();

}