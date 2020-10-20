#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 20,SZ0 = 1900;

int dl,d[SZ];LL dp[SZ][SZ0 << 1];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

inline int ID(int v){return v + SZ0;}

//non0：表示是否已经枚举过至少1个非0位。我们dfs模板有一个缺点就是前导0不好处理：为了去掉”不合法的piv位置“，使用if(piv > idx) return 0;
LL dfs(int idx,int v,int piv,bool non0,bool isup){
    if(v < 0) return 0;//剪枝：nv从0始先单增后单减，如果某时刻小于0肯定永远小于0。
    if(idx == -1) return v == 0;
    if(!isup && non0 && ~dp[idx][ID(v)]) return dp[idx][ID(v)];
    int up = isup ? d[idx] : 9;
    LL ans = 0;
    rep(i,0,up){
        int nv = v + i * (idx - piv);
        if(i == 0){
            ans += dfs(idx - 1,v,piv,non0,isup && i == up);
        }
        else{
            if(!non0){
                if(piv > idx) return 0;
                ans += dfs(idx - 1,nv,piv,true,isup && i == up);
            }
            else ans += dfs(idx - 1,nv,piv,non0,isup && i == up);
        }
    }
    if(!isup && non0) dp[idx][ID(v)] = ans;
    return ans;
}

LL solve(LL x){
    if(x < 0) return 0;
    if(x == 0) return 1;
    dl = 0;
    for(;x;x /= 10) d[dl++] = x % 10;
    LL ans = 0;
    re_(piv,0,dl){
        memset(dp,-1,sizeof dp);
        ans += dfs(dl - 1,0,piv,false,true);
    }
    return ans;
}

int main(int argc, char** argv) {
    memset(dp,-1,sizeof dp);
    int T;read(T);
    while(T--){
        LL a,b;read(a);read(b);
        printf("%lld\n",solve(b) - solve(a - 1));
    }
    return 0;
}