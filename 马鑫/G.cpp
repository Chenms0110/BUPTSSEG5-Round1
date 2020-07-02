
//VS2017运行环境，需要加此头文件
//#include "pch.h"


/*
	测试G
*/

//#include <bits/stdc++.h>
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;


int main()
{
	//分别记录学生的数量、每个学生的技能点、技能点之差等信息
	int n, a[101], b = 0;
	//数组索引变量
	int i, j, k;

	cin >> n;
	for (i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	//递增排序
	sort(a + 1, a + n + 1);

	for (j = 1; j < n; )
	{
		b += a[j + 1] - a[j];
		j += 2;
	}

	cout << b << endl;

	return 0;
}