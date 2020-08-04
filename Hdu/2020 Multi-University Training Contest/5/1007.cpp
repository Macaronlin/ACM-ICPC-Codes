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

int T,n,k,x,y;
long long z;
vector<pair<int,long long>> e[N];
vector<pair<long long,int>> st[N];
long long dp[N];
long long pre[N];
long long dpf[N],ans[N];

void init()
{
    for (int i=1;i<=n;i++)
    {
        e[i].clear();
        st[i].clear();
        dp[i]=0;
        pre[i]=0;
        dpf[i]=0;
        ans[i]=0;
    }
}

long long get_k(int u,int k)
{
    if (k<=0) return LONG_LONG_MAX;
    if (k>(int)st[u].size()) return 0;
    return st[u][k-1].first;
}

void dfs(int u,int f)
{
    for (auto nxt:e[u])
    {
        int v=nxt.first;
        long long w=nxt.second;
        if (v==f) continue;
        dfs(v,u);
        st[u].push_back(make_pair(dp[v]+w,v));
        pre[v]=w;
    }
    sort(st[u].begin(),st[u].end(),greater<pair<long long,int>>());
    int siz=st[u].size();
    for (int i=0;i<min(siz,k-1);i++) dp[u]+=st[u][i].first;
}

void get_ans(int u,int f)
{
    if (f)
    {
        long long d1=dp[f]+pre[u];
        if (dp[u]+pre[u]>=get_k(f,k-1)) d1=d1-(dp[u]+pre[u])+get_k(f,k);
        long long d2=0;
        if (k>1)
        {
            d2=dpf[f]+dp[f]-get_k(f,k-1)+pre[u];
            if (dp[u]+pre[u]>=get_k(f,k-2)) d2=d2-(dp[u]+pre[u])+get_k(f,k-1);
        }
        dpf[u]=max(d1,d2);
    }
    ans[u]=dpf[u];
    for (auto nxt:e[u])
    {
        int v=nxt.first;
        long long w=nxt.second;
        if (v==f) continue;
        get_ans(v,u);
        ans[u]+=dp[v]+w;
    }
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--)
    {
        init();
        cin>>n>>k;
        for (int i=1;i<n;i++)
        {
            cin>>x>>y>>z;
            e[x].push_back(make_pair(y,z));
            e[y].push_back(make_pair(x,z));
        }
        if (k==0)
        {
            cout<<0<<'\n';
            continue;
        }
        dfs(1,0);
        get_ans(1,0);
        long long maxans=0;
        //for (int i=1;i<=n;i++)cout<<dp[i]<<' '<<dpf[i]<<'\n';
        for (int i=1;i<=n;i++) maxans=max(maxans,ans[i]);
        cout<<maxans<<'\n';
    }
    getchar(); getchar();
    return 0;
}