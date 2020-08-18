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

int T;
long long a,b,k;
long double eps=1e-8;

long long bi(long long a,double k)
{
    long long l=1,r=200000000;
    while (l<r)
    {
        long long mid=(l+r)>>1;
        if ((long long)(k*mid+eps)<=a) l=mid+1;
        else r=mid;
    }
    return l-1;
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--)
    {
        cin>>a>>b>>k;
        if (a>b) swap(a,b);
        k++;
        long double s=(2+k+sqrt(k*k+4))/2;
        long double r=s/(s-1);
        long long n=bi(a,r);
        if ((long long)(r*n+eps)!=a || (long long)(s*n+eps)!=b) cout<<1<<'\n';
        else cout<<0<<'\n';
    }
    getchar(); getchar();
    return 0;
}