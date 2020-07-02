#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int a[101];

int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++){
        scanf("%d",&a[i]);
    }
    sort(a+1,a+1+n);
    int cnt = 0;
    for(int i = 1;i <= n-1;i += 2){
        if(a[i] != a[i+1])
            cnt += abs(a[i] - a[i + 1]);
    }
    printf("%d\n",cnt);
    return 0;
}
