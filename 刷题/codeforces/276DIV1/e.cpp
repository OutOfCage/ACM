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
struct Tnode
{
    Tnode *l,*r;
    int pref,suf,len,maxf;
    Tnode() { l=r=NULL; pref=suf=len=maxf=0; }
    void init(int x) { l=r=NULL; pref=suf=maxf=0; len=x; }
    void up()
    {
        maxf=max(l->suf + r->pref,max(l->maxf,r->maxf));
        suf=r->suf + (r->len==r->suf ? l->suf : 0);
        pref=l->pref + (l->len==l->pref ? r->pref : 0);
    }
}Tree[maxn*4+maxn*17],*root[maxn];
int N,M,A[maxn],p[maxn],fre;

bool cmp(int i,int j)
{
    return A[i]>A[j];
}

Tnode *build(int le,int ri)
{
    Tnode *v=&Tree[fre++];
    v->init(ri-le+1);
    if (le==ri) return v;
    int mid=(le+ri)>>1;
    v->l=build(le,mid);
    v->r=build(mid+1,ri);
    return v;
}

Tnode *modify(int le,int ri,int &x,Tnode *&t)
{
    if (x<le || x>ri) return t;
    Tnode *v=&Tree[fre++];
    v->len=t->len;
    if (le==ri)
    {
        v->len=t->len;
        v->pref=v->suf=v->maxf=1;
        v->l=v->r=NULL;
        return v;
    }
    int mid=(le+ri)>>1;
    v->l=modify(le,mid,x,t->l);
    v->r=modify(mid+1,ri,x,t->r);
    v->up();
    return v;
}

Tnode Ans_up(Tnode &l,Tnode &r)
{
    Tnode ret;
    ret.maxf=max(l.suf + r.pref,max(l.maxf,r.maxf));
    ret.suf=r.suf + (r.len==r.suf ? l.suf : 0);
    ret.pref=l.pref + (l.len==l.pref ? r.pref : 0);
    ret.len=l.len + r.len;
    return ret;
}

Tnode query(int le,int ri,int &x,int &y,Tnode *&t)
{
    if (x>ri || y<le) return Tnode();
    if (x<=le && ri<=y) return *t;
    int mid=(le+ri)>>1;
    Tnode p=query(le,mid,x,y,t->l);
    Tnode q=query(mid+1,ri,x,y,t->r);
    return Ans_up(p,q);
}

int Done(int x,int y,int wid)
{
    int le=0,ri=N;
    while(le+1<ri)
    {
        int mid=(le+ri)>>1;
        if (query(1,N,x,y,root[mid]).maxf >= wid) ri=mid;
            else le=mid;
    }
    return ri;
}

int main()
{
    for (; scanf("%d",&N)!=EOF; )
    {
        For(i,1,N) A[i]=getint(),p[i]=i;
        sort(p+1,p+N+1,cmp);
        fre=0;
        root[0]=build(1,N);
        For(i,1,N)
        {
            int w=p[i];
            root[i]=modify(1,N,w,root[i-1]);
        }
        M=getint();
        while(M--)
        {
            int x=getint(),y=getint(),wid=getint();
            int w=p[Done(x,y,wid)];
            printf("%d\n",A[w]);
        }
    }
    return 0;
}
