#include <bits/stdc++.h>

using namespace std; 

struct Dinic {
    const static int maxn = 200 + 10;
    struct Edge {
        int from, to;
        int cap, flow;
    };
    int n, m, s, t;
    vector <Edge> edges;
    vector <int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    
    void AddEdge(int from, int to, int cap) {
        edges.push_back((Edge){from, to, cap, 0});
        edges.push_back((Edge){to, from, 0, 0});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool Bfs() {
        memset(vis, 0, sizeof(vis));
        memset(d, -1, sizeof(d));
        queue <int> Q;  Q.push(s), d[s] = 0, vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front(); Q.pop();
            for (int i = 0; i < (int)G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (!vis[e.to] && e.cap > e.flow) {
                    vis[e.to] = 1;
                    d[e.to] = d[x] + 1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }
    int Dfs(int x, int a) {
        if (x == t || a == 0)   return a;
        int flow = 0, f;
        for (int i = 0; i < (int)G[x].size(); i++) {
            Edge& e = edges[G[x][i]];
            if (d[x] + 1 == d[e.to] && (f = Dfs(e.to, min(a, e.cap - e.flow))) > 0) {
                e.flow += f;
                edges[G[x][i] ^ 1].flow -= f;
                flow += f;
                a -= f;
                if (a == 0) break;
            }
        }
        if (!flow)  d[x] = -1;
        return flow;
    }
    int Maxflow(int s, int t) {
        this->s = s;    this->t = t;
        int flow = 0;
        while (Bfs()) {
            flow += Dfs(s, INT_MAX);
        }
        return flow;
    }
    void Bfs_ans(int s, int t, vector<int>&ans1, vector<int>&ans2) {
        memset(vis, 0, sizeof(vis));
        queue <int> Q;  Q.push(s), d[s] = 0, vis[s] = 1;
        while (!Q.empty()) {
            int x = Q.front();  Q.pop();
            for (int i = 0; i < (int)G[x].size(); i++) {
                Edge& e = edges[G[x][i]];
                if (x == s && e.flow)   ans1.push_back(e.to);
                if (e.to == t && e.flow)    ans2.push_back(x);
                if (!vis[e.to]) {
                    vis[e.to] = 1;
                    if (e.to != t) {
                        Q.push(e.to);
                    }
                }
            }
        }
    }
}dinic;

int main() {
    int T;  scanf("%d", &T);
    while (T--) {
        int n;  scanf("%d", &n);
        unordered_map <long long, vector<int>> ump[2];
        int S = n + 1, T = n + 2;
        int tot = n + 2;
        for (int i = 1; i <= n; i++) {
            int x, y;   scanf("%d %d", &x, &y);
            ump[0][x + y].push_back(i);
            ump[1][x - y].push_back(i);
            dinic.AddEdge(S, i, 1);
        }
        for (int i = 0; i < 2; i++) {
            for (auto it : ump[i]) {
                ++tot;
                dinic.AddEdge(tot, T, 100000);
                for (auto pos : it.second) {
                    dinic.AddEdge(pos, tot, 1);
                }
            }
        }
        dinic.Maxflow(S, T);
        printf("%d\n", dinic.)
        dinic.dinic(S, T);
        printf("%d %d\n", dinic.minCost, dinic.maxFlow);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}