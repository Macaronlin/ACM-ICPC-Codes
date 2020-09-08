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

int n,m,x,y;
vector<pair<int,int>> g;
int f[N],d[N];

int find_f(int p)
{
    if (f[p]==p) return p;
    return f[p]=find_f(f[p]);
}

int main()
{
    ios::sync_with_stdio(0); cin.tie(0);
    cin>>n>>m;
    for (int i=1;i<=m;i++)
    {
        cin>>x>>y;
        g.push_back(make_pair(x,y));
    }
    sort(g.begin(),g.end(),[&](pair<int,int> a,pair<int,int> b)
    {
        int u=a.first,v=a.second;
        if (u<v) swap(u,v);
        if (u==v+1) u++,v=0;
        auto aa=make_pair(u,v);
        u=b.first,v=b.second;
        if (u<v) swap(u,v);
        if (u==v+1) u++,v=0;
        auto bb=make_pair(u,v);
        return aa<bb;
    });
    for (int i=1;i<=n;i++) f[i]=i;
    for (auto i:g)
    {
        int u=i.first,v=i.second;
        int fu=find_f(u),fv=find_f(v);
        if (fu==fv) continue;
        f[fu]=fv;
        d[u]++; d[v]++;
    }
    int ans=0;
    for (int i=1;i<=n;i++) ans=max(ans,d[i]);
    cout<<ans;
    getchar(); getchar();
    return 0;
}