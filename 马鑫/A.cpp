//VS2017运行环境，需要加此头文件
#include "pch.h"

/*
	测试A
*/
//#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

//定义a与p数组
int a[105], p[105];
//克隆a数组
int b[105];
//存储结果的数组
bool res_bool[101] = { false };
//定义测试的输两
int t, m, n;

int start_ind, end_ind;

void Increase_find(int *a, int *p, int ind)
{

	int i, j, k;
	//排序成功的标注位
	int flag = 0;

	for (i = 1; i <= n; i++)
	{
		if (a[i] == b[i])
			continue;

		//查找a与b中对应元素的位置
		for (j = 1; j <= n; j++)
		{
			if (b[j] != a[i])
			{
				continue;
			}
			else
			{
				if (j > i)
				{
					start_ind = i;
					end_ind = j;
				}
				else
				{
					start_ind = j;
					end_ind = i;
				}
			}
		}

		for (k = start_ind; k < end_ind; k++)
		{
			if (binary_search(p + 1, p + n + 1, k))
				continue;
			else
				break;
		}
		if (k == end_ind)
		{
			res_bool[ind] = true;
			return;
		}
	}

	if (i == n)
	{
		res_bool[ind] = true;
		return;
	}
}

int main()
{
	int i, j;

	//memset(res_bool, false, 101);

	cin >> t;

	for (i = 0; i < t; i++)
	{
		cin >> n >> m;
		for (j = 1; j <= n; j++)
		{
			cin >> a[j];
			b[j] = a[j];
		}

		for (j = 1; j <= m; j++)
		{
			cin >> p[j];
		}

		sort(b + 1, b + n + 1);

		Increase_find(a, p, i);
	}

	//输出结果
	for (i = 0; i < t; i++)
	{
		if (res_bool[i])
		{
			cout << "YES" << endl;
		}
		else
		{
			cout << "NO" << endl;
		}
	}

	return 0;
}