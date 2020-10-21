#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 1e5 + 5;

int L;
double p,q,dp[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%lf%lf",&L,&p,&q)){
        dp[L] = 0;
        dwn(i,L - 1,0){
            double pw = pow(1 - q,L - i);
            dp[i] = dp[i + 1] + 1 + 2 * p * ((L - i) * pw + ((1 - q) / q - (1 / q + L - i - 1) * pw)) / (1 - p);
        }
        printf("%.10lf\n",dp[0]);
    }
    return 0;
}