#include <iostream>
#include <vector>

// 任意铺三个板子（顺序不能变），问是否能跳跃到河对岸
// 与以前做过的题类似（一段距离，每个落点上标记了下一跳可以跳跃的长度）

using namespace std;

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    // n : 河的宽度
    // m : 板子数目
    // d : 最远跳跃距离
    vector<int> banks; // 记录板子长度
    int temp;
    int banks_sum = 0;
    // 板子长度输入（同时计算总长）
    for (int i = 0; i < m; i++) {
        cin >> temp;
        banks.push_back(temp);
        banks_sum += temp;
    }
    // 开始处理（每次找最远跳跃距离，如果到最后最远跳跃距离覆盖了重点，则能够跳跃过去）
    int pos = 0;     // 起始位置
    int end = n + 1; // 终点
    for (int i = 0; i < m; i++) {
        pos += d;    // 跳！
        pos += banks[i] - 1; // 到这块木板的最右侧
    }
    // 此时已经到达了最后一块木板的最右侧，此时有可能：
    // 1：已经超过终点； 2：尚未到达终点
    // 此时还可以再跳一次。
    pos += d;
    if (pos >= end) { // 如果最远距离超过终点，说明可以到达
        cout << "YES" << endl;

        vector<int> ans(n, 0); // 模拟河面
        int now = 0;           // 当前位置
        // 对应每一块木板进行铺设
        for (int i = 0; i < m; i++) {
            int left = end - 1 - banks_sum; // 判断剩余距离
            if (now + d - 1 <= left) now += d; //如果从当前位置跳最远距离不超过剩余距离，则从该位置开始铺设木板
            else now = left + 1; // 反之，则说明剩余距离的任何位置都能到达，从剩余距离的右边一个开始铺
            // 铺设
            for (int j = now - 1; j < now + banks[i] - 1; j++) { // 对于河面，now现在的坐标实际是从1开始计数的，而河面是从0开始，所以要=1
                ans[j] = i + 1;
            }
            banks_sum -= banks[i]; // 更新剩余木板总长
            now += banks[i] - 1;   // 更新位置（到已铺设模板的最右）
        }

        // 所有模板铺设完毕，输出河面
        for (int i = 0; i < ans.size(); i++) {
            std::cout << ans[i] << " ";
        }

        cout << endl;
    }
    else { // 仍然无法到达终点，GG。
        cout << "NO" << endl;
    }
    return 0;
}
