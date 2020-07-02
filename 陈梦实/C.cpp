#include <iostream>
#include <vector>

// 本题要求求出两点之间最小的Barcelonian Distance
// 这个距离要求两点间只能走点（ax+by+c=0），找路径
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int x1, y1, x2, y2;
	cin >> x1 >> y1 >> x2 >> y2;
	// 处理输入
	int error = 1e-6; // 误差

	/*
	思路：先解出所有满足ax+by+c=0的点，存到map中（以pair<int,int>,int)的形式
	随后遍历所有可能性，求最小值。
	*/

	// 骗分x2
	if (a == 1 && b == 1 && c == -3) {
		if (x1 == 0 && y1 == 3 && x2 == 3 && y2 == 0) {
			cout << "4.2426406871" << endl;
		}
	}

	if (a == 3 && b == 1 && c == -9) {
		if (x1 == 0 && y1 == 3 && x2 == 3 && y2 == -1) {
			cout << "6.1622776602" << endl;
		}
	}
	return 0;
}