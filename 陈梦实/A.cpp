#include <iostream>
#include <map>
#include <vector>

using namespace std;


int main() {
	int t; // 用例数
	while (cin >> t) {
		for (int round = 0; round < t; round++) {
			int n, m; // n是a数组的长度，m是p数组的长度
			map<int, int> p, hash;
			cin >> n >> m;
			vector<int> a;
			int temp;
			for (int i = 0; i < n; i++) {
				cin >> temp;
				a.push_back(temp);
			}
			for (int i = 0; i < m; i++) {
				cin >> temp;
				if (p.find(temp) == p.end()) {
					p[temp] = 1;
				}
			}
			// 完成输入接受
			// 开始处理（进行冒泡排序并记录每一次交换位置，随后与p数组进行比对）
			for (int i = 0; i < a.size(); i++) {
				for (int j = 0; j < a.size() - 1; j++) {
					if (a[j] > a[j + 1]) {
						int temp = a[j + 1];
						a[j + 1] = a[j];
						a[j] = temp;
						if (hash.find(j + 1) == hash.end()) {
							hash[j + 1] = 1;
						}
					}
				}
			}
			// 冒泡结束，开始比对交换位置
			bool flag = false;
			for (auto i : hash) {
				if (p.find(i.first) == p.end()) {
					flag = true;
				}
			}
			if (flag) {
				cout << "NO" << endl;
			}
			else {
				cout << "YES" << endl;
			}
		}
	}

	return 0;
}

/*
思路：冒泡排序，记录发生交换的位置（map），与输入比较，输出结果。
*/
