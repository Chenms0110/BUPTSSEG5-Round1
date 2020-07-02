#include<cstdio>
#include<algorithm>
#include<iostream>
#include <vector>

//#include<bits/stdc++.h>
using namespace std;
const int maxn = 105;
int p[maxn], a[maxn];
bool is[maxn];
vector<int> temp;
void  init() {
	memset(is,false,sizeof(is));
	memset(p,0,sizeof(p));
	memset(a,0,sizeof(a));
	temp.clear();

}


int main() {
	int t,n,m;
	
	scanf_s("%d", &t);
	while (t--) {
		init();
		int flag = true;
		scanf_s("%d%d",&n,&m);
		for (int i = 1; i <= n; i++) {
			scanf_s("%d", &a[i]);
			temp.emplace_back(a[i]);
		}
		for (int i = 1; i <=m; i++) {
			scanf_s("%d", &p[i]);
			is[p[i]] = true;
		}
		sort(temp.begin(), temp.end());
		for (int i = 1; i <= n; i++) {
			int pos1 = lower_bound(temp.begin(), temp.end(),a[i])-temp.begin();
			int pos2 = upper_bound(temp.begin(), temp.end(), a[i]) - temp.begin();
			int pos = abs(pos1 - i) < abs(pos2 - i) ? pos1 : pos2;
			if (i < pos) {
				for (int j = i;j<pos;j++)
					if (p[j] == false) { printf_s("NO\n"); flag = false; break; }

			}
			else {
				for (int j = pos; j < i; j++)
					if (p[j] == false) { printf_s("NO\n"); flag = false; break; }

			}
			if (flag == false)break;
		}
		if(flag){
		printf_s("YES\n");

		}
	}


	return 0;
}