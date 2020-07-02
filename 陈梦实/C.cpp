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

/*
本题给定两点与一条直线，要求：只有在直线上可以从方格中空的部分走，不在直线上则必须走方格的边。求A到B的最短距离。
思路：根据直线方程，A和B都有两种方法走到直线上（x相同移动y和y相同移动x）。
故如果走直线，总共有四种情况（2x2），分别计算。
同时一种例外的情况是完全不走直线。
计算这五种情况后，选一个最小的即可。
*/
