#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 1e3 + 5;
const double EP = 1e-9;

int r,c;
double dp[SZ][SZ],p[SZ][SZ][3];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%d",&r,&c)){
        rep(i,1,r){
            rep(j,1,c){
                scanf("%lf%lf%lf",&p[i][j][0],&p[i][j][1],&p[i][j][2]);
            }
        }
        dwn(i,r,1){
            dwn(j,c,1){
                //题目保证答案<=1000000，但依然可能出现此处p2或者p3=0且对应的点处p1=0。此时也应保证乘积为0。
                if((i == r && j == c) || 1 - p[i][j][0] < EP){
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = (p[i][j][1] * dp[i][j + 1] + p[i][j][2] * dp[i + 1][j] + 2) / (1 - p[i][j][0]);
            }
        }
        printf("%.3lf\n",dp[1][1]);
    }
    return 0;
}