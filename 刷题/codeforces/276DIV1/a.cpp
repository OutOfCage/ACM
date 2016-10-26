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

int N;
long long L,R;

int main()
{
    scanf("%d",&N);
    for (; N--; )
    {
        cin>>L>>R;
       // int gg=0,w=L;
      /*  for (int i=L; i<=R; i++)
        {
            int c=__builtin_popcount(i);
            if (c>gg) w=i,gg=c;
        }
        cout<<w<<endl;*/
        long long ans;
        Rof(i,62,0)
        {
            if ((1LL<<i)&R)
            {
                if ((1LL<<i)&L) continue;
                ans=R;
                ans|=((1LL<<i)-1);
                if (ans>R) ans^=(1LL<<i);
                break;
            }
        }
        if (L==R) ans=L;
        cout<<ans<<endl;
    }
    return 0;
}