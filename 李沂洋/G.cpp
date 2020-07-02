#include <iostream>
#include <bits/stdc++.h>
#define maxn 110
#define LL long long
using namespace std;
int stu[maxn];
int visit[maxn] = { 0 };
int n;
int min1 = 110;//最小
int key1 = 0;
int min2 = 110;
int key2 = 0;
void findMinIndex()
{
	for (int i = 0;i <n;++i)
		if (stu[i] <min1 && !visit[i])
		{
			min1 = stu[i];
			key1 = i;
		}
	visit[key1] = 1;
	for (int i = 0;i <n;++i)
		if (stu[i] <min2 && !visit[i])
		{
			min2 = stu[i];
			key2 = i;
		}
	visit[key2] = 1;
}
int main()
{

	cin >> n;
	for (int i = 0;i < n;++i)
		cin >> stu[i];
	int x = n / 2;
	int num = 0;
	while (x--)
	{
		findMinIndex();
		num += (min2 - min1);
		min1 = 110;//最小
		key1 = 0;
		min2 = 110;
		key2 = 0;
	}
	cout << num << endl;
	system("pause");
	return 0;
}