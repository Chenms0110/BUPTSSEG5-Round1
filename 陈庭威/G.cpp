#include<iostream>
#include<algorithm>
using namespace std;
int n;
int a[105];
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	cin>>a[i];
	sort(a+1,a+1+n);
	int sum=0;
	for(int i=1;i<=n;i+=2)
	{
		int k=abs(a[i]-a[i+1]);
		sum+=k;
	}
	cout<<sum;
}
