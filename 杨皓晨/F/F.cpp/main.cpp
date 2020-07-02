#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;

int maze[1001][1001];
bool mark[1001][1001];

struct N{
    int x,y;
    char c;
};
queue <N> q;
int go[][2] = {{1,0},{0,1}};

bool BFS(int a,int b,int n){
    int cnt = 0;
    while(q.empty() == false){
        N now = q.front();
        q.pop();
        for(int i = 0;i < 2;i++){
            int nx = now.x + go[i][0];
            int ny = now.y + go[i][1];
            if(nx > a || ny >b){
                continue;
            }
            if(mark[nx][ny] == true){
                continue;
            }
            if(maze[nx][ny] == 0){
                continue;
            }
            N tmp;
            tmp.x = nx;
            tmp.y = ny;
            if(i == 0){
                tmp.c = 'R';
            }
            if(i == 1){
                tmp.c = 'U';
            }
            printf("%c",tmp.c);
            cnt++;
            mark[nx][ny] = true;
            if(cnt == n)
                return true;
            q.push(tmp);
        }
    }
    return false;
}


int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int max_x = 0,max_y = 0;
        int n;
        scanf("%d",&n);
        for(int i = 0;i <= 1001;i++){
            for(int j = 0;j <= 1001;j++){
                maze[i][j] = 0;
                mark[i][j] = false;
            }
        }
        for(int i = 0;i < n;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            if(x > max_x){
                max_x = x;
            }
            if(y > max_y){
                max_y = y;
            }
            maze[x][y] = 1;
        }
        while(q.empty() == false)
            q.pop();
        mark[0][0] = true;
        bool flag = BFS(max_x,max_y,n);
        if(flag == true)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
