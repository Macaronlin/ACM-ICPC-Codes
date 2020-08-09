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
const long long N=100010;

long long a,b,c,d,x,y;
bool not_pri[N];
vector<long long> pri;
vector<pair<long long,long long>> dx,dy;


void euler_sieve(long long lim)
{
    for (long long i=2;i<=lim;i++)
    {
        if (!not_pri[i]) pri.push_back(i);
        for (long long j:pri)
        {
            if ((long long)i*j>lim) break;
            not_pri[i*j]=true;
            if (i%j==0) break;
        }
    }
}

vector<pair<long long,long long>> decomp(long long x)
{
    vector<pair<long long,long long>> re;
    for (long long d:pri)
    {
        if (d*d>x) break;
        if (x%d) continue;
        long long cnt=0;
        while (x%d==0)
        {
            x/=d;
            cnt++;
        }
        re.push_back(make_pair(d,cnt));
    }
    if (x>1) re.push_back(make_pair(x,1));
    return re;
}

long long qpow(long long a,__int128_t k,long long p)
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

long long cal(long long p,long long x,long long y,long long a,long long b,long long c,long long d)
{
    //long long re=1;
    __int128_t sum=0;
    for (long long i=a;i<=b;i++)
    {
        long long lim=max(c,(x*i+y-1)/y);
        long long cnt=max(0ll,d-lim+1);
        if (!cnt) break;
        //re=(re*qpow(p,x*i*cnt,M))%M;
        sum+=x*i*cnt;
    }
    for (long long j=c;j<=d;j++)
    {
        long long lim=max(a,(y*j)/x+1);
        long long cnt=max(0ll,b-lim+1);
        if (!cnt) break;
        //re=(re*qpow(p,y*j*cnt,M))%M;
        sum+=y*j*cnt;
    }
    return qpow(p,sum,M);
}

long long solve(long long a,long long b,long long c,long long d)
{
    if (b==0 || d==0) return 1;
    if (a==0) a++;
    if (c==0) c++;
    long long re=1;
    for (auto i:dx)
    {
        for (auto j:dy)
        {
            if (i.first!=j.first) continue;
            re=(re*cal(i.first,i.second,j.second,a,b,c,d))%M;
        }
    }
    return re;
}

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    cin>>a>>b>>c>>d>>x>>y;
    euler_sieve(100000);
    dx=decomp(x); dy=decomp(y);
    //cout<<(((solve(b,d)*get_inv(solve(b,c-1),M))%M*get_inv(solve(a-1,d),M))%M*solve(a-1,c-1))%M;
    cout<<solve(a,b,c,d);
    getchar(); getchar();
    return 0;
}