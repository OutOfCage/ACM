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

const int maxn=1000000+10,maxL=(1<<21)+10;
const int oo=1<<30;
struct Node
{
    int minf,maxf;
    Node() { minf=oo,maxf=-oo;}
};
int N,A[maxn];
Node Tree[maxL];
long long F[maxn];

void maketree(int w,int le,int ri)
{
    if (le==ri)
    {
        Tree[w].minf=Tree[w].maxf=A[le];
        return ; 
    }
    int mid=(le+ri)>>1;
    maketree(w<<1,le,mid);
    maketree(w<<1|1,mid+1,ri);
    Tree[w].minf=min(Tree[w<<1].minf,Tree[w<<1|1].minf);
    Tree[w].maxf=max(Tree[w<<1].maxf,Tree[w<<1|1].maxf);
}

Node query(int w,int le,int ri,int &x,int &y)
{
    if (x>ri || y<le) return Node();
    if (x<=le && ri<=y) return Tree[w];
    int mid=(le+ri)>>1;
    Node ret;
    Node p=query(w<<1,le,mid,x,y);
    Node q=query(w<<1|1,mid+1,ri,x,y);
    ret.minf=min(p.minf,q.minf);
    ret.maxf=max(p.maxf,q.maxf);
    return ret;
}

long long calc(int j,int i)
{
    if (i==j) return F[j-1];
    Node ret=query(1,1,N,j,i);
    return F[j-1]+ret.maxf-ret.minf;
}
int main()
{
    for (; scanf("%d",&N)!=EOF; )
    {
        For(i,1,N) scanf("%d",A+i);
        maketree(1,1,N);
        F[1]=0;
        int j=1;
        For(i,2,N)
        {
            F[i]=calc(j,i);
            for (; j<i; j++)
            {
                long long ret=calc(j+1,i);
                if (i==4 && j==3) cout<<"***"<<ret<<' '<<F[i]<<endl;
                if (ret<F[i]) break;
                F[i]=ret;
            }
        }
        For(i,1,N) cout<<F[i]<<' ';
        //cout<<F[N]<<endl;
        cout<<endl;
        //Node ret;
       // cout<<ret.minf<<' '<<ret.maxf;
    }
    return 0;
}
