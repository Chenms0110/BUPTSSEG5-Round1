#include <iostream>
#include <vector>

// 分析题意：给出一个数组a和一些区间。
// 应用一个区间：将数组该区间位置的元素全部减一。

// 题目要求：给出一个数组和一些区间，应用这些区间使得数组的最大值和最小值的差值最大。
// 输出三行：
// 1：可能的最大的最大值与最小值差值的数值
// 2：应用了多少个区间来达到这个差值？
// 3：位置

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m) {
		vector<int> a;
		vector<pair<int, int>> q;
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		int l, j;
		for (int i = 0; i < m; i++) {
			cin >> l >> j;
			q.push_back(make_pair(l, j));
		}
		// 处理所有input完成

	}

	return 0;
}