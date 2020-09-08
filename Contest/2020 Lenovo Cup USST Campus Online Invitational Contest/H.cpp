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

const int N=510;
const int M=998244353;

int n,m,k;
long long a[N][N];
long long fr[N],fc[N];
char s[2];
int x;
long long t;

int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    //cin>>n>>m>>k;
    scanf("%d%d%d",&n,&m,&k);
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            //cin>>a[i][j];
            scanf("%lld",&a[i][j]);
        }
    }
    long long ans=0;
    while (k--)
    {
        //cin>>s>>x>>t;
        scanf("%s%d%lld",s,&x,&t);
        if (s[0]=='r') fr[x]=t;
        else fc[x]=t;
    }
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
        {
            long long t=max(fr[i],fc[j])%M;
            ans=(ans+a[i][j]%M*t)%M;
        }
    }
    //cout<<ans;
    printf("%lld",ans);
    getchar(); getchar();
    return 0;
}