#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back
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
    int n,x;
    read(n); read(x);
    int val;
    unordered_map<int,int> mp;
    F_OR(i,1,n+1,1)
    {
        cin>>val;
        if(val >= x)
        continue;
        if(mp.find(x-val) != mp.end()){
            cout<<mp[x-val]<<" "<<i;
            return;
        }
        mp[val]=i;
    }
    cout<<"IMPOSSIBLE";
    
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
