#include<bits/stdc++.h>
using namespace std;

#define ll long long
const ll inf = INT_MAX;

ll dp[1000001];
void solve()
{
   int n,x;
   cin>>n>>x;
   int coins[n];
   for(int i=0; i<n; i++)
   { cin>>coins[i]; }

   dp[0]=0;
   
    for(int i=1; i<=x; i++)
    {
        dp[i]=inf;
        for(int j=0; j<n; j++)
          if(i - coins[j] >=0)
          { dp[i] = min(dp[i], 1+ dp[i - coins[j]]); } 
    }


   if(dp[x] >= inf) cout<<-1;
   else cout<<dp[x];

}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    solve();
    return 0;
}