#include <bits/stdc++.h>

using namespace std;

const int N = 300 + 10;

struct Card {
    int w, b, c;
}cards[N];

char s[N];
int sum[N][3];

struct Dinic {
    const static int maxn = 100000 + 10;
    const static int INT_INF = 1061109567;
    const static long long LLONG_INF = 4557430888798830399;
    struct Edge {
        int from, to;
        int cap, flow, cost;
    };
    vector <Edge> edges;
    vector <int> G[maxn];
    bool ins[maxn];
    int d[maxn], a[maxn], pre[maxn];
    int maxFlow, minCost;
    void init(int n) {
        edges.clear();
        for (int i = 1; i <= n; i++)    G[i].clear();
        maxFlow = minCost = 0;
    }
    void AddEdge(int from, int to, int cap, int cost) {
        edges.push_back((Edge){from, to, cap, 0, cost});
        edges.push_back((Edge){to, from, 0, 0, -cost});
        int m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool BellManFord(int s, int t) {
        memset(d, 0x3f, sizeof(d)); d[s] = 0;
        memset(pre, -1, sizeof(pre));
        memset(ins, false, sizeof(ins));    ins[s] = true;
        queue <int> Q;  Q.push(s); a[s] = INT_INF;
        while (!Q.empty()) {
            int u = Q.front();  Q.pop();    ins[u] = false;
            for (int i = 0; i < (int)G[u].size(); i++) {
                Edge& e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) {
                    d[e.to] = d[u] + e.cost;
                    pre[e.to] = G[u][i];
                    a[e.to] = min(a[u], e.cap - e.flow);
                    if (!ins[e.to]) {
                        Q.push(e.to);
                        ins[e.to] = true;
                    }
                }
            }
        }
        if (d[t] == INT_INF) {
            return false;
        }
        maxFlow += a[t];
        minCost += d[t] * a[t];
        for (int i = t; i != s; i = edges[pre[i]].from) {
            edges[pre[i]].flow += a[t];
            edges[pre[i] ^ 1].flow -= a[t];
        }
        return true;
    }
    void MCMF(int s, int t) {
        while (BellManFord(s, t));
    }
}mcmf;

int main() {
    freopen("jackpot.in", "r", stdin);
    freopen("jackpot.out", "w", stdout);
    int m;
    while (~scanf("%d", &m) && m) {
        scanf("%s", s + 1);
        for (int i = 1; i <= m; i++) {
            sum[i][0] = sum[i - 1][0] + (s[i] == 'W');
            sum[i][1] = sum[i - 1][1] + (s[i] == 'B');
            sum[i][2] = sum[i - 1][2] + (s[i] == '*');
        }
        int n;  scanf("%d", &n);
        mcmf.init(n + m + 5);
        for (int i = 1; i <= n; i++)    scanf("%d %d %d", &cards[i].w, &cards[i].b, &cards[i].c);
        int S = n + m + 1, T = n + m + 2;
        for (int j = 1; j <= m; j++)    mcmf.AddEdge(S, j, 1, 0);
        for (int i = 1; i <= n; i++)    mcmf.AddEdge(m + i, T, cards[i].c, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                mcmf.AddEdge(j, m + i, 1, max(max(cards[i].w - sum[j - 1][0], 0) + max(cards[i].b - sum[j - 1][1], 0) - sum[j - 1][2], 0));
            }
        }
        mcmf.MCMF(S, T);
        // printf("%d\n", mcmf.maxFlow);
        printf("%d\n", mcmf.minCost);
    }
    system("pause");
    return 0;
}