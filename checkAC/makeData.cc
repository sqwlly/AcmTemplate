#include <bits/stdc++.h>
#define random(a,b) ((a)+rand()%((b)-(a)+1))
using namespace std;
int main(){
        // freopen("data.in","w",stdout);
        srand(time(0));
        int n=rand()%30;
        while(n==1) n=rand()%30;
        int m=rand()%50;
        printf("%d %d\n",n,m);
        for(int i = 1; i <= n; ++i) {
                printf("%d ", rand()%100);
        }
        for(int i=1; i<=m; i++) {
                int a=random(1,2);
                int b=random(1,n);
                int c=random(b,n);
                // while(a==b) b=rand()%n+1;
                printf("%d %d %d\n",a,b,c);
        }
        return 0;
}
