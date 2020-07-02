#include <bits/stdc++.h>
using namespace std;
int a[110],b[110],p[110];
bool compare(int a[],int b[],int n)
{
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
int main()
{
    //ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int flag=1;
        fill(p,p+110,0);
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=n;i++)
        {
            cin>>a[i];
            b[i]=a[i];
        }
        sort(b+1,b+1+n);
        int t;
        for(int i=1;i<=m;i++)
        {
            cin>>t;
            p[t]=1;
        }


        for(int i=1;i<n;i++)
        {
            if(a[i]>a[i+1])
            {
                if(p[i]==0)
                {
                    flag=0;
                }
                else
                    swap(a[i],a[i+1]);

            }
        }
        if(!compare(a,b,n))
            flag=0;


        if(flag)
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }

    return 0;
}
