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

const int N=100010;

int T,n,x[N],y[N];
vector<int> v1,v2;
int id1[N],id2[N];
int siz;

const int INF=INT_MAX/4;

struct Edge {int u,v,c,f;};

struct Dinic
{
    int n,m,s,t;
    vector<Edge> e;
    vector<int> g[N];
    bool vis[N];
    int d[N],cur[N];

    void init()
    {
        for (int i=0;i<=siz;i++) g[i].clear();
        e.clear();
    }

    void add_edge(int u,int v,int c)
    {
        e.push_back({u,v,c,0});
        e.push_back({v,u,0,0});
        m=e.size();
        g[u].push_back(m-2);
        g[v].push_back(m-1);
    }

    bool bfs()
    {
        //memset(vis,0,sizeof(vis));
        for (int i=0;i<=siz;i++) vis[i]=0;
        queue<int> q;
        q.push(s); d[s]=0; vis[s]=true;
        while (!q.empty())
        {
            int now=q.front(); q.pop();
            for (int i:g[now])
            {
                Edge nxt=e[i];
                if (!vis[nxt.v] && nxt.c>nxt.f)
                {
                    vis[nxt.v]=true;
                    d[nxt.v]=d[now]+1;
                    q.push(nxt.v);
                }
            }
        }
        return vis[t];
    }

    int dfs(int u,int minf)
    {
        if (u==t || !minf) return minf;
        int flow=0,f=0;
        for (int &i=cur[u];i<(int)g[u].size();i++)
        {
            Edge& nxt=e[g[u][i]];
            if (d[u]+1==d[nxt.v] && (f=dfs(nxt.v,min(minf,nxt.c-nxt.f)))>0)
            {
                nxt.f+=f; e[g[u][i]^1].f-=f;
                flow+=f; minf-=f;
                if (!minf) break;
            }
        }
        return flow;
    }

    int maxflow(int s,int t)
    {
        this->s=s; this->t=t;
        int flow=0;
        while (bfs())
        {
            //memset(cur,0,sizeof(cur));
            for (int i=0;i<=siz;i++) cur[i]=0;
            flow+=dfs(s,INF);
        }
        return flow;
    }
}d;

void init()
{
    d.init();
    v1.clear();
    v2.clear();
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>T;
    while (T--)
    {
        init();
        cin>>n;
        for (int i=1;i<=n;i++)
        {
            cin>>x[i]>>y[i];
            v1.push_back(x[i]+y[i]);
            v2.push_back(x[i]-y[i]);
        }
        sort(v1.begin(),v1.end());
        v1.resize(unique(v1.begin(),v1.end())-v1.begin());
        sort(v2.begin(),v2.end());
        v2.resize(unique(v2.begin(),v2.end())-v2.begin());
        for (int i=1;i<=n;i++)
        {
            id1[i]=lower_bound(v1.begin(),v1.end(),x[i]+y[i])-v1.begin()+1;
            id2[i]=lower_bound(v2.begin(),v2.end(),x[i]-y[i])-v2.begin()+1;
        }
        int siz1=v1.size(),siz2=v2.size();
        siz=siz1+siz2+1;
        for (int i=1;i<=n;i++)
        {
            d.add_edge(id1[i],siz1+id2[i],1);
        }
        for (int i=1;i<=siz1;i++) d.add_edge(0,i,1);
        for (int i=siz1+1;i<=siz1+siz2;i++) d.add_edge(i,siz1+siz2+1,1);
        cout<<d.maxflow(0,siz1+siz2+1)<<'\n';
    }
    getchar(); getchar();
    return 0;
}
