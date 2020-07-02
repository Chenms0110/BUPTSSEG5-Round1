#include<iostream>
using namespace std;
int t;
int a[105][105];
int p[105][105];
int m[105];
int n[105];
int main()
{
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		
		cin>>n[i]>>m[i];
		for(int j=1;j<=n[i];j++)
		cin>>a[i][j];
		for(int j=1;j<=m[i];j++)
		cin>>p[i][j];	
	}
	/*
	for(int i=1;i<=t;i++)
	{
		for(int j=1;j<=n[i];j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
	}
	*/
	for(int i=1;i<=t;i++)
	{
		int len=n[i];
		int nump=m[i];
		int f=1;
		while(f)
		{
			f=0;
				for(int j=1;j<=len;j++)//循环每个数组 
			{
				if(a[i][j]>a[i][j+1])
				{
					//cout<<"i "<<i<<" j "<<j<<endl;
					int flag=0;
					for(int k=1;k<=nump;k++)
					{
						if(p[i][k]==j)
						{
							flag=1;
						}
		
					}
					if(flag)
					{
						swap(a[i][j],a[i][j+1]);
						f=1;
					}
					
					
				}
				
				
			}
		}
		/*
		cout<<"a[i]"<<endl;
		for(int j=1;j<=n[i];j++)
		cout<<a[i][j]<<" ";
		cout<<endl;
		*/
	}
	
	for(int i=1;i<=t;i++)
	{
		int flag=1;
		int len=n[i];
		for(int j=1;j<len;j++)
		{
			if(a[i][j]>a[i][j+1])
			{
				flag=0;
				break;
			}
		}
		if(flag)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl; 
	}
}
