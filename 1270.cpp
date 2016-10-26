#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <vector>
#include <bitset>
using namespace std;

#define bll long long
#define dou double
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define rep(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define rek(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define Mem(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(b))
//__builtin_popcountll

const int maxn=50000+100;
int N,A[maxn];
int dp[maxn][2];

bool cmp(int a,int b)
{
    if (a!=1 || b!=1) return 0;
    return a==b;
}

int Done()
{
    dp[1][0]=dp[1][1]=0;
    For(i,2,N)
    {
        dp[i][0]=max(dp[i-1][0]+abs(1-1),dp[i-1][1]+abs(1-A[i-1]));
        dp[i][1]=max(dp[i-1][0]+abs(A[i]-1),dp[i-1][1]+abs(A[i]-A[i-1]));
    }
    return max(dp[N][0],dp[N][1]);
}

int main(int argc, char* argv[])
{
    for (; scanf("%d",&N)!=EOF; )
    {
        For(i,1,N) scanf("%d",&A[i]);
        N=unique(A+1,A+N+1,cmp)-A-1;
        int ans=Done();
        printf("%d\n",ans);
    }
    return 0;
}