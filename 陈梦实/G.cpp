#include <iostream>
#include <vector>
#include <algorithm>

// 本题给出一个数组（偶数个元素），两两组队，目标值为所有队伍间元素的差值和。
// 要求该差值和最小，
using namespace std;

int main() {
	int n; // 学生数
	while (cin >> n) {
		vector<int> a; // skill of the i-th student
		int temp;
		for (int i = 0; i < n; i++) {
			cin >> temp;
			a.push_back(temp);
		}
		// 处理所有input完毕

		// 排序，随后取每两个数字的差值，所有差值加和即为答案（最小）
		sort(a.begin(), a.end());
		int ans = 0;
		for (int i = 1; i < n;) {
			ans += a[i] - a[i - 1];
			i += 2;
		}
		cout << ans << endl;
	}
	return 0;
}
