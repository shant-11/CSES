#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,x;
    cin>>n>>x;
    int p[n];

    for(int i=0; i<n; i++)
    { cin>>p[i];}

    sort(p, p+n);
    int s=0, e= n-1, count=0;
    while(s <= e)
    {
        if(p[s] + p[e] <= x)
        { s++; e--;}
        else
        { e--;}

        count++;
    }
    cout<<count;

}
int main()
{
  //#ifndef ONLINE_JUDGE
  freopen("input.txt","r",stdin);
  freopen("output.txt","w", stdout);
  //#endif

  solve();
  return 0;   

}