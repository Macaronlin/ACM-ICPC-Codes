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

const int N=5010;
const long long M=998244353;

int T,n,k;
long long dp[N][N];
long long inv[N];
long long fac[N],invf[N];

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
}

long long A(long long n,long long m,long long p)
{
    if (m>n) return 0;
    return (fac[n]*invf[n-m])%p;
}

long long C(long long n,long long m,long long p)
{
    if (m>n) return 0;
    return ((fac[n]*invf[m])%p*invf[n-m])%p;
}

long long get_dp(int id,int l)
{
    if (l<0) return 0;
    if (dp[id][l]!=-1) return dp[id][l];
    if (id>=n/(k+1)) return dp[id][l]=1;
    long long re=0;
    for (int i=0;i<=min(l-1,k);i++)
    {
        long long cnt=((C(l-1,i,M)*C(n-id*(k+1)-l-1,k-i,M))%M*fac[k])%M;
        re=(re+(cnt*get_dp(id+1,l-i-1))%M)%M;
    }
    return dp[id][l]=re;
}
 
int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    linear_inv(5000,M);
    cin>>T;
    while (T--)
    {
        cin>>n>>k;
        for (int i=0;i<=n;i++)
        {
            for (int j=0;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        for (int i=1;i<=n;i++)
        {
            long long u=get_dp(0,i-1);
            long long v=1;
            int t=n;
            while (t>k)
            {
                v=(v*A(t-1,k,M))%M;
                t-=k+1;
            }
            cout<<(u*get_inv(v,M))%M;
            if (i==n) cout<<'\n';
            else cout<<' ';
        }
    }
    getchar(); getchar();
    return 0;
}