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

const int maxn=1000000+10;
int N,A[maxn];
long long F[maxn];

int get_sign(int x)
{
    if (x<0) return -1;
    if (x>0) return 1;
    return 0;
}

void Done()
{
    int i=1;
    if (A[i]==A[i+1]) i++;
    F[i-1]=F[i]=0;
    for (; i<N; )
    {
        int j=i+1;
        int d=get_sign(A[i]-A[i+1]);
        for (; j<N && d==get_sign(A[j]-A[j+1]); j++);
        F[j]=F[i-1]+(ll)abs(A[i]-A[j]);
        if (i!=j) F[j]=max(F[j],F[i]+(ll)abs(A[i+1]-A[j]));
        if (i+1<j)
        {
            F[j-1]=F[i-1]+(ll)abs(A[i]-A[j-1]);
            F[j-1]=max(F[j-1],F[i]+(ll)abs(A[i+1]-A[j-1]));
        }
        i=j;
    }
}

int main()
{
    for (; scanf("%d",&N)!=EOF; )
    {
        For(i,1,N) scanf("%d",A+i);
        int nn=2;
        For(i,3,N) if (A[i]!=A[nn] || A[i]!=A[nn-1]) A[++nn]=A[i];
        N=nn;
        For(i,1,N) F[i]=0;
        Done();
        long long ans=0;
        For(i,1,N) ans=max(ans,F[i]);
        //For(i,1,N) cout<<F[i]<<' ';
        //cout<<endl;
        cout<<ans<<endl;
    }
    return 0;
}