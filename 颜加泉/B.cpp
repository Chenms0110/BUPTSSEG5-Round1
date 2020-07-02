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
	int cha = n - sum;//算出有多少空位
	if (cha == 0) {

	}
	if ((double)cha / (m + 1.0) > d - 1) {
		printf_s("NO\n");
		return 0;
	}
	int in = cha / (m + 1) ;
	int ex = cha % (m + 1);
	int index = 0;
	while(index<n+1) {
		int xxx = in;
		ans[index] = index + in+1;
		
		if (ex > 0) {
			ex--;
			ans[index]++;
			xxx++;
		}
		if(index<m)index =index+xxx +c[index + 1];
		else {
			index = index + xxx + 1;
		}
	}
	int res[maxn] = { 0 };

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