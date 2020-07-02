#include <bits/stdc++.h>
using namespace std;
const int N=10000;
const int inf=1e9;
int n;
int d[N],g[N][N],weight[N];
bool vis[N]={false};
void bfs(int s)
{
    queue<int>q;
    q.push(s);
    d[s]=0;
    while(!q.empty())
    {
        int f=q.front();
        vis[f]=true;
        q.pop();
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==false&&g[f][i])
            {
                q.push(i);
                d[i]=d[f]+1;
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>weight[i];
    }
    int x,y;
    fill(g[0],g[0]+N*N,0);
    for(int i=0;i<n-1;i++)
    {
        cin>>x>>y;
        g[x][y]=g[y][x]=1;
    }
    int maxx=0;

    for(int i=1;i<=n;i++)
    {
        fill(vis,vis+N,false);
        bfs(i);
        int value=0;
        for(int j=1;j<=n;j++)
        {
            value+=d[j]*weight[j];
        }
        if(value>maxx)
            maxx=value;

    }
    cout<<maxx;


    return 0;
}
