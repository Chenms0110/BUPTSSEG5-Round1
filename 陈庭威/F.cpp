#include<iostream>
#include<algorithm>
#include<string.h>
#include<queue>
using namespace std;
typedef struct Node{
	int x;
	int y;
	int c;
};
queue<Node> Q;
void DFS(int x,int y,int a,int sum);
void finish();
int t;
int n[1005];
int maxx[105];
int maxy[105];
int map[105][1005][1005];
int mark[105][1005][1005];
char dir[105][1005][1005];
int main()
{
	cin>>t;
	memset(map,0,sizeof(map));
	for(int i=1;i<=t;i++)
	{
		
		maxx[i]=0;
		maxy[i]=0;
		cin>>n[i];
		for(int j=0;j<n[i];j++)
		{
			int x,y;
			cin>>x;
			cin>>y;
			if(x>maxx[i])
			maxx[i]=x;
			if(y>maxy[i])
			maxy[i]=y;
			map[i][x][y]=1;
		}
		 
	}
	/*
	for(int i=1;i<=t;i++)
	{
		
		for(int j=0;j<=20;j++)
		{
			for(int k=0;k<=20;k++)
			cout<<map[i][j][k];
			cout<<endl;
		}
		 cout<<endl;
	}
	*/
	for(int i=1;i<=t;i++)
	{
		
		mark[i][0][0]=1;
		DFS(0,0,i,0);//方法选的不对,应该用BFS的 
	} 
	for(int i=1;i<=t;i++)
	{
		while(!Q.empty())
		Q.pop();
		Node node;
		node.x=0;
		node.y=0;
		node.c=0;
	} 
	
}
void DFS(int x,int y,int a,int sum)
{
	//cout<<"x is "<<x<<" y is "<<y<<endl;
	if(x==maxx[a]&&y==maxy[a]&&sum<n[a])
	{
		cout<<"NO"<<endl;
		return;
	}
	if(map[a][x][y]==1)
	sum+=1;
	if(sum==n[a])
	{
		//cout<<a<<":"<<endl;
		finish();
		return;
	}
	
	int direction[2][2]={1,0,0,1};
	for(int i=0;i<2;i++ )
	{
		int nextx=x+direction[i][0];
		int nexty=y+direction[i][1];
		if(nextx>maxx[a]+1||nextx<0||nexty>maxy[a]+1||nexty<0)
		continue;
		if(mark[a][nextx][nexty]==0)
		{
			if(i==0)
			dir[a][nextx][nexty]='R';
			else
			dir[a][nextx][nexty]='D';
			mark[a][nextx][nexty]=1;
			DFS(nextx,nexty,a,sum);
			mark[a][nextx][nexty]=0;
		}
	}
	
	
}
void finish()
{
	cout<<"YES"<<endl;
}
void  BFS(int a)
{
	while(!Q.empty())
	{
		Node node;
		node=Q.front();
		Q.pop();
		int x=node.x;
		int y=node.y;
		int c=node.c;
	}
	
}
