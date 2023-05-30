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
    ll n,x;
    read(n);
    ll max_sum = LLONG_MIN,sum=LLONG_MIN;
    F_OR(i,0,n,1)
    {
        cin>>x;
        sum = (sum == LLONG_MIN) ? x : sum +x;
        if(sum < x){
            sum =x;
        }
        max_sum = max(max_sum, sum);

    }
 cout<<max_sum;
    
    
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
