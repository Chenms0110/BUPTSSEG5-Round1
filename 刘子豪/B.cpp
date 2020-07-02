#define B
#ifdef B
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
/*B题*/

const int maxn = 105;

//以pos位置为起点，放置平台plat[i]，返回平台尾端的位置
int putPlat(vector<int>& ans, vector<int>& plat, int i,int pos) {
    int platlength = plat[i];
    int p;
    for (p = 0; p < platlength; p++) {
        ans[p + pos] = i + 1;
    }
    return p + pos - 1;
}

int main() {
    //贪心法
    //最极限的放平台方法：每个平台之间相隔的距离均为d，如果这样放做不到，那么最后结果为NO

    //输入数据
    int n, m, d;
    cin >> n >> m >> d;
    vector<int> plat;
    for (int i = 0; i < m; i++) {
        int temp;
        cin >> temp;
        plat.push_back(temp);
    }

    //1 首先，判断是否存在可行的放平台方法
    //可行时的条件：间隔数*(d-1)+平台长度之和>=n，其中间隔数=平台数+1
    int sum = 0;
    for (int p : plat) {
        sum += p;
    }
    if ((m + 1)*(d - 1) + sum >= n) {
        cout << "YES" << endl;

        //2 输出一个合适的平台方法
        //其中关键是平台间间隔大小的分配要平均
        int seanum = n - sum;
        int intervalnum = m + 1;
        int t1 = seanum / intervalnum;
        int t2 = seanum % intervalnum;

        vector<int> ans(n, 0);
        int p = -1;
        for (int i = 1; i <= m; i++) {
            //先空几个位置，再放平台plat[i-1]
            int interval_length = t1;
            if (i <= t2)
                interval_length++;
            p += interval_length + 1;
            p = putPlat(ans, plat, i - 1, p);
        }

        //放置完成，输出最后结果
        for (int i : ans) {
            cout << i << " ";
        }
        cout << endl;
    }
    else {
        cout << "NO" << endl;
    }

    return 0;
}
#endif