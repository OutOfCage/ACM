#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
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

int getint()
{
    char ch=getchar();
    for (; ch<'0' || ch>'9'; ch=getchar());
    int tmp=0;
    for (; ch>='0' && ch<='9'; ch=getchar())
        tmp=tmp*10+ch-48;
    return tmp;
}

const int maxn=100000+100;
struct Query_Type
{
    int x,y,w;
};

int main()
{
    for (; scanf("%d",&N)!=EOF; )
    {
        For(i,1,N) A[i]=getint();
        M=getint();
        For(i,1,M) Q[i].x=getint(),Q[i].y=getint(),Q[i].w=getint();
        For(i,1,M) num[i]=i;
        For(i,1,N) p[i]=A[i];
        sort(p+1,p+N+1);
        int le=1,ri=1;
        For(i,2,N) if (p[i]!=p[ri]) p[++ri]=p[i];
        dfs_divide()
    }
    return 0;
}
