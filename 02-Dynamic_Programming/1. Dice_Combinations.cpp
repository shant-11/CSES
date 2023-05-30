#include<bits/stdc++.h>
using namespace std;
const long long md = 1000000007;

int dp[1000001];
void solve()
{
   int n;
   cin>>n;
   dp[0]=0;
   for(int i=1; i<=6; i++)
   {
    dp[i] = 1;
     for(int j=i-1; j>0; j--)
     dp[i] += dp[j];
   }
   
   if(n > 6)
   {
    for(int i=7; i<=n; i++)
    {
        dp[i]=0;
        for(int j=1; j<=6; j++)
          dp[i] = ( (dp[i] % md) + (dp[i-j] % md) ) % md; 
    }
   }

   cout<<dp[n];

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
