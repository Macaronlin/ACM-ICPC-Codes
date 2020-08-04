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

const int N=5000010;
const long long M=998244353;

int T,n;
long long inv[N];
long long fac[N],invf[N],inv2[N];

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

long long get_inv(long long a,long long p) {return qpow(a,p-2,p);}

void linear_inv(long long n,long long p)
{
    inv[1]=1;
    for (long long i=2;i<=n;i++) inv[i]=((p-p/i)*inv[p%i])%p;
    fac[0]=1;
    for (long long i=1;i<=n;i++) fac[i]=(fac[i-1]*i)%p;
    invf[n]=get_inv(fac[n],p);
    for (long long i=n-1;i>=0;i--) invf[i]=(invf[i+1]*(i+1))%p;
    inv2[0]=1; inv2[1]=get_inv(2,M);
    for (long long i=2;i<=n;i++) inv2[i]=(inv2[i-1]*inv2[1])%p;
}

long long cal(int n,int k)
{
    return ((((fac[n+k]*inv2[k])%M*invf[k])%M*inv2[n])%M*invf[n])%M;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    linear_inv(5000000,M);
    cin>>T;
    while (T--)
    {
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            if (i<=n/2) cout<<0;
            else cout<<cal(n/2,i-n/2-1);
            if (i==n) cout<<'\n';
            else cout<<' ';
        }
    }
    getchar(); getchar();
    return 0;
}