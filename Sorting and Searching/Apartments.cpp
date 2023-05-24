#include <bits/stdc++.h>
using namespace std;

void solve(int n, int m, int k, int a[], int b[])
{
    sort(a, a+n);  sort(b, b+m);
    
    int i=0, j=0, count=0;
    while(i<n && j<m)
    {
      if(b[j]-k <= a[i] && a[i] <= b[j]+k)
      {
        count++;
        i++;
        j++;
      }
      else if(a[i] < b[j]-k)
      {
        i++;
      }
      else
      j++;
    }

    cout<<count;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    int n,m,k;
    cin>>n;
    cin>>m;
    cin>>k;

    int a[n],b[m];

    for(int i=0; i<n; i++)
    { cin>>a[i];}

    for(int i=0; i<m; i++)
    { cin>>b[i];}

    solve(n,m,k, a,b);

    return 0;
}