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
long long mult(long long a, long long b)
{
    long long res = 0;
    a= a%md;
    while(b)
    {
        if(b&1) res = (res%md + a%md)%md;
        a = (a*2)%md;
        b= b/2; 
    }

    return res%md;
}
void solve()
{
    int n;
    read(n); 
    vt<pair<int,int>> intervals;
    int a,b;
    F_OR(i,0,n,1)
    {
        cin>>a>>b;
        intervals.pb({a,b});
    }
    sort(intervals.begin(), intervals.end());
    pair<int,int> prev(0,0);
    int count=0;
    for(int i=0; i<n; i++)
    {
      auto curr = intervals[i];
      if(curr.first < prev.second)
      {
        if(curr.second < prev.second)
        prev = curr;

        continue;
      }
      count++;
      prev = curr;
    
    }
    cout<<count;
    
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