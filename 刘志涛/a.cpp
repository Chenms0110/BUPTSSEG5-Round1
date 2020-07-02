#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t,m,n;
	int a[1000];
	int b[1000];
	cin>>t;
	while(t--)
	{	int q=0;
		cin>>m>>n;
		
		for(int i=1;i<=m;i++)
		{
			cin>>a[i];
		 } 
		 for(int j=1;j<=n;j++)
		 {
		 	cin>>b[j];
		 	if(a[b[j]]>a[b[j]+1])
		 	{
		 	     int tmp=0;
		 	     tmp=a[b[j]];
		     	a[b[j]]=a[b[j]+1];
		     	a[b[j]+1]=tmp;
			 }
		 
		 }
		 
		 for(int c=1;c<n;c++)
		 {
		 	if(a[b[c]]>a[b[c]+1])
		 {
		 	int pm=0;
		 	pm=a[b[1]];
		 	a[b[1]]=a[b[1]+1];
		 	a[b[1]+1]=pm;
		 }
		 }
		 
		 for(int i=1;i<m;i++)
		 {    
		 	if(a[i]>a[i+1])
		 	{
		 	     q=1;
			} 
		 }
		 if(q==1)
		 {
		 	cout<<"NO"<<endl;
		 	
		 }
		else
		{
			cout<<"YES"<<endl;
		}
		 
	}
 } 
