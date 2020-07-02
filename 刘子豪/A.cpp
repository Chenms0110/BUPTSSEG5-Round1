#define A
#ifdef A
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;
/*A题*/

const int maxn = 105;

int main() {
    //输入t
    int t;
    cin >> t;
    while (t--) {
        //输入用例数据
        int n, m;
        cin >> n >> m;
        vector<int> a;
        set<int> p;
        for (int i = 0; i < n; i++) { //输入数组a的内容
            int temp;
            cin >> temp;
            a.push_back(temp);
        }
        for (int i = 0; i < m; i++) { //输入集合p的内容
            int temp;
            cin >> temp;
            p.insert(temp);
        }

        //对a数组模拟冒泡排序，其中数组元素的交换需要经过p数组的限制
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= i; j++) {
                if (p.find(j) != p.end() && a[j - 1] > a[j]) {
                    //如果p数组允许对[j]与[j-1]进行交换，则进行交换
                    int temp = a[j - 1];
                    a[j - 1] = a[j];
                    a[j] = temp;
                }
            }
        }

        //检查排序之后的a数组是否为不减序列
        bool ans = true;
        int prev = 0;
        for (int a0 : a) {
            if (prev > a0) {
                ans = false;
                break;
            }
            prev = a0;
        }
        if (ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;

    }
}
#endif