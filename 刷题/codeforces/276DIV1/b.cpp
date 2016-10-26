#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

#define ll long long
#define dou double
#define For(i,a,b) for (int i=(a),_##i=(b); i<=_##i; i++)
#define Rof(i,a,b) for (int i=(a),_##i=(b); i>=_##i; i--)
#define Mem(a,b) memset(a,b,sizeof(a))
#define Cpy(a,b) memcpy(a,b,sizeof(b))

int N,M,Ans,G[2000005],pre[2000005];

void Done(int x)
{
    for (int i=x; i<=M+x; i+=x)
    {
        if (pre[i]<x) continue;
        int ret=pre[i] % x;
        Ans=max(ret,Ans);
    }
}

int main()
{
    for (; scanf("%d",&N)!=EOF; )
    {
        Mem(G,0); Mem(pre,0);
        M=0;
        For(i,1,N)
        {
            int x; scanf("%d",&x);
            G[x]++;
            M=max(M,x);
        }
        Ans=0;
        int w=0;
        For(i,1,M*2)
        {
            pre[i]=w;
            if (G[i]) w=i;
        }
        For(i,2,M)
            if (G[i]) Done(i);
        printf("%d\n",Ans);
    }
    return 0;
}