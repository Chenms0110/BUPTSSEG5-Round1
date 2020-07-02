#define F
#ifdef F
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
/*F题*/

struct Node {
    int x;
    int y;
    Node(int x,int y):x(x),y(y){}
};


int main() {
    //思路：对包含物品的这些点的坐标进行排序，机器人按照顺序移动到这些点上取得物品
    //如果有一个物品需要机器人向左或向下移动，则结果为NO
    //移动时，先右移再上移

    //可以取得所有物品的条件:在排序之后的数组中，对于任意相邻位置的两个点A和B, A.x<=B.x && A.y<=B.y
    return 0;
}
#endif