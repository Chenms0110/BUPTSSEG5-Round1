#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
// 本题要求从左下到最右上的包裹，只在右移和上移的情况下找到一条路径
// 如果这种路径有多条，则按照“lexicographically”规则找到最小路
// 这个规则是字符串标准比较法：第一个不同的字符，比较其ascii值
// 因为R的ascii值小于U，所以：能先往右的时候就先往右走

using namespace std;

// 位置信息
struct position {
    int x;
    int y;
    position() {
        x = 0;
        y = 0;
    }
};

// 对于包裹，排序应该先按左右顺序，再按下上顺序
// 用于第一次sort，x轴的排序（升序）
bool cmpx(position& p1, position& p2) {
    if (p1.x < p2.x) {
        return true;
    }
    else {
        return false;
    }
}
// 用于第二次sort，y轴的排序（升序）
bool cmpy(position& p1, position& p2) {
    if (p1.y < p2.y) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int t; // 用例数
    while (cin >> t) {
        for (int iii = 0; iii < t; iii++) {
            int n; // 包裹数
            cin >> n;
            vector<position> packages;
            for (int i = 0; i < n; i++) {
                position a;
                cin >> a.x >> a.y;
                packages.push_back(a);
            }
            // 所有包裹输入完毕

            // 两次排序，越靠近左下的包裹优先级越高
            sort(packages.begin(), packages.end(), cmpx);
            sort(packages.begin(), packages.end(), cmpy);

            // 对于每个包裹，先走右，再走上
            string ans;   // 路径
            position now; // 机器人位置
            int i;
            for (i = 0; i < n; i++) {
                ;
                position target = packages[i]; // 获取下一个目标
                // 如果下一个目标在当前位置的左侧或下侧，说明找不到题目要求路径
                if (now.x > target.x || now.y > target.y) {
                    cout << "NO" << endl; // GG
                    break;
                }
                // 先走右
                while (now.x < target.x) {
                    now.x += 1;
                    ans += "R";
                }
                // 后走上
                while (now.y < target.y) {
                    now.y += 1;
                    ans += "U";
                }
                // 到达了目标位置，获得一个包裹，开始获取下一个包裹
            }
            if (i == n) { // 如果取得了所有包裹
                cout << "YES" << endl;
                cout << ans << endl; // 输出路径
            }
        }
    }
    return 0;
}
