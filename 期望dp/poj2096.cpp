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

const int SZ = 1000 + 5;

int n,m;
double dp[SZ][SZ];

template<typename Type>inline void read(Type &xx){
    Type f = 1;char ch;xx = 0;
    for(ch = getchar();ch < '0' || ch > '9';ch = getchar()) if(ch == '-') f = -1;
    for(;ch >= '0' && ch <= '9';ch = getchar()) xx = xx * 10 + ch - '0';
    xx *= f;
}

int main(int argc, char** argv) {
    read(n);read(m);dp[n][m] = 0;
    for(int j = m - 1;j >= 0;j--) dp[n][j] = 1.0 * m / (m - j) + dp[n][j + 1];
    for(int i = n - 1;i >= 0;i--) dp[i][m] = 1.0 * n / (n - i) + dp[i + 1][m];
    int prd = n * m;
    for(int i = n - 1;i >= 0;i--){
        for(int j = m - 1;j >= 0;j--){
            int tmp = prd - i * j;
            dp[i][j] = 1.0 * prd / tmp + 1.0 / tmp * ((n - i) * j * dp[i + 1][j] + i * (m - j) * dp[i][j + 1] + (n - i) * (m - j) * dp[i + 1][j + 1]);
        }
    }
    printf("%.4lf\n",dp[0][0]);
    return 0;
}
