#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define dwn(i,a,b) for(int i = (a);i >= (b);--i)

const int SZ = 10005;
const double EP = 1e-9;

double a[SZ],b[SZ],c[SZ],X[SZ],K[SZ],E[SZ];
int n;vector<int> G[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

void dfs(int u,int ufa){
    if(G[u].size() == 1 && u != 1){
        a[u] = X[u];
        b[u] = K[u];
        c[u] = 1 - K[u] - E[u];
        return;
    }
    double tmp = 1,sumb = 0,sumc = 0;
    for(auto v: G[u]){
        if(v == ufa) continue;
        dfs(v,u);
        tmp -= X[u] * a[v];
        sumb += b[v];
        sumc += c[v];
    }
    a[u] = X[u] / tmp;
    b[u] = (K[u] + X[u] * sumb) / tmp;
    c[u] = (X[u] * sumc + 1 - K[u] - E[u]) / tmp;
}

int main(int argc, char** argv) {
    int T,cas = 0;read(T);
    while(T--){
        read(n);
        rep(i,1,n) G[i].clear();
        rep(i,1,n - 1){
            int p1,p2;read(p1);read(p2);
            G[p1].push_back(p2);G[p2].push_back(p1);
        }
        rep(i,1,n){
            int p1,p2;read(p1);read(p2);
            K[i] = p1 * 1.0 / 100;E[i] = p2 * 1.0 / 100;
        }
        rep(i,1,n) X[i] = (1 - K[i] - E[i]) / G[i].size();
        dfs(1,0);
        if(fabs(1 - b[1]) > EP) printf("Case %d: %.6lf\n",++cas,c[1] / (1 - b[1]));
        else printf("Case %d: impossible\n",++cas);
    }
    return 0;
}