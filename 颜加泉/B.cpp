#include<cstdio>
#include<algorithm>

//#include<bits/stdc++.h>
using namespace std;
const int maxn = 1005;

void  init() {
	
}


int main() {
	int d, n, m;
	int c[maxn];
	int ans[maxn];
	memset(ans, 0, sizeof(ans));
	scanf_s("%d%d%d",&n,&m,&d);
	int sum = 0;
	c[0] = 1;
	for (int i = 1; i <= m; i++) {
		scanf_s("%d",&c[i]);
		sum += c[i];
	}
	int cha = n - sum;//算出有多少长度的空位
	if (cha == 0) {

	}
	if ((double)cha / (m + 1.0) > d - 1) {//如果平均空位大于每步的距离，说明不可能，输出NO
		printf_s("NO\n");
		return 0;
	}
	int in = cha / (m + 1) ;//计算平均每段空格可以放多长的空格
	int ex = cha % (m + 1);//计算平均分配后，多出的部分
	int index = 0;
	while(index<n+1) {//
		int xxx = in;
		ans[index] = index + in+1;//加上平均的空格，下一个就是要发的平台的位置
		
		if (ex > 0) {//如果有多余部分，空格长度可以加一
			ex--;
			ans[index]++;
			xxx++;
		}
		if(index<m)index =index+xxx +c[index + 1];//更新index
		else {
			index = index + xxx + 1;
		}
	}
	int res[maxn] = { 0 };
	//这里是由于存ans的方法有问题，不符合答案的要求，所以用res进行一个转换
	int no = 1;
	for (int i = 0; i < n; i++) {
		if (ans[i] != 0) { 
			
			int ind = 0;
			while (c[no]-->0) {
				res[ans[i]+ind] = no;
				ind++;
			}	 
			no++;
		}
	}
	printf_s("YES\n");
	for (int i =1; i <=n; i++) {
		printf_s("%d", res[i]);
	}

	return 0;
}