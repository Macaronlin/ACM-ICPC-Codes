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

const int N=10000010;
const long long M=998244353;

int n;
long long p,x,y,z,b[N];
long long a,ans;
long long st[N],sum;
int tp;

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>p>>x>>y>>z>>b[1];
    for (int i=1;i<=n;i++)
    {
        if (i>1) b[i]=(x*a+y*b[i-1]+z)%p;
        while (tp && b[st[tp]]>=b[i])
        {
            sum=(sum-(b[st[tp]]*(st[tp]-st[tp-1]))%M+M)%M;
            tp--;
        }
        st[++tp]=i;
        sum=(sum+(b[i]*(i-st[tp-1]))%M)%M;
        a=(a+sum)%M;
        //cout<<a<<'\n';
        ans^=a;
    }
    cout<<ans;
    getchar(); getchar();
    return 0;
}