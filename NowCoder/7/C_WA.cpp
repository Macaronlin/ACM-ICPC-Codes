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
 
const int N=50010;
const int M=1300;
  
int T,n,m,o,x,y;
//vector<int> e[N];
int dep[N];
int rt;
bool flag[N];
int maxd[N],maxd2[N],maxfa[N],ans[N],tot;
int cnt[N],maxv[N];
vector<int> add;
int totw,now[N],upd[N];
int dfn[N<<1],clk,pos[N];
int st[N<<1][25],lg2[N<<1];
int head[N],to[N<<1],nxt[N<<1],_tot;
 
void init()
{
    //for (int i=1;i<N;i++) e[i].clear();
    //memset(f,0,sizeof(f));
    memset(dep,0,sizeof(dep));
    rt=0;
    memset(flag,0,sizeof(flag));
    memset(maxd,0,sizeof(maxd));
    memset(maxd2,0,sizeof(maxd2));
    memset(maxfa,0,sizeof(maxfa));
    memset(ans,0,sizeof(ans));
    tot=0;
    memset(cnt,0,sizeof(cnt));
    memset(maxv,0,sizeof(maxv));
    add.clear();
    totw=0;
    memset(now,0,sizeof(now));
    memset(upd,0,sizeof(upd));
    memset(dfn,0,sizeof(dfn));
    clk=0;
    memset(pos,0,sizeof(pos));
    //memset(dd,0,sizeof(dd));
    //memset(st,0,sizeof(st));
    _tot = 0;
    memset(head, 0, sizeof(head));
}
 
void add_edge(int u,int v)
{
    to[++_tot]=v;
    nxt[_tot]=head[u];
    head[u]=_tot;
}
 
void get_f(int u,int fa,int d)
{
    dfn[++clk]=u;
    pos[u]=clk;
    //dd[clk]=d;
    dep[u]=d;
    //for (int v:e[u])
    for (int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        if (v==fa) continue;
        get_f(v,u,d+1);
        dfn[++clk]=u;
        //dd[clk]=d;
    }
}
 
void build_st()
{
    lg2[0]=-1;
    for (int i=1;i<=clk;i++) lg2[i]=lg2[i>>1]+1;
    for (int i=1;i<=clk;i++) st[i][0]=dfn[i];
    for (int k=1;k<=20;k++)
    {
        for (int i=1;i<=clk-(1<<k)+1;i++)
        {
            //st[i][k]=max(st[i][k-1],st[i+(1<<(k-1))][k-1]);
            st[i][k]=(dep[st[i][k-1]]<=dep[st[i+(1<<(k-1))][k-1]]?st[i][k-1]:st[i+(1<<(k-1))][k-1]);
        }
    }
}
 
int query_st(int l,int r)
{
    int k=lg2[r-l+1];
    return dep[st[l][k]]<=dep[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
  
int lca(int u,int v)
{
    if (pos[u]>pos[v]) swap(u,v);
    return query_st(pos[u],pos[v]);
}
  
void dfs(int u,int fa,int d)
{
    if (flag[u]) cnt[u]++;
    //for (int v:e[u])
    for (int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        int w=1;
        if (v==fa) continue;
        dfs(v,u,w);
        cnt[u]+=cnt[v];
        if (cnt[v])
        {
            if (maxd[v]+w>maxd[u])
            {
                maxd2[u]=maxd[u];
                maxd[u]=maxd[v]+w;
                maxv[u]=v;
            }
            else if (maxd[v]+w>maxd2[u])
            {
                maxd2[u]=maxd[v]+w;
            }
        }
    }
    if (cnt[u]) tot+=d;
}
  
void dfs2(int u,int fa,int d)
{
    if (!cnt[u]) ans[u]=ans[fa]+d;
    else
    {
        if (maxv[fa]!=u) maxfa[u]=max(maxd[fa]+d,maxfa[fa]+d);
        else maxfa[u]=max(maxd2[fa]+d,maxfa[fa]+d);
        ans[u]=-max(maxd[u],maxfa[u]);
    }
    //for (int v:e[u])
    for (int i=head[u];i;i=nxt[i])
    {
        int v=to[i];
        int w=1;
        if (v==fa) continue;
        dfs2(v,u,w);
    }
}
 
void solve()
{
    if (add.empty())
    {
        for (int i=1;i<=n;i++) now[i]-=upd[i];
        memset(upd,0,sizeof(upd));
        return;
    }
    memset(flag,0,sizeof(flag));
    for (int i:add) flag[i]=true;
    rt=add[0];
    //for (int i=2;i<=k;i++) rt=lca(rt,ed[i]);
    for (int i:add) rt=lca(rt,i);
    dfs(rt,0,0);
    dfs2(rt,0,0);
    for (int i=1;i<=n;i++)
    {
        ans[i]+=2*tot;
        now[i]+=totw-ans[i]-upd[i];
    }
    add.clear();
    totw=0;
    memset(upd,0,sizeof(upd));
}
 
int main()
{
    //ios::sync_with_stdio(0); cin.tie(0);
    scanf("%d",&T);
    while (T--)
    {
        init();
        scanf("%d%d",&n,&m);
        for (int i=1;i<n;i++)
        {
            scanf("%d%d",&x,&y);
            //e[x].push_back(y);
            //e[y].push_back(x);
            add_edge(x,y);
            add_edge(y,x);
        }
        get_f(1,0,0);
        build_st();
        for (int tt=1;tt<=m;tt++)
        {
            scanf("%d",&o);
            if (o==1)
            {
                scanf("%d%d",&x,&y);
                totw+=y;
                add.push_back(x);
            }
            else if (o==2)
            {
                scanf("%d",&x);
                int sum=now[x]+totw-upd[x];
                for (int i:add)
                {
                    int l=lca(i,x);
                    sum-=dep[i]-dep[l]+dep[x]-dep[l];
                }
                if (sum>0) upd[x]+=sum;
                //cout<<now[i]+sum<<'\n';
            }
            else
            {
                scanf("%d",&x);
                int sum=now[x]+totw-upd[x];
                for (int i:add)
                {
                    int l=lca(i,x);
                    sum-=dep[i]-dep[l]+dep[x]-dep[l];
                }
                printf("%d\n",sum);
            }
            if (tt%M==0) solve();
        }
    }
    getchar(); getchar();
    return 0;
}