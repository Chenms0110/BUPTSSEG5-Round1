#include <iostream>
#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;//N的上限

vector<int> maps[maxn];
int w[maxn];
int visit[maxn] = { 0 };


int main()
{
	int n;
	cin >> n;
	for (int i = 1;i <= n;++i)
		cin >> w[i];
	//输入边
	int x, y;
	//建图
	for (int i = 0;i <= n;++i)
	{
		cin >> x >> y;
		maps[x].push_back(y);
		maps[y].push_back(x);
	}
	//然后广搜记录距离
	for (int i = 0;i < n;++i)
	{
		
	}

	system("pause");
	return 0;
}