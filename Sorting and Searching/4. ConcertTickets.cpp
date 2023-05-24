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
    int n,m;
    read(n); read(m);
    set<pair<int,int>> h;
    vt<int> t(m);
    int tmp;
    F_OR(i,0,n,1)
    {
        cin>>tmp;
        h.insert({tmp,i});
    }
     read(t);
    
    F_OR(i,0,m,1)
    {
      auto it = h.lower_bound({t[i],0});
      //cout<<it->first<<" "<<it->second<<endl;
      if(it->first == t[i])
      {
        cout<<it->first<<endl;
        h.erase(it);
      } 
      else if( it == h.begin())
      cout<<-1<<endl;
      else
      {
        it--;
        cout<<it->first<<endl;
        h.erase(it);
      }
    }

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
