#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <climits>
#include <cmath>
using namespace std;

const long long M=998244353;

int n;

long long qpow(long long a,long long k,long long p)
{
    long long re=1;
    while (k)
    {
        if (k&1) re=(re*a)%p;
        k>>=1;
        a=(a*a)%p;
    }
    return re;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    freopen("cover.in","r",stdin);
    freopen("cover.out","w",stdout);
    while (1)
    {
        cin>>n;
        if (!n) break;
        long long ans=0;
        for (int i=1;i<=n;i++)
        {
            int t=n%i;
            if (!t) ans=(ans+qpow(2,i,M))%M;
            else ans=(ans+qpow(2,t,M))%M;
        }
        cout<<ans<<'\n';
    }
    getchar(); getchar();
    return 0;
}