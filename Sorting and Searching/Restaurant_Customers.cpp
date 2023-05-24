#include<bits/stdc++.h>
using namespace std;

#define vt vector
#define pb push_back

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
    int n;
    read(n);
    vector<pair<int,int>> v;
    int a,b;
    F_OR(i,0,n,1)
    {
        cin>>a>>b;
        v.pb({a,1});
        v.pb({b,-1});
    }
    sort(v.begin(),v.end());
    int count=0, max_count=0;
    EACH(x,v)
    {
       count+= x.second;
       max_count = max(max_count,count);
    }
    cout<<max_count;
    
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

   // int t=1;
   // read(t);
   // while(t--)
   // {
        solve();
    //} 
    return 0;
}