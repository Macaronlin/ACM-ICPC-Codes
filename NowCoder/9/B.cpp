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

const int N=200010;

int T,n,x,y;
long long a[N],z;
vector<pair<int,long long>> e[N];
long long dp[N],sum[N];

void init()
{
    for (int i=1;i<=n;i++)
    {
        e[i].clear();
        dp[i]=0;
        sum[i]=0;
    }
}

bool cmp(pair<long long,long long> a,pair<long long,long long> b)
{
    long long am=a.first,as=a.second;
    long long bm=b.first,bs=b.second;
    return min(am,as+bm)==min(bm,bs+am)?as>bs:min(am,as+bm)>min(bm,bs+am);
}

void dfs(int u,int f,long long pre)
{
    sum[u]=a[u]-pre-pre;
    vector<pair<long long,long long>> t;
    for (auto nxt:e[u])
    {
        int v=nxt.first;
        long long w=nxt.second;
        if (v==f) continue;
        dfs(v,u,w);
        sum[u]+=sum[v];
        t.push_back(make_pair(dp[v],sum[v]));
    }
    sort(t.begin(),t.end(),cmp);
    long long m=0,s=0;
    for (auto i:t)
    {
        m=min(m,s+i.first);
        s+=i.second;
    }
    dp[u]=min(-pre,min(m-pre+a[u],sum[u]));
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--)
    {
        init();
        cin>>n;
        for (int i=1;i<=n;i++) cin>>a[i];
        for (int i=1;i<n;i++)
        {
            cin>>x>>y>>z;
            e[x].push_back(make_pair(y,z));
            e[y].push_back(make_pair(x,z));
        }
        dfs(1,0,0);
        cout<<-dp[1]<<'\n';
    }
    return 0;
}