#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 20,SZ0 = (1 << 10) + 3;

int dl,d[SZ];LL dp[SZ][SZ0][11];
int k,bc[SZ0];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int update_lis(int S,int x){
    rep(i,x,9){
        if(S >> i & 1){
            S ^= (1 << i);
            break;
        }
    }
    return S | (1 << x);
}

LL dfs(int idx,int S,bool zero,bool isup){
    if(idx == -1) return bc[S] == k;
    if(!isup && !zero && ~dp[idx][S][k]) return dp[idx][S][k];
    int up = isup ? d[idx] : 9;
    LL ans = 0;
    rep(i,0,up){
        bool nzero = zero && (i == 0);
        ans += dfs(idx - 1,nzero ? S : update_lis(S,i),nzero,isup && i == up);
    }
    if(!isup && !zero) dp[idx][S][k] = ans;
    return ans;
}

LL solve(LL x){
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    return dfs(dl - 1,0,true,true);
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    bc[0] = 0;rep(i,1,SZ0 - 3) bc[i] = bc[i - (i & (-i))] + 1;
    int T,cas = 0;read(T);
    while(T--){
        LL a,b;read(a);read(b);read(k);
        printf("Case #%d: %I64d\n",++cas,solve(b) - solve(a - 1));
    }
    return 0;
}