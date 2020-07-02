#define E
#ifdef E
#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cstdlib>
#include <ctime>
using namespace std;
/*E题*/

//对u进行dfs，求出cost, depth表示此时u点所在深度
int dfs(int u, vector<vector<int> >& graph, vector<int>& valtable, int depth, vector<int>& visited) {
    int cost = depth * valtable[u];
    visited[u] = 1;
    for (int v : graph[u]) {
        if(!visited[v])
            cost += dfs(v, graph, valtable, depth + 1, visited);
    }
    
    return cost;
}

int main() {
    //暴力法：遍历树中的每一个点，对于该点V，通过dfs求出cost值，直到找到最大的cost值对应的那个点
    //不成形的贪心法：尽量让值更大的节点与root的距离更远
    int n;
    cin >> n;

    vector<vector<int> > graph(n+1,vector<int>()); //图的邻接表定义
    vector<int> valtable(n+1,0); //存放每个节点的值，可以通过节点的序号查找它的值

    //输入节点的值
    for (int i = 1; i <= n; i++) {
        cin >> valtable[i];
    }
    //输入图的边，建立邻接表
    int u, v;
    for (int i = 0; i < n - 1; i++) {
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    int maxcost = 0;
    for (int i = 1; i <= n; i++) {
        //以每一个点作为root，进行dfs遍历
        vector<int> visited(n + 1, 0);
        maxcost = max(maxcost, dfs(i, graph, valtable, 0, visited));
    }

    cout << maxcost << endl;

}
#endif