#include <bits/stdc++.h>
using namespace std;

const long long M=1000000007;
const int N=5010;

int T,n,a[N];
long long fac[N];
long long dp[N][N];
vector<int> pos;


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

long long C(long long n,long long m,long long p)
{
    if (m>n) return 0;
    return ((fac[n]*get_inv(fac[m],p))%p*get_inv(fac[n-m],p))%p;
}

long long get_dp(int l,int r)
{
    if (dp[l][r]!=-1) return dp[l][r];
    if (l==r) return dp[l][r]=1;
    long long re=0;
    auto p=lower_bound(pos.begin(),pos.end(),l + 1);
    //for (int i=l+1;i<r;i++)
    for (auto it=p;it!=pos.end();it++)
    {
        //if (!flag[i]) continue;
        int i=*it;
        if (i>=r) break;
        re=(re+((get_dp(l,i-1)*get_dp(i+1,r))%M*C(r-l,(r-l)-(i-l),M))%M)%M;
    }
    if (a[l]==0) re=(re+get_dp(l+1,r))%M;
    if (a[r-1]==1) re=(re+get_dp(l,r-1))%M;
    return dp[l][r]=re;
}

int main()
{
    
    // freopen("1004.in", "r", stdin);
    // freopen("1004.out", "w", stdout);
    
    clock_t _s = clock();
    ios::sync_with_stdio(0); cin.tie(0);
    fac[0]=1;
    for (int i=1;i<N;i++) fac[i]=(fac[i-1]*i)%M;
    cin>>T;
    while (T--)
    {
        cin>>n;
        pos.clear();
        for (int i=1;i<n;i++)
        {
            cin>>a[i];
            //if (i>1 && a[i-1]==1 && a[i]==0) flag[i]=true;
            //else flag[i]=false;
            if (i>1 && a[i-1]==1 && a[i]==0) pos.push_back(i);
        }
        for (int i=1;i<=n;i++)
        {
            for (int j=1;j<=n;j++)
            {
                dp[i][j]=-1;
            }
        }
        cout<<get_dp(1,n)<<'\n';
    }
    clock_t _t = clock();
    printf("%.6lf s\n", (_t - _s) * 1.0 / CLOCKS_PER_SEC);
    getchar(); getchar();
    return 0;
}