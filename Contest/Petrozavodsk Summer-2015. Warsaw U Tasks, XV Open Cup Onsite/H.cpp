#include <bits/stdc++.h>

using namespace std; 

const int N = 5000 + 10;
int c[N], p[N], _k[N], lg2[N];

int head[N], to[N << 1], nxt[N << 1], tot;
void AddEdge(int u, int v) {
    to[++tot] = v;
    nxt[tot] = head[u];
    head[u] = tot;
}

int fa[N][20], dps[N];
void dfs(int u, int fath, int tdps) {
    dps[u] = tdps;
    fa[u][0] = fath;
    for (int i = 1; i < 20; i++)    fa[u][i] = fa[fa[u][i - 1]][i - 1];
    for (int i = head[u]; i; i = nxt[i]) {
        int v = to[i];
        if (v != fath) {
            dfs(v, u, tdps + 1);
        }
    }
}

int lca(int u, int v) {
    while (dps[u] != dps[v]) {
        if (dps[u] < dps[v])    swap(u, v);
        int k = lg2[dps[u] - dps[v]];
        u = fa[u][k];
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
    for (int i = 0; i < 20; i++) {
        if (k & (1 << i)) {
            u = fa[u][i];
        }
    }
    return u;
}

int main() {
    for (int i = 1; i < N; i++) lg2[i] = log2(i);
    int n;  scanf("%d", &n);
    for (int i = 1; i <= n; i++)    scanf("%d", c + i);
    for (int i = 1; i < n; i++) {
        int u, v;   scanf("%d %d", &u, &v);
        AddEdge(u, v);
        AddEdge(v, u);
    }
    dfs(1, 0, 1);
    for (int i = 1; i <= n; i++)    scanf("%d", p + i);
    for (int i = 1; i < n; i++)    scanf("%d", _k + i);
    for (int i = 1; i < n; i++) {
        int u = p[i], v = p[i + 1], uv = lca(u, v);
        int ans = 0;
        for (int now = u; dps[now] >= dps[uv]; now = fak(now, _k[i])) {
            ans += c[now];
        }
        int dps_uv2 = _k[i] - (dps[u] - dps[uv]) % _k[i] + dps[uv];
        // int a = dps[uv] + d, b = dps[v];
        if (dps[v] - dps_uv2 >= 0) {
            // if (dps[v] - dps_uv2 == 0)  ans -= c[v];
            for (int now = fak(v, (dps[v] - dps_uv2) % _k[i]); dps[now] >= dps_uv2; now = fak(now, _k[i])) {
                ans += c[now];
            }
        }
        printf("%d\n", ans);
    }
#ifndef ONLINE_JUDGE
    system("pause");
#endif
    return 0;
}