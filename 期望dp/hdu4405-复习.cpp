#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 1e5 + 10;

int n,m;
int mov[SZ];
double dp[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%d",&n,&m) && (n || m)){
        rep(i,1,n + 6) mov[i] = -1;
        rep(i,0,6) dp[n + i] = 0;
        rep(i,1,m){
            int x,y;read(x);read(y);
            mov[x] = y;
        }
        dwn(i,n - 1,0){
            dp[i] = 1;
            rep(j,1,6){
                int p = i + j;
                for(;~mov[p];p = mov[p]);
                dp[i] += dp[p] / 6;
            }
        }
        printf("%.4lf\n",dp[0]);
    }
    return 0;
}