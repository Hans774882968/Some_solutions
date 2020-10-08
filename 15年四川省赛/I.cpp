#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include <cmath>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define re_(i,a,b) for(int i = (a);i < (b);++i)
#define rep(i,a,b) for(int i = (a);i <= (b);++i)

const int SZ = 100000 + 3;
const LL INF = (1LL << 60) + 10;

int n,m,a,b,S;vector<int> G[SZ];
LL dis[SZ];queue<int> q;
bool vis[SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

LL bfs(int S){
    set<int> acc,ncc;
    for(int i = 1;i <= n;++i){
        dis[i] = INF;
        if(i != S) acc.insert(i);
    }
    dis[S] = 0;q.push(S);
    while(!q.empty()){
        int u = q.front();q.pop();
        re_(i,0,G[u].size()){
            int v = G[u][i];
            if(!acc.count(v)) continue;
            acc.erase(v);
            ncc.insert(v);
        }
        for(set<int>::iterator it = acc.begin();it != acc.end();++it){
            int v = *it;
            dis[v] = dis[u] + b;
            q.push(v);
        }
        acc.swap(ncc);
        ncc.clear();
    }
    return dis[n];
}

struct Node{
    int x;LL d;
    Node(){}
    Node(int x,LL d):x(x),d(d){}
    bool operator < (const Node &rhs) const{
        return d > rhs.d;
    }
};
priority_queue<Node> qq;

LL dij(int S,int lim){
    for(int i = 1;i <= lim;++i) dis[i] = INF,vis[i] = false;
    dis[S] = 0;qq.push(Node(S,dis[S]));
    while(!qq.empty()){
        int u = qq.top().x;qq.pop();
        if(vis[u]) continue;
        vis[u] = true;
        re_(i,0,int(G[u].size())){
            int v = G[u][i];
            if(dis[v] > dis[u] + a){
                dis[v] = dis[u] + a;
                qq.push(Node(v,dis[v]));
            }
        }
    }
    return dis[n];
}

int main(int argc, char** argv) {
    while(~scanf("%d%d%d%d",&n,&m,&a,&b)){
        S = 1;
        for(int i = 1;i <= n;++i) G[i].clear();
        bool fl = false;
        for(int i = 0;i < m;++i){
            int p1,p2;read(p1);read(p2);
            if(p1 > p2) swap(p1,p2);
            if(p1 == 1 && p2 == n) fl = true;
            G[p1].push_back(p2);G[p2].push_back(p1);
        }
        LL ans;
        if(fl) ans = min(bfs(S),1LL*a);
        else ans = min(dij(S,n),1LL*b);
        printf("%lld\n",ans);
    }
    return 0;
}