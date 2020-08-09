#include <bits/stdc++.h>

using namespace std;

const int N = 200000 + 10;
int n, t;

int head[N], to[N << 1], nxt[N << 1], tot;
void AddEdge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int fa[N][20], dps[N], lg2[N];
vector <int> leaf;
void dfs1(int u, int fath, int tdps) {
    fa[u][0] = fath;
    dps[u] = tdps;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            dfs1(v, u, tdps + 1);
        }
    }
}

void dfs2(int u, int fath, int tdps, bool flag2) {
    if (u == n) flag2 = false;
    fa[u][0] = fath;
    dps[u] = tdps;
    for (int i = 1; i < 20; i++)    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    bool flag = true;
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            dfs2(v, u, tdps + 1, flag2);
            flag = false;
        }
    }
    if (flag && flag2)   leaf.push_back(u);
}
int lca(int u, int v) {
    while (dps[u] != dps[v]) {
        if (dps[u] < dps[v])    swap(u, v);
        u = fa[u][lg2[dps[u] - dps[v]]];
    }
    if (u == v) return u;
    for (int i = 19; i >= 0; i--) {
        if (fa[u][i] != fa[v][i]) {
            u = fa[u][i];
            v = fa[v][i];
        }
    }
    return fa[u][0];
}

int fak(int u, int k) {
    for (int i = 0; i < 20 && k; i++) {
        if (k & (1 << i)) {
            u = fa[u][i];
            k ^= (1 << i);
        }
    }
    return u;
}

int calc(int a, int b) {
    return a <= b ? a : (1.0 * ((a - b) / 2)) + b;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("K.in", "r", stdin);
    freopen("K.out", "w", stdout);
    clock_t _s = clock();
#endif
    for (int i = 1; i < N; i++) lg2[i] = log2(i);
    scanf("%d %d", &n, &t);
    for (int i = 1; i < n; i++) {
        int u, v;   scanf("%d %d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs1(n, 0, 1);
    int u = 1;
    for (int i = 0; i < t && u != n; u = fa[u][0], i++);
    int ans = ceil((1.0 * dps[u] - dps[n]) / 2);
    dfs2(u, 0, 1, 1);
    for (auto v : leaf) {
        int x = lca(v, n);
        if (x == u) {
            int a = dps[n] - dps[u];
            int b = dps[v] - dps[u];
            ans = max(ans, calc(a, b));
        }
        else {
            int o = fak(n, dps[x] - dps[u]);
            if (dps[o] <= dps[x])   continue;
            int a = dps[o] - dps[x];
            int b = dps[v] - dps[x];
            ans = max(ans, calc(a, b));
        }
    }
    printf("%d\n", ans);
#ifndef ONLINE_JUDGE
    clock_t _t = clock();
    printf("%.6lf s\n", 1.0 *(_t - _s) / CLOCKS_PER_SEC);
    system("pause");
#endif
    return 0;
}