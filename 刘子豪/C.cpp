#define C
#ifdef C
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;
/*C题*/


double minDistance(int a, int b, int c, int x1, int x2, int y1, int y2) {
    //边界数据1：当x1=x2或y1=y2时，最短路径一定不用走avenue
    if (x1 == x2) {
        return abs(y1 - y2);
    }
    if (y1 == y2) {
        return abs(x1 - x2);
    }

    //边界数据2：当a与b中的某一项为0，那么最短路径一定不用走avenue
    if (a == 0 || b == 0) {
        return abs(y1 - y2) + abs(x1 - x2);
    }

    //一般情况下，将A点B点作为对角点画一个矩形，可以根据avenue与矩形边的交点进行讨论
    //有两个交点时，根据交点所在的边不同，有6种情况，其中4种情况下可以通过走斜线得到更短的距离

    return 0;
}

int main() {
    //如果不走斜线的话最短的距离恒为abs(x1-x2)+abs(y1-y2)
    int a, b, c;
    cin >> a >> b >> c;
    int x1, x2, y1, y2;
    cin >> x1 >> x2 >> y1 >> y2;
    double ans = minDistance(a, b, c, x1, x2, y1, y2);
    cout << ans << endl;
    return 0;
}
#endif