#include <bits/stdc++.h>
using namespace std;

int main()
{
    //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    int a[110];
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
    }
    sort(a+1,a+n+1);

    int ans=0;
    for(int i=1;i<n;i=i+2)
    {
        ans+=abs(a[i]-a[i+1]);
    }
    cout<<ans;
    return 0;
}
