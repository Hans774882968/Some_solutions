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
#include <algorithm>
//#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
#define rep(i,a,b) for(int i = (a);i <= (b);++i)
#define re_(i,a,b) for(int i = (a);i < (b);++i)

const int N = 5e6 + 5;
char x[N],y[N],ans[N];
int l1,l2,al,fail[N],pre[N],p[N];

void kmp(){
    fail[0] = -1;
    rep(i,1,l1){
        int j = fail[i - 1];
        for(;~j && x[j] != x[i - 1];j = fail[j]);
        fail[i] = j + 1;
    }
}

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    while(~scanf("%s",x)){
        scanf("%s",y);
        l1 = strlen(x);l2 = strlen(y);
        kmp();
        re_(i,0,l2) p[i] = 0;
        int j = 0,tot = 0;al = 0;
        re_(i,0,l2){
            ans[++al] = y[i];
            p[al] = i;
            for(;~j && x[j] != y[i];j = fail[j]);
            pre[i] = ++j;
            if(j == l1){
                al -= l1;
                j = pre[p[al]];
            }
        }
        ans[++al] = '\0';
        puts(ans + 1);
    }
    return 0;
}