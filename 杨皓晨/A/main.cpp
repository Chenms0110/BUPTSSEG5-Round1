#include<cstdio>
#include<algorithm>
using namespace std;

int a[101];
int p[101];

int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,m;
        scanf("%d%d",&n,&m);
        for(int i = 1;i <= n;i++){
            scanf("%d",&a[i]);
        }
        for(int j = 1;j <= m;j++){
            scanf("%d",&p[j]);
        }
        sort(p + 1,p + m + 1);
        sort(a + p[1],a + p[m]);
        bool flag = false;
        if(p[1] > 1){
            for(int i = 1;i < p[1];i++){
                if(a[i] > a[i + 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(p[m] < n - 1){
            for(int i = n;i > p[m];i--){
                if(a[i] < a[i - 1]){
                    flag = true;
                    break;
                }
            }
        }
        if(flag == false){
            printf("YES\n");
        }
        else{
            printf("NO\n");
        }
    }
    return 0;
}
