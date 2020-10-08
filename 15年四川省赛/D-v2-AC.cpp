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
#include <bitset>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int N = 505;
bitset<N> g[N];
int color[N];
int c[N];
int ans,n,m,lim;

void dfs(int u,bitset<N> a){
    if(int(a.count())>=ans)return;
    if(u>lim){
        ans=min(ans,int(a.count()));
        return;
    }
    a[u] = 1;
    dfs(u+1,a);
    a[u] = 0;
    a |= g[u];
    dfs(u+1,a);
}

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%d%d", &n, &m)){
        ans = N;lim = 0;
        re_(i,0,N) g[i].reset();
        for (int i = 0; i < m; i++)
        {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u][v] = g[v][u] = 1;
            if(u <= 30) lim = max(lim,u);
            if(v <= 30) lim = max(lim,v);
        }
        dfs(1,bitset<N>());
        printf("%d\n",ans);
    }
    return 0;
}
