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
  
const int INF=INT_MAX/4;
const int N=500010;
  
int T;
int n,a[N],b[N];
vector<int> mp;
vector<int> e[N];
bool vis[N];
int cnt0,cnt1;
  
void init()
{
    for (int i=1;i<=n+n;i++) e[i].clear();
    mp.clear();
    memset(vis,0,sizeof(vis));
}
 
int read_int()
{
    char c=0; int re=0;
    while (!isdigit(c)) c=getchar();
    while (isdigit(c)) {re=re*10+c-'0'; c=getchar();}
    return re;
}
 
void add_edge(int x,int y)
{
    e[x].push_back(y);
    e[y].push_back(x);
}
 
void dfs(int u)
{
    vis[u]=true;
    if (u<=n) cnt0++;
    else cnt1++;
    for (int v:e[u])
    {
        if (vis[v]) continue;
        dfs(v);
    }
}
 
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    //freopen("I.in","r",stdin);
    T=read_int();
    for (int tt=1;tt<=T;tt++)
    {
        init();
        n=read_int();
        for (int i=1;i<=n;i++)
        {
            a[i]=read_int(); b[i]=read_int();
            mp.push_back(a[i]);
            mp.push_back(b[i]);
        }
        sort(mp.begin(),mp.end());
        mp.resize(unique(mp.begin(),mp.end())-mp.begin());
        for (int i=1;i<=n;i++)
        {
            a[i]=lower_bound(mp.begin(),mp.end(),a[i])-mp.begin()+1;
            b[i]=lower_bound(mp.begin(),mp.end(),b[i])-mp.begin()+1;
            add_edge(i,n+a[i]);
            add_edge(i,n+b[i]);
        }
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            if (!vis[i])
            {
                cnt0=0; cnt1=0;
                dfs(i);
                ans+=min(cnt0,cnt1);
            }
        }
        cout<<"Case #"<<tt<<": "<<ans<<'\n';
    }
    getchar(); getchar();
    return 0;
}