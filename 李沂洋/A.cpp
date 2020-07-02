#include <iostream>
#include <bits/stdc++.h>
#define maxn 110
#define LL long long
using namespace std;
int t;
int n, m;
int a[maxn];
int p[maxn];
int index;
int findMinIndex(int startindex,int endindex)
{
	int min = a[startindex];
	int key = startindex;
	for (int i = startindex + 1;i <= endindex;++i)
		if (a[i] < min)
		{
			min = a[i];
			key = i;
		}
	return key;
}
int main()
{
	
	cin >> t;
	
	while (t--)
	{
		cin >> n >> m;
		for (int i = 0;i < n;++i)
			cin >> a[i];
		for (int i = 0;i < m;++i)
			cin >> p[i];
		//按照从小到大，把a中的每一个元素运到前面
		bool ok = true;
		for (int i = 0;i < n;++i)
		{
			//获取最小元素索引
			index = findMinIndex(i, n - 1);
			if (index == i)
				continue;
			int num = 0;
			//通过计算枢纽数量来判断能否运送过去
			for (int j = 0;j < m;++j)
			{
				if (p[j] - 1 >= i&&p[j] - 1 <= index - 1)
					num++;
			}
			if (num == (index - i))
				ok = true;
			else
			{
				ok = false;
				break;
			}
		}
		if (ok)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
		
	}
	system("pause");
	return 0;
}

/*法二
#include <iostream>
#include <bits/stdc++.h>
#define maxn 110
#define LL long long
using namespace std;
int t;
int n, m;
int a[maxn];
int p[maxn];
int index;
int findMinIndex(int startindex,int endindex)
{
int min = a[startindex];
int key = startindex;
for (int i = startindex + 1;i <= endindex;++i)
if (a[i] < min)
{
min = a[i];
key = i;
}
return key;
}
int main()
{

cin >> t;

while (t--)
{
cin >> n >> m;
for (int i = 0;i < n;++i)
cin >> a[i];
for (int i = 0;i < m;++i)
cin >> p[i];
//按照从小到大，把a中的每一个元素运到前面
for (int i = 0;i < n;++i)
{
//获取最小元素索引
index = findMinIndex(i, n - 1);
//看看能否通过p移动过去
bool itcan = true;
while (index != i&& itcan)
{
bool ok = false;
for (int j = 0;j <m;++j)
{
if (p[j]-1 == index - 1)
{
//交换两个数
int temp = a[index];
a[index] = a[index - 1];
a[index - 1] = temp;
index = index - 1;
ok = true;
break;
}
}
if (ok)
continue;
else
{
itcan = false;
break;
}
}
if (!itcan)
{
cout << "NO" << endl;
break;
}
else {
cout << "YES" << endl;
break;
}


}

}
system("pause");
return 0;
}*/