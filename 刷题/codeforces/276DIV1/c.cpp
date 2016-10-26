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

int getint()
{
    char ch=getchar();
    for (; ch<'0' || ch>'9'; ch=getchar());
    int tmp=0;
    for (; ch>='0' && ch<='9'; ch=getchar())
        tmp=tmp*10+ch-48;
    return tmp;
}

const int maxn=1000000+10;
int N,M,L[maxn],T[maxn],P[maxn],w[maxn];
char s[maxn],ss[maxn];

void permutate(int *A,int *B)
{
    static int C[maxn];
    For(i,0,N-1) C[i]=B[A[i]];
    For(i,0,N-1) A[i]=C[i];
}

void mul(int *T,int x)
{
    static int ret[maxn];
    For(i,0,N-1) ret[i]=i;
    for (; x; x>>=1)
    {
        if (x&1) permutate(ret,T);
        permutate(T,T);
    }
    For(i,0,N-1) T[i]=ret[i];
}

void printt(int *T)
{
    For(i,0,N-1) printf("%d ",T[i]);
    printf("\n");
}
int main()
{
    for (; scanf("%s",s)!=EOF; )
    {
        N=strlen(s);
        scanf("%d",&M);
        L[0]=N-1;
        for (int i=1; i<N; i++) L[i]=i-1;
        while(M--)
        {
            int len=getint(),modd=getint();
            for (int i=0; i<modd; i++) w[i]=0;
            for (int i=0; i<len; i++) w[i%modd]++;
            for (int i=1; i<modd; i++) w[i]+=w[i-1];
            for (int i=len-1; i>=0; i--) P[i]=--w[i%modd];
            for (int i=len; i<N; i++) P[i]=i;
            For(i,0,N-1) T[i]=L[i];
            permutate(T,P);
            mul(T,N-len);
            permutate(P,T);
            For(i,0,N-1) P[i]=(P[i]+N-len)%N;
            For(i,0,N-1) T[P[i]]=i;
            For(i,0,N-1) ss[i]=s[T[i]];
            For(i,0,N-1) s[i]=ss[i];
            printf("%s\n",s);
        }
    }
    return 0;
}